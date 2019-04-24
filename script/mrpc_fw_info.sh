#!/bin/bash

echo new round > fwinfolog

for ((i=0;i<$1;i++))
do
	echo $i +++
	echo $i >> fwinfolog

	sudo ~/switchtec-user/switchtec fw-info /dev/switchtec0
	#sudo ~/switchtec-user/switchtec status /dev/switchtec0
	#sudo ~/switchtec-user/switchtec log-dump /dev/switchtec0 -t RAM
	
	#if [ $? -ne 0 ]; then
	#	echo info fail
	#	exit 1
	#else
	#	echo info ok
	#fi

	echo $i ---
	#sleep 1
done

exit 0
