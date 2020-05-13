set -e

g++ -I /path/to/Eigen/ ../../ELEC40006/Bin/TransientAnalysis.cpp ../../ELEC40006/Bin/Parser.cpp -o TransientAnalysis


./TransientAnalysis < ../../ELEC40006/Tests/Data_struct_input.txt 

