// Classes
#include "../../bin/circuit.hpp"

// Support functions
#include "../../bin/header.hpp"

int main()
{
    // f = 1000, amplitude of 5
    double f = 1000;
    double time = 0;
    double timestep = 0.001;
    double d;
    for (int i = 0; i < 1200; i++)
    {
        d = (double)(f*time);
        std::cout<<d<<" "<<(5.0*sin(2*M_PI*d))<<std::endl;
        time += timestep;
    }
    

}
