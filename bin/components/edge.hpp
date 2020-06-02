/*
# ===================================================================================
# About the code
# ===================================================================================
# This code forms the 'Analysis' module' # 
# ===================================================================================
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

    public: //-----------------------------------------------------------------------


        /* Get operations for base variables */
        char Get_ID(){return this->ID;} 
        std::string Get_Name(){return this->name;};
        int Get_p_N(){return this->p_N;};
        int Get_n_N(){return this->n_N;};


        /* Specific element operations */
        double virtual Get_g(){};
        void virtual Set_g_value(double delta){};


        /* Dynamic element operations */
        void virtual Set_next_I(double Prev_edge_V){};
        double virtual Get_prev_I(){};
        void virtual Set_prev_I(double Prev_edge_V){};
    

        /* Voltage and Current Source operations */
        int virtual Get_assigned_ID(){};
        void virtual Update_assigned_ID(int vcount){};
        double virtual Get_src_value(double time=0){};


        /* Output operations */
        void virtual print_edge()=0;
};

#endif