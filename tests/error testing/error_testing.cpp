// Classes
#include "../../bin/circuit.hpp"

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

    // Initalising the simulation parameters
    input.Init_simulation();

    // Output simulation parameters
    //input.Print_simul_parameters();
    //std::cout<<std::endl;

    // Output transient results
    input.Transient_solve();

    // Get ending time 
    auto stop = std::chrono::high_resolution_clock::now(); 

    // Get difference between start and end
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start); 
    std::cout << std::endl;
    std::cout << "Time taken for module to execute: " << duration.count() << " microseconds" << std::endl; 
    std::cout << std::endl;
}