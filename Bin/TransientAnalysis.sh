set -e

g++ -I /path/to/Eigen/ TransientAnalysis.cpp Parser.cpp -o zoology


./zoology < ../../ELEC40006/Tests/Data_struct_input.txt 

