set -e

g++ -I /path/to/Eigen/ TransientAnalysis.cpp ../../ELEC40006/Bin/Parser.cpp ../../ELEC40006/Bin/Analysis.cpp -o TransientAnalysis


./TransientAnalysis < ../../ELEC40006/Tests/Data_struct_input.txt 

