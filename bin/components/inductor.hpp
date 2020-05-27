/*
# ===============================================================
# About the code
# ===============================================================
# This code forms the 'Analysis' module' # 
# ===============================================================
*/

#ifndef inductor_hpp
#define inductor_hpp

#include "branch.hpp"

class inductor : public branch
{
    private: // -------------------------------------------------------------------

        double // Default 0
            l_val; // Inductor appears as a short circuit thus max conductance
        
    public: //-----------------------------------------------------------------------

        inductor(std::string name, int n_pos, int n_neg);

        ~inductor();

        char getID();

        int getNodeR();

        int getNodeL();

        double getconductance();

        int update(){return 0;};

        void print();
};

#endif