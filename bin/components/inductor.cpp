/*
# ===============================================================
# About the code
# ===============================================================
# This code forms the 'Analysis' module' # 
# ===============================================================
*/

#include "inductor.hpp"

inductor::inductor(std::string name, int n_pos, int n_neg)
{
    this->ID = 'l';
    this->n_pos = n_pos;
    this->n_neg = n_neg;
    this->l_val=INT_MAX;
    this->g = this->l_val;
};

inductor::~inductor() {delete this;};

char inductor::getID() {return this->ID;};

int inductor::getNodeR() {return this->n_neg;};

int inductor::getNodeL() {return this->n_pos;};

double inductor::getconductance() {return this->g;};

void inductor::print()
{
    std::cout<<" Component ID: "<<this->ID<<" Node 1: "<<this->n_pos<<" Node 2: "<<this->n_neg<<" Resistance value: " << this->l_val << std::endl;
};