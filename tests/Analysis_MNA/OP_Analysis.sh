set -e

g++ -I /path/to/Eigen/ OP_Analysis.cpp ../../../ELEC40006/bin/Parser.cpp ../../../ELEC40006/bin/Analysis.cpp  -o  OP_Analysis


./OP_Analysis < ../../../ELEC40006/tests/Analysis_MNA/OP_Analysis_input.txt 


