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
            C_value, 
            g_value,
            Next_edge_I,
            Prev_edge_I;
        
    public: //-----------------------------------------------------------------------


        /* Class operations */
        capacitor(std::string in_name,int in_p_N,int in_n_N,double in_c_value)
        {
            ID='c'; name=in_name;
            p_N=in_p_N; n_N=in_n_N;
            C_value=in_c_value;
            g_value=0;
            Prev_edge_I=0;
            Next_edge_I=0;
        };
        ~capacitor(){if(this!=NULL){delete this;}};


        /* Simulation-related functions */
        void Set_g_value(double delta){g_value=(C_value/delta);};
        double Get_g(){return g_value;};

        void Set_next_I(double Prev_edge_V) {Next_edge_I = Prev_edge_I - (g_value*Prev_edge_V);}

        void Set_prev_I(double Prev_edge_V){Prev_edge_I = g_value*Prev_edge_V;};
        double Get_prev_I(){return Prev_edge_I;};


        /* Output operations */
        void print_edge()
        {
            std::cout<<"ID: "<<ID<<" name: "<<name<< " P terminal: "<<p_N
            <<" N terminal: "<<n_N<<" Capacitance: "<<C_value<<std::endl;
        };
};

#endif