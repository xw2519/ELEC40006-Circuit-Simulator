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

        double  
            Prev_edge_V, // Previous voltage of component
            Prev_edge_I; // Previous current of component

    public: //-----------------------------------------------------------------------

        /* Get operations for base variables */
        char Get_ID(){return this->ID;} 
        std::string Get_Name(){return this->name;};
        int Get_p_N(){return this->p_N;};
        int Get_n_N(){return this->n_N;};

        /* Update operations */
        void Set_prev_edge_v(double voltage){this->Prev_edge_V=voltage;};
        void Set_prev_edge_i(double current){this->Prev_edge_I=current;};

        /* Specific element operations */
        double virtual Get_g(){};
        void virtual Set_g_value(double delta){};

        /* Dynamic element operations */
        double virtual Get_next_I(){};
        void virtual Set_next_I(double Prev_edge_V){};
        double virtual Get_prev_I(){};
        void virtual Set_prev_I(){};

        double virtual Get_next_V(){};
        void virtual Set_next_V(){};
        
        
        double virtual Get_integrat_value(){};
        void virtual Set_integrat_value(double delta_src){};
    
        /* Voltage and Current Source operations */
        int virtual Get_assigned_ID(){};
        void virtual Update_assigned_ID(int vcount){};
        double virtual Get_voltage(double time){};
        double virtual Get_current(){};

        /* Output operations */
        void virtual print_edge()=0; // Report variables of a specific edge
};

#endif