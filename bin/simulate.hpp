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

        ~simulate() {};

        void init_matrices();

        void update_parameters(std::string in_type, double start, double stop, double in_interval);

        void update_matrices();

        double find_voltage();

        double find_current();

        void print_param();
};

#endif