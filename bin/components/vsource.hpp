/*
# ===============================================================
# About the code
# ===============================================================
# This code forms the 'Analysis' module' # 
# ===============================================================
*/
#define _USE_MATH_DEFINES
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


        /* Class operations */
        vsource(std::string in_name,int in_p_N,int in_n_N,std::string in_type,double in_offset,double in_amp, double in_freq)
        {
            ID='v'; name=in_name;
            p_N=in_p_N; n_N=in_n_N;
            type = in_type;
            offset=in_offset; amp=in_amp;
            freq=in_freq;
        };

        ~vsource(){delete this;};


        /* Voltage Source operations */
        int Get_assigned_ID() {return assigned_ID;};
        void Update_assigned_ID(int vcount) {assigned_ID=vcount;};
        double Get_src_value(double time=0)
        {
            if (type=="DC") {return offset;}
            else if (type=="SINE") 
            {  
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