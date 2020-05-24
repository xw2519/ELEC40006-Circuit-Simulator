/*
# ===============================================================
# About the code
# ===============================================================
# This code forms the 'Analysis' module' # 
# ===============================================================
*/

#ifndef isource_hpp
#define isource_hpp

#include "branch.hpp"

class isource : public branch
{
    private: // -------------------------------------------------------------------

        
    public: //-----------------------------------------------------------------------

        isource(std::string name, int n_pos, int n_neg, double i_value);

        ~isource();

        char getID();
        
        int getNodeR();

        int getNodeL();

        double getcurrent();

        int Update(){return 0;};

        void print();
};

#endif