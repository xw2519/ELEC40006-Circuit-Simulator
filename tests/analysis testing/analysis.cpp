// Classes
#include "../../bin/circuit.hpp"
#include "../../bin/analysis.hpp"

// Support functions
#include "../../bin/header.hpp"

int main()
{
    // Get starting time 
    auto start = std::chrono::high_resolution_clock::now(); 

    // Initialising the input_circuit of type 'circuit' and call 'parse' function
    circuit input_circuit;
    input_circuit.parse(std::cin);

    // Create analysis class variable 
    analysis equation;
    equation.makeDenseMatrix(input_circuit);

    // Solve the circuit
    equation.solve();
    equation.print();

    // Get ending time 
    auto stop = std::chrono::high_resolution_clock::now(); 

    // Get difference between start and end
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start); 
    std::cout << std::endl;
    std::cout << "Time taken for module to execute: " << duration.count() << " microseconds" << std::endl; 
}
