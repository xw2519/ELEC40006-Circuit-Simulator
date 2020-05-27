#include "vsource.hpp"

vsource::~vsource()
{
    delete this;
};

void vsource::update(std::string name, int n_pos, int n_neg, std::string type, double v_value, double amp, double freq)
{
    this->ID = 'v';
    this->name = name;
    this->n_pos = n_pos;
    this->n_neg = n_neg;
    this->vsrc_type = type;
    this->branch_val = v_value;
    this->amp = amp;
    this->freq = freq;
};

void vsource::source_resolver(std::vector<std::string> store)
{
    // ID component 'v' has already been removed
    // Deterimine if 'SINE' is mentioned in input
    if (store[3] == "SINE" || store[3] == "sine")
    {
        /* Debugging purposes 
        std::cout << "Sine detected." << std::endl */
        // Extract SINE parameters
        this->update(store[0], GetNode(store[1]), GetNode(store[2]), "SINE", converter(store[4]), converter(store[5]), converter(store[6]));
    }
    else if (store.size() == 4)
    {
        /* Debugging purposes 
        std::cout << "DC detected." << std::endl */
        // Treat as DC source
        this->update(store[0], GetNode(store[1]), GetNode(store[2]), "DC", converter(store[3]), 0, 0);
    }
    else{std::cerr << "Unsupported voltage source type." << std::endl; }
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
    std::cout<<" Component ID: "<<this->ID<<" Node 1: "<<this->n_pos<<" Node 2: "<<this->n_neg<<" Source Type: "<<this->vsrc_type<<" Steady state value: "<<this->branch_val<<" Amplitude: "<<this->amp<<" Frequency: "<<this->freq<<std::endl;
};