/*
# ===============================================================
# About the code
# ===============================================================
# This code forms the 'Analysis' module' # 
# ===============================================================
*/

#ifndef resistor_hpp
#define resistor_hpp

#include "edge.hpp"

class resistor : public edge
{
    private: // -------------------------------------------------------------------

        double
            R_value, // Value of resistance
            g_value; // Value of conductance
        
    public: //-----------------------------------------------------------------------


        /* Class operations */
        resistor(std::string in_name,int in_p_N,int in_n_N,double in_r_value)
        {
            ID='r'; name=in_name;
            p_N=in_p_N; n_N=in_n_N;
            R_value=in_r_value;
            g_value=1/R_value;
        };
        ~resistor(){delete this;};


        /* Simulation-related functions */
        double Get_g(){return this->g_value;};


        /* Output operations */
        void print_edge()
        {
            std::cout<<"ID: "<<ID<<" name: "<<name<< " P terminal: "<<p_N
            <<" N terminal: "<<n_N<<" Resistance: "<<R_value<<" Conductance: "<<g_value<<std::endl;
        };
};

#endif
