/*
# ===============================================================
# About the code
# ===============================================================
# This code forms the 'Analysis' module' # 
# ===============================================================
*/

#include "capacitor.hpp"

capacitor::capacitor(std::string name, int n_pos, int n_neg)
{
    this->ID = 'c';
    this->n_pos = n_pos;
    this->n_neg = n_neg;
    this->c_val=0;
    this->g = this->c_val;
};

capacitor::~capacitor() {delete this;};

char capacitor::getID() {return this->ID;};

int capacitor::getNodeR() {return this->n_neg;};

int capacitor::getNodeL() {return this->n_pos;};

double capacitor::getconductance() {return this->g;};

void capacitor::print()
{
    std::cout<<" Component ID: "<<this->ID<<" Node 1: "<<this->n_pos<<" Node 2: "<<this->n_neg<<" Resistance value: " << this->c_val << std::endl;
};