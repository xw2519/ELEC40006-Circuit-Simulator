/*
# ===============================================================
# About the code
# ===============================================================
# This code forms the 'Analysis' module' # 
# ===============================================================
*/

#ifndef edge_hpp
#define edge_hpp

#include "../../bin/header.hpp"

class edge
{
    protected: // -------------------------------------------------------------------

        char ID; // ID of component e.g. 'r' and ''l'

        std::string name; // Description of component

        int 
            p_N, // Positive terminal of component
            n_N; // Negative terminal of component

        double  
            edge_v, // Edge voltage of component
            edge_i; // Edge current of component

    public: //-----------------------------------------------------------------------

        /* Get operations */
        char Get_ID(){return this->ID;} 
        std::string Get_Name(){return this->name;};
        int Get_p_N(){return this->p_N;};
        int Get_n_N(){return this->n_N;};

        /* Update operations */
        void update_edge_v(double voltage){this->edge_v=voltage;};
        void update_edge_i(double current){this->edge_i=current;};

        /* Output operations */
        void virtual print_edge()=0; // Report variables of a specific edge

        /* Specific element operations */
        double virtual Get_g(){};
        double virtual Get_voltage(){};
        double virtual Get_current(){};
};

#endif