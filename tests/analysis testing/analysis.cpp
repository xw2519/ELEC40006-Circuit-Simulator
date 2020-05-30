// Classes
#include "../../bin/circuit.hpp"
#include "../../bin/simulate.hpp"

// Support functions
#include "../../bin/header.hpp"

int main()
{
    // Get starting time 
    auto start = std::chrono::high_resolution_clock::now(); 

    // Initialising the input_circuit of type 'circuit' contains the parser component
    circuit input(std::cin);

    // Initialising the 'Node' vector
    input.Init_nodes();

    // Output content of the circuit
    input.Print_Edges();

    // Initialising the 'Simulate" class
    input.Init_simulation();

    // Solve 
    input.Simul_solve();
    
    // Output simulation result
    input.Print_simul_results();

    // Get ending time 
    auto stop = std::chrono::high_resolution_clock::now(); 

    // Get difference between start and end
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start); 
    std::cout << std::endl;
    std::cout << "Time taken for module to execute: " << duration.count() << " microseconds" << std::endl; 
}
