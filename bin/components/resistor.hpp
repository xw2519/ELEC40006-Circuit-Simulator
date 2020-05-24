/*
# ===============================================================
# About the code
# ===============================================================
# This code forms the 'Analysis' module' # 
# ===============================================================
*/

#ifndef resistor_hpp
#define resistor_hpp

#include "branch.hpp"

class resistor : public branch
{
    private: // -------------------------------------------------------------------

        double // Default 0
            r_val=0; // Resistance of resistor
        
    public: //-----------------------------------------------------------------------

        resistor(std::string name, int n_pos, int n_neg, double r_value);

        ~resistor();

        char getID();

        int getNodeR();

        int getNodeL();

        double getconductance();

        int update(){return 0;};

        void print();
};

#endif
