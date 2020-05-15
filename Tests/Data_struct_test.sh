set -e


g++ Data_struct.cpp ../../ELEC40006/Bin/Parser.cpp -o Data_struct
./Data_struct < Data_struct_input.txt
