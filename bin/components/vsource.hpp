/*
# ===============================================================
# About the code
# ===============================================================
# This code forms the 'Analysis' module' # 
# ===============================================================
*/

#ifndef vsource_hpp
#define vsource_hpp

#include "branch.hpp"

class vsource : public branch
{
    private: // -------------------------------------------------------------------

        
    public: //-----------------------------------------------------------------------

        vsource(std::string name, int n_pos, int n_neg, double v_value);

        ~vsource();

        char getID();
        
        int getNodeR();

        int getNodeL();

        double getvoltage();

        int Update(){return 0;};

        void print();
};

#endif