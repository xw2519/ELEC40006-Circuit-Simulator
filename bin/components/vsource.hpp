/*
# ===============================================================
# About the code
# ===============================================================
# This code forms the 'Analysis' module' # 
# ===============================================================
*/

#ifndef vsource_hpp
#define vsource_hpp

#include "edge.hpp"

class vsource : public edge
{
    private: // -------------------------------------------------------------------

        std::string type;

        int assigned_ID;

        double  
            offset, // DC offset
            amp, // Amplitude of sine wave
            freq, // Frequency of the sine wave

            voltage; // Return voltage calculated for instance in time
        
    public: //-----------------------------------------------------------------------

        vsource(std::string in_name,int in_p_N,int in_n_N,std::string in_type,double in_offset,double in_amp, double in_freq)
        {
            ID='v'; name=in_name;
            p_N=in_p_N; n_N=in_n_N;
            type = in_type;
            offset=in_offset; amp=in_amp;
            freq=in_freq;
            Prev_edge_V=0; Prev_edge_I=0;
        };

        ~vsource(){delete this;};

        /* Voltage and Current Source operations */

        int Get_assigned_ID() {return assigned_ID;};

        void Update_assigned_ID(int vcount) {assigned_ID=vcount;};

        double Get_voltage(double time)
        {
            if (type=="DC") {return offset;}
            else if (type=="SINE") 
            {  
                std::cerr<<time<<std::endl;
                voltage = (amp)*sin((2*M_PI*freq*time)) + offset;
                return voltage;
            }
        };

        /* Output operations */

        void print_edge()
        {
            std::cout<<"ID: "<<ID<<" name: "<<name<< " P terminal: "<<p_N
            <<" N terminal: "<<n_N<<" Type: "<<type<<" Offset: "<<offset
            <<" Amplitude: "<<amp<<" Frequency: "<<freq<<std::endl;
        };
};

#endif