#!/bin/bash

for ((i=0;i<$1;i++))
do
	echo +++ $i +++
	echo "cat /sys/class/switchtec/switchtec0/sum_lo" : 
	cat /sys/class/switchtec/switchtec0/sum_lo >> cat_log
	cat /sys/class/switchtec/switchtec0/sum_lo
	echo --- $i ---
	sleep 10
done

exit 0
