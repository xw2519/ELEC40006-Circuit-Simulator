/*
# ===================================================================================
# About the code
# ===================================================================================
# Integration is using 'Backward Euler' Integration
# ===================================================================================
*/

#ifndef capacitor_hpp
#define capacitor_hpp

#include "edge.hpp"

class capacitor : public edge
{
    private: // ---------------------------------------------------------------------

        double
            C_value, // Value of capacitance
            integrat_value, // Voltage value in this case
            g_value,
            instant_current;
        
    public: //-----------------------------------------------------------------------

        /* Class operations */
        capacitor(std::string in_name,int in_p_N,int in_n_N,double in_c_value)
        {
            ID='c'; name=in_name;
            p_N=in_p_N; n_N=in_n_N;
            C_value=in_c_value;
            prev_edge_v=0; prev_edge_i=0;
            g_value=0;
            instant_current=0;
            integrat_value=0;
        };

        ~capacitor(){delete this;};

        /* Get operations for base variables */
        double Get_C(){return this->C_value;};

        /* Simulation-related functions */
        void Set_g_value(double delta){g_value=(delta/C_value);};
        double Get_g(){return g_value;};
        void Set_instant_current(double nodeV){instant_current=g_value*nodeV;};
        double Get_instant_current(){return instant_current;};
        void Set_integrat_value(double delta_src){integrat_value=delta_src+integrat_value;};
        double Get_integrat_value(){return integrat_value;};

        /* Output operations */
        void print_edge()
        {
            std::cout<<"ID: "<<ID<<" name: "<<name<< " P terminal: "<<p_N
            <<" N terminal: "<<n_N<<" Edge voltage: "<<prev_edge_v<<" Edge current: "
            <<prev_edge_i<<" Capacitance: "<<C_value<<std::endl;
        };
};

#endif