import os, glob, re

worksapce_path = 'D:\\saratoga_fw\\ESD\\PSX\\main'
mrpc_register_handler_str = 'mrpc_register_handler'

list_file_filter_type = ['c']
list_dir_file_c_file = []
list_mrpc_handler = []
list_mrpc_handler_polish = []
list_each_mrpc_handler = []
list_single_mrpc_file = []
list_single_mrpc_handler = []
list_single_mrpc_body = []

def scandirs(path):
    for file in glob.glob(os.path.join(path, '*')):
        if os.path.isdir(file):
            scandirs(file)
        elif file.split('.')[-1].lower() in list_file_filter_type:
            list_dir_file_c_file.append(file)

def search_string_in_file(key_string, filename, target_list, append_file_path):
    with open(filename, "r") as f_read:
        lines = f_read.readlines()
        for line in lines:
            if re.search(key_string, line):
                line = line.strip('\n') # remove the null line
                if target_list is not None:
                    if append_file_path is not None:
                        #target_list.append(file + ',' + line)
                        target_list.append(file)
                        target_list.append(line)
                    else:
                        target_list.append(line)

def search_function_body_in_file(function_name, filename, target_list, append_file_path):
    start_fun_body = 0
    file_all_content = []
    with open(filename, "r") as f_read:
        lines = f_read.readlines()
        for line in lines:
            line = line.strip('\n') # remove the null line
            if line is not None:
                file_all_content.append(line)

        print_list_element(file_all_content)

        for line in file_all_content:
            #print line
            #print len(line)

            if line is None:
                print "None line"
                continue

            elif len(line) == 0: # why check by None is fail, should be len ???
                continue
            
            #if re.search(function_name, line): # why not work ???
            elif line == function_name:           # why it work ???
                target_list.append(line)
                start_fun_body = 1
                continue
            
            elif start_fun_body == 1 and line[0] == '}':
                target_list.append(line)
                return
            
            elif start_fun_body == 1:
                target_list.append(line)
                continue
            


def polish_mrpc_handler_name(str):
    ## example:
    ## 1. PUBLIC PMCFW_ERROR mrpc_register_handler(UINT16 cmd_idx, mrpc_hdlr_fn fn_ptr)
    ## 2. mrpc_register_handler(MRPC_ECHO, &mrpc_echo_cmd); // with &
    ## 3. mrpc_register_handler( MRPC_SYNEP, synep_mrpc_func); // w/o &
    ## 4. mrpc_register_handler( MRPC_STACKBIF, pg_set_bif_mrpc ); // whitespace after ( and before ), w/o &
    ## 5. mrpc_register_handler( MRPC_EVENTS_QUERY, &mrpc_events_query ); // same as 4, with &
    
    ## check by & (not applicable)
    ## ugly firmware code, some with &, some w/o &, fuck
    ## check by & is not applicable
    #str = str.split('&')[-1] #split the & before mrpc handler name
    #str = str.split(')')[0] #split the ) after mrpc handler name

    #if str is None:
    #    print "@@@ " + "null" ## make sure none not into polish list
    #else:
        #print "not None" + str
        str = str.replace(' ', '') ## remove the whitesapce
        if str.find(';') == -1: ## remove example case 1
            print "+++++++++++++++++++++++++++++"
            print " @@@ " + str
            print "============================="
        else:
            str = str.split(',')[-1] ## keep the str after ,
            str = str.split(')')[0] ## keep the str before )
            str = str.replace('&', '') ## remove &, if any
            #print str
            return str

def print_list_element(list):
    print "+++++++++++++++++++++++++++++"
    for element in list:
        print element
    print "============================="

def print_list_len(list):
    print "+++++++++++++++++++++++++++++"
    print len(list)
    print "============================="
    
'''
## STEP 1
## for list_dir_file_c_file
scandirs(worksapce_path)
#print_list_element(list_dir_file_c_file)
print_list_len(list_dir_file_c_file)

## STEP 2
## for list_mrpc_handler
for file in list_dir_file_c_file:
    search_string_in_file(mrpc_register_handler_str, file, list_mrpc_handler, None)
        
#print_list_element(list_mrpc_handler)
print_list_len(list_mrpc_handler)

## STEP 3
## polish the mrpc handler list
for element in list_mrpc_handler:
    str = polish_mrpc_handler_name(element)
    if str is not None:
        list_mrpc_handler_polish.append(str)
#print_list_element(list_mrpc_handler_polish)
print_list_len(list_mrpc_handler_polish)

## STEP 4
## for each mrpc handler
## Time consuming, can FW guys supplied c file name, with related to mrpc?
for str in list_mrpc_handler_polish:
    for file in list_dir_file_c_file:
        search_string_in_file("PMCFW_ERROR " + str, file, list_each_mrpc_handler, "append_file")
        #print "Running time consuming operation: (handler):" + str + "(file):" + file
    print "Running time consuming op: " + str
    
print_list_element(list_each_mrpc_handler)
print_list_len(list_each_mrpc_handler)

## STEP 5
## needed this step?
for i in range(0, len(list_each_mrpc_handler), 2):
    list_single_mrpc_file.append(list_each_mrpc_handler[i])

for i in range(1, len(list_each_mrpc_handler), 2):
    list_single_mrpc_handler.append(list_each_mrpc_handler[i])

print_list_element(list_single_mrpc_file)
print_list_len(list_single_mrpc_file)
print_list_element(list_single_mrpc_handler)
print_list_len(list_single_mrpc_handler)

## STEP 6
##
file = list_single_mrpc_file[0]
handler = list_single_mrpc_handler[0]
print file
print handler
'''

file = "D:\\saratoga_fw\\ESD\\PSX\\main\\gas\\src\\mrpc_cmd_internal.x"
handler = "PRIVATE PMCFW_ERROR mrpc_twi_cmd(UINT8 src_id, UINT32 *input, UINT32 *OutOffset, UINT32 *OutCount)"
print file
print handler
search_function_body_in_file(handler, file, list_single_mrpc_body, None)
print_list_element(list_single_mrpc_body)
print_list_len(list_single_mrpc_body)

