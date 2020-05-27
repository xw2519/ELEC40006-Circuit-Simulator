/*
# ===============================================================
# About the code
# ===============================================================
# This code forms the 'Analysis' module' # 
# ===============================================================
*/

#ifndef capacitor_hpp
#define capacitor_hpp

#include "branch.hpp"

class capacitor : public branch
{
    private: // -------------------------------------------------------------------

        double // Default 0
            c_val; // capacitor appears as a open circuit thus no conductance
        
    public: //-----------------------------------------------------------------------

        capacitor(std::string name, int n_pos, int n_neg);

        ~capacitor();

        char getID();

        int getNodeR();

        int getNodeL();

        double getconductance();

        int update(){return 0;};

        void print();
};

#endif