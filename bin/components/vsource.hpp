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

        std::string vsrc_type;

        // Sine wave
        double  
            offset, // DC offset
            amp, // Amplitude of sine wave
            freq; // Frequency of the sine wave
        
    public: //-----------------------------------------------------------------------

        ~vsource();

        void update(std::string name, int n_pos, int n_neg, std::string type, double v_value, double amp, double freq);

        void source_resolver(std::vector<std::string> store);

        char getID();
        
        int getNodeR();

        int getNodeL();

        double getvoltage();

        int Update(){return 0;};

        void print();
};

#endif