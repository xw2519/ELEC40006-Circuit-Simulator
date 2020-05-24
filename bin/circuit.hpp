#ifndef circuit_hpp
#define circuit_hpp

// Classes 
#include "../bin/components/branch.hpp"
// Support functions
#include "header.hpp"

class circuit
{
    private: // -----------------------------------------------------------------------

        std::vector<branch*> branch_store; // Stores the circuit inputted

        int 
            N, // The number of nodes in the circuit
            M, // The number of independent voltage sources in the circuit
            vcount;
        
        Eigen::MatrixXf A;
        Eigen::VectorXf b;
        Eigen::VectorXf x;
        
    protected: // ---------------------------------------------------------------------
    
    public: //-------------------------------------------------------------------------

        // Virtual destructor to be redefined by subclasses
        virtual ~circuit();

        /* Parse a netlist */
        // Handles the input of a netlist
        void parse(std::istream& cin);

        /* Matrix functions */
        // Creates and populates the matrices in the format Ax = b
        void makeDenseMatrix();

        // Stamp new values into existing matrix
        void update();

        // Solve for matrix x
        void solve();

        /* Output functions */
        // Outputs the content of the circuit vector
        void print_data_structure();

        // Output the content of matrix 'x'
        void print_solution();
};

#endif