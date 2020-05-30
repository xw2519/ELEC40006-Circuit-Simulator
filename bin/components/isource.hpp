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

        isource(std::string in_name,int in_p_N,int in_n_N,double in_current)
        {
            ID='i'; name=in_name;
            p_N=in_p_N; n_N=in_n_N;
            current=in_current;
            prev_edge_v=0; prev_edge_i=0;
        };

        ~isource(){delete this;};

        double Get_current(){return current;};

        void print_edge()
        {
            std::cout<<"ID: "<<ID<<" name: "<<name<< " P terminal: "<<p_N
            <<" N terminal: "<<n_N<<" Edge voltage: "<<prev_edge_v<<" Edge current: "
            <<prev_edge_i<<" Current: "<<current<<std::endl;
        };
};

#endif