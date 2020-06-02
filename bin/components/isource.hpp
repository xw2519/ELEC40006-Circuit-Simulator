/*
# ===============================================================
# About the code
# ===============================================================
# This code forms the 'Analysis' module' # 
# ===============================================================
*/

#ifndef isource_hpp
#define isource_hpp

#include "edge.hpp"

class isource : public edge
{
    private: // -------------------------------------------------------------------

        double  
            current;

    public: //-----------------------------------------------------------------------


        /* Class operations */
        isource(std::string in_name,int in_p_N,int in_n_N,double in_current)
        {
            ID='i'; name=in_name;
            p_N=in_p_N; n_N=in_n_N;
            current=in_current;
        };
        ~isource(){delete this;};


        /* Simulation-related functions */
        double Get_src_value(double time=0){return current;};


        /* Output operations */
        void print_edge()
        {
            std::cout<<"ID: "<<ID<<" name: "<<name<< " P terminal: "<<p_N
            <<" N terminal: "<<n_N<<" Current: "<<current<<std::endl;
        };
};

#endif