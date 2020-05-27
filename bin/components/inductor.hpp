/*
# ===============================================================
# About the code
# ===============================================================
# This code forms the 'Analysis' module' # 
# ===============================================================
*/

#ifndef inductor_hpp
#define inductor_hpp

#include "edge.hpp"

class inductor : public edge
{
    private: // -------------------------------------------------------------------

        double 
            L_value, // Inductor appears as a short circuit thus max conductance
            integrated;
        
    public: //-----------------------------------------------------------------------

        inductor(std::string in_name,int in_p_N,int in_n_N,double in_l_value)
        {
            ID='l'; name=in_name;
            p_N=in_p_N; n_N=in_n_N;
            L_value=in_l_value;
            edge_v=0; edge_i=0;
        };

        ~inductor(){delete this;};

        double Get_integrated(){}; // To be implemented

        double Get_L(){return this->L_value;};

        void print_edge()
        {
            std::cout<<"ID: "<<ID<<" name: "<<name<< " P terminal: "<<p_N
            <<" N terminal: "<<n_N<<" Edge voltage: "<<edge_v<<" Edge current: "
            <<edge_i<<" Inductor: "<<L_value<<" Integrated value: "<<integrated<<std::endl;
        };
};

#endif