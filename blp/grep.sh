#!/bin/sh

for file in *
do
	if grep -l maximum $file
	then
		echo $file
	fi
done

exit 0
