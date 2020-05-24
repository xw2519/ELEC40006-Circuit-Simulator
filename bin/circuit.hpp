#ifndef circuit_hpp
#define circuit_hpp

// Classes 
#include "../bin/components/branch.hpp"
// Support functions
#include "header.hpp"

class circuit
{
    private: // -----------------------------------------------------------------------
        
    protected: // ---------------------------------------------------------------------
    
        std::vector<branch*> branch_store; // Stores the circuit inputted

        int 
            N=0, // The number of nodes in the circuit
            M=0; // The number of independent voltage sources in the circuit
    
    public: //-------------------------------------------------------------------------

        // Handles the input of a netlist
        void parse(std::istream& cin);

        // Virtual destructor to be redefined by subclasses
        virtual ~circuit();

        std::vector<branch*> get_circuit();

        // Returns the number of nodes in the circuit
        int get_N();

        // Returns the number if independent voltage sources
        int get_M();

        // Outputs the content of the circuit vector
        void print_data_structure();
};

#endif