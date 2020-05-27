/*
# ===============================================================
# About the code
# ===============================================================
# This code forms the 'Analysis' module' # 
# ===============================================================
*/

#ifndef capacitor_hpp
#define capacitor_hpp

#include "edge.hpp"

class capacitor : public edge
{
    private: // -------------------------------------------------------------------

        double
            C_value, // Value of capacitance
            integrated; // Result of integration process
        
    public: //-----------------------------------------------------------------------

        capacitor(std::string in_name,int in_p_N,int in_n_N,double in_c_value)
        {
            ID='c'; name=in_name;
            p_N=in_p_N; n_N=in_n_N;
            C_value=in_c_value;
            edge_v=0; edge_i=0;
        };

        ~capacitor(){delete this;};

        double Get_integrated(){}; // To be implemented

        double Get_C(){return this->C_value;};

        void print_edge()
        {
            std::cout<<"ID: "<<ID<<" name: "<<name<< " P terminal: "<<p_N
            <<" N terminal: "<<n_N<<" Edge voltage: "<<edge_v<<" Edge current: "
            <<edge_i<<" Capacitance: "<<C_value<<" Integrated value: "<<integrated<<std::endl;
        };
};

#endif