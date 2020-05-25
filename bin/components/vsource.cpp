#include "vsource.hpp"

vsource::vsource(std::string name, int n_pos, int n_neg, std::string type, double v_value, double amp, double freq)
{
    this->ID = 'v';
    this->name = name;
    this->n_pos = n_pos;
    this->n_neg = n_neg;
    this->branch_val = v_value;
    this->vsrc_type = type;
    this->amp = amp;
    this->freq = freq;
};


vsource::~vsource()
{
    delete this;
};

char vsource::getID()
{
    return this->ID;
};

int vsource::getNodeR()
{
    return this->n_neg;
};

int vsource::getNodeL()
{
    return this->n_pos;
};

double vsource::getvoltage()
{
    return this->branch_val;
};

void vsource::print()
{
    std::cout<<" Component ID: "<<this->ID<<" Node 1: "<<this->n_pos<<" Node 2: "<<this->n_neg<<" Voltage value: "<<this->branch_val<<std::endl;
};