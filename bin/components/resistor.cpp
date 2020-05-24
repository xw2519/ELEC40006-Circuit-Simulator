/*
# ===============================================================
# About the code
# ===============================================================
# This code forms the 'Analysis' module' # 
# ===============================================================
*/

#include "resistor.hpp"

resistor::resistor(std::string name, int n_pos, int n_neg, double r_value)
{
    this->ID = 'r';
    this->n_pos = n_pos;
    this->n_neg = n_neg;
    this->r_val = r_value;
    this->g = 1/this->r_val;
};

resistor::~resistor()
{
    delete this;
};

char resistor::getID()
{
    return this->ID;
};

int resistor::getNodeR()
{
    return this->n_neg;
};

int resistor::getNodeL()
{
    return this->n_pos;
};

double resistor::getconductance()
{
    return this->g;
};

void resistor::print()
{
    std::cout<<" Component ID: "<<this->ID<<" Node 1: "<<this->n_pos<<" Node 2: "<<this->n_neg<<" Resistance value: " << this->r_val << std::endl;
};
