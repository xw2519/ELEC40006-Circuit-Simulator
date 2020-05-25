#ifndef circuit_hpp
#define circuit_hpp

// Classes 
#include "../bin/components/branch.hpp"
#include "../bin/components/resistor.hpp"
#include "../bin/components/vsource.hpp"
#include "../bin/components/isource.hpp"
// Support functions
#include "header.hpp"

class circuit
{
    private: // -----------------------------------------------------------------------

        std::vector<branch*> branch_store; // Stores the circuit inputted

        int 
            N, // The number of nodes in the circuit
            M, // The number of independent voltage sources in the circuit
            vcount; // Counter keeping track of number of independent voltage sources
        
        // Analysis function variables
        std::string func_name;
        double stop_time, timestep;
        
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

        /* Analysis function handler */
        // Scans and returns the parameters of the analysis function inputted
        void func_param(std::string& func_name, double& stop_time, double& timestep);

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
        void print_dc_sol();

        // Output solutions in .csv format
        void print_csv();
};

#endif