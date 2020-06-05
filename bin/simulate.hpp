/*
# =================================================================================================
# About the code
# =================================================================================================
# This code forms the 'Analysis' module' # 
# =================================================================================================
*/

#ifndef simulate_hpp
#define simulate_hpp

#include "header.hpp"
#include "node.hpp"
#include "../bin/components/edge.hpp"
#include "../bin/components/resistor.hpp"
#include "../bin/components/capacitor.hpp"
#include "../bin/components/inductor.hpp"
#include "../bin/components/vsource.hpp"
#include "../bin/components/isource.hpp"

class simulate
{
    private: // -----------------------------------------------------------------------------------
    
    /* Required transient parameters */

    std::string 
        type;

    double 
        start_time,
        stop_time,
        timestep;

    /* Simulation parameters */

    int 
        N_store,
        M_store;

    double
        current_time,
        intervals;

    std::vector<edge*>
        inductors,
        capacitors,
        vsources;

    Eigen::MatrixXd A;
    Eigen::VectorXd 
        x,
        b;
    
    public: // ------------------------------------------------------------------------------------

        /* Class operations */
        ~simulate() {};

        /* Simulation parameter operations */
        void update_parameters(std::string in_type, double start, double stop, double in_interval);

        /* Matrix operations */
        // Create matrices based on initial conditions
        void Init_matrices(int N, int M, std::vector<edge*>& Edges); 
        // Separate C and L into separate vector and set conductances 
        void Init_dynamic(std::vector<edge*>& Edges);
        // Updates matrices based on values of the voltage source
        void Update_source();
        // Updates matrices based on values of dynamic elements
        void Update_dynamic();
        // Update previous currents in the system for integration
        void Update_prev_values();
        // Solves the system of equations based on current values of matrices
        void Solve_matrices();

        /* Newton-Raphson approximation */
        // void Newton_Raphson();

        /* Transient simulation */
        void Transient(std::vector<edge*>& Edges);
        
        /* Output operations */
        void print_param();
        void print_source(std::vector<edge*>& Edges);
        void print_x();
        void print_CSV();
};

#endif