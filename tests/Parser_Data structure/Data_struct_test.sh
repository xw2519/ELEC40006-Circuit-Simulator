set -e


g++ Data_struct.cpp ../../../ELEC40006/bin/Parser.cpp -o Data_struct
./Data_struct < Data_struct_input.txt
