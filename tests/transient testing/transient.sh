g++ -g transient.cpp ../../bin/circuit.cpp ../../bin/simulate.cpp ../../bin/node.cpp ../../bin/str_handler.cpp -o transient_tester

./transient_tester < ../transient\ testing/test\ inputs/test_4.txt >output.csv

