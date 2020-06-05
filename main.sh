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
echo "Please enter the number of the netlist file you wish to input"
echo "***************************************************************"

read NUM
./main < ${ARRAY[$NUM - 1]} > output.csv
