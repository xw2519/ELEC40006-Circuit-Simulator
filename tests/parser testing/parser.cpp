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
    input.init_nodes();

    // Output the content of the 'Edges' vector using built in function
    input.Print_Edges();

    // Output the content of the 'Nodes' vector using built in function
    input.Print_Nodes();

    // Output critical variables 'N' and 'M'
    std::cout<<"N variable: "<<input.Get_N()<<std::endl;
    std::cout<<"M variable: "<<input.Get_M()<<std::endl;
    std::cout<<std::endl;

    // Output simulation parameters
    input.Print_simul_parameters();

    // Get ending time 
    auto stop = std::chrono::high_resolution_clock::now(); 

    // Get difference between start and end
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start); 
    std::cout << std::endl;
    std::cout << "Time taken for module to execute: " << duration.count() << " microseconds" << std::endl; 
    std::cout << std::endl;
}
