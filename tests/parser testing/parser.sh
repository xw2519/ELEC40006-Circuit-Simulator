g++ ../../bin/components/branch.cpp ../../bin/components/resistor.cpp ../../bin/components/vsource.cpp ../../bin/components/isource.cpp ../../bin/str_handler.cpp parser.cpp ../../bin/circuit.cpp ../../bin/vsrc_resolver.cpp -o parser

./parser < ../parser\ testing/test\ inputs/test_1.txt 

