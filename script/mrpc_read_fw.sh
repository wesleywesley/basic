#!/bin/bash

for ((i=0;i<"$1";i++))
do
	#sudo ~/switchtec-user/switchtec status /dev/switchtec0
	#sudo ~/switchtec-user/switchtec log-dump /dev/switchtec0 -t "$2" 
	sudo ~/switchtec-user/switchtec fw-read /dev/switchtec0 
	echo script '$?':"$?"
	if [ $? -ne 0 ]; then
		exit 1
	else
		exit 0
	fi
done

exit 0
