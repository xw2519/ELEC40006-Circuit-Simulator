set -e

g++ -I /path/to/Eigen/ OP_Analysis.cpp ../../../ELEC40006/bin/parser.cpp ../../../ELEC40006/bin/analysis.cpp  -o  OP_Analysis


./OP_Analysis < ../../../ELEC40006/tests/Analysis/OP_Analysis_input.txt 


