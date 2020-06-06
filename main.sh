#!/bin/bash
set -e 

clear
echo "***************************************************************"
echo "Detecting current directory for netlist files..."
echo "***************************************************************"
echo "List of netlist files detected in current directory" 
echo "***************************************************************"

ARRAY=($(ls -d *.net))

ARRAYLEN=${#ARRAY[@]}

for (( i=1; i<${ARRAYLEN}+1; i++ ));
do
	echo $i")" ${ARRAY[$i-1]}
done

echo "***************************************************************"
echo "Program Error Log"
echo "***************************************************************"

read NUM
./main < ${ARRAY[$NUM - 1]} > output.csv
