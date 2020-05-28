#include "simulate.hpp"

void simulate::init_matrices()
{

};

void simulate::update_parameters(std::string in_type, double start, double stop, double in_interval)
{
    this->type=in_type; this->start_time=start; 
    this->stop_time=stop; this->interval=in_interval;
};

void simulate::update_matrices()
{

};

double simulate::find_voltage()
{

};

double simulate::find_current()
{

};

void simulate::print_param()
{
    std::cout<<"Simulation type: "<<this->type<<" Start time: "<<this->start_time<<" Stop time: "
    <<this->stop_time<<" Interval: "<<this->interval<<std::endl;
};