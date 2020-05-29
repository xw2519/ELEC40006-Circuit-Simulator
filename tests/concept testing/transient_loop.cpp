#include <iostream>
#include <cassert>

using namespace std;

/*
# ===================================================================================
# About the code: This section tests the implementation of the transient loop. 
# ===================================================================================
# Testing Log: 
# ===================================================================================
# We have to consider the situation where the interval is a non-whole number.
# ===================================================================================
*/

int main()
{
    double stop_time, start_time, max_timestep, current_time, interval;
    
    start_time = 0.5;
    stop_time = 1;
    max_timestep = 0.0001;

    assert(stop_time>start_time); // Ensure stop time is later than start time
    current_time=0; 
    interval=(stop_time-start_time)/max_timestep; 

    for (int i = 0; i <= interval; i++) // Transient loop
    {
        cout<<i<<endl;
    }
}
