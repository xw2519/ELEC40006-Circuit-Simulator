
#ifndef branch_hpp
#define branch_hpp

// Support functions
#include "../../bin/header.hpp"

class branch
{
    protected: // -------------------------------------------------------------------

        std::string
            name; // Description of the element

        char 
            ID; // Type of element e.g. resistors and voltage sources

        int 
            n_pos,
            n_neg;
        
        double // Default 0
            pre_v=0, // Previous value of v
            pre_i=0, // Previous value of i
            g=0, // Conductance value
            branch_val=0; // Current or voltage value of branch
        

    public: //-----------------------------------------------------------------------
    
        virtual ~branch();
        
        virtual char getID(){};

        virtual int getNodeR(){};

        virtual int getNodeL(){};

        virtual double getconductance(){};

        virtual double getvoltage(){};

        virtual int update(){};

        virtual void print()=0;
};

#endif