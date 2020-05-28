/*
# ===================================================================================
# About the code
# ===================================================================================
# This code forms the 'Analysis' module' # 
# ===================================================================================
*/

#ifndef simulate_hpp
#define simulate_hpp

#include "header.hpp"
#include "circuit.hpp"

class simulate
{
    private: // ---------------------------------------------------------------------

        std::string type;

    double 
        start_time,
        stop_time,
        interval;

    Eigen::MatrixXd A;
    Eigen::VectorXd x;
    Eigen::VectorXd b;
    
    public: //-----------------------------------------------------------------------

        /* Class operations */
        ~simulate() {};

        /* Simulation parameter operations */
        void update_parameters(std::string in_type, double start, double stop, double in_interval);

        /* Matrix operations */
        void init_matrices(int N, int M, std::vector<node> Nodes); // Create conductance matrix
        void update_matrices();
        void solve_matrices();

        double find_voltage();

        double find_current();
        
        /* Output operations */
        void print_param();
        void print_x();
};

#endif