#include "isource.hpp"

isource::isource(std::string name, int n_pos, int n_neg, double i_value)
{
    this->ID = 'v';
    this->name = name;
    this->n_pos = n_pos;
    this->n_neg = n_neg;
    this->branch_val = i_value;
};


isource::~isource()
{
    delete this;
};

char isource::getID()
{
    return this->ID;
};

int isource::getNodeR()
{
    return this->n_neg;
};

int isource::getNodeL()
{
    return this->n_pos;
};

double isource::getcurrent()
{
    return this->branch_val;
};

void isource::print()
{
    std::cout<<" Component ID: "<<this->ID<<" Node 1: "<<this->n_pos<<" Node 2: "<<this->n_neg<<" Current value: "<<this->branch_val<<std::endl;
};