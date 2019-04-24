#!/bin/bash

echo new round > log

for ((i=0;i<$1;i++))
do
	echo $i +++
	echo $i >> log
	sudo ~/switchtec-user/switchtec fw-update /dev/switchtec0 ~/share/fw/pm74602_psx_010b0088/images/switchtec_psx.pmc -A -y
	if [ $? -ne 0 ];then
		echo $i fail
		exit 1
	else
		echo $i ok
	fi
	echo $i ---
done

exit 0
