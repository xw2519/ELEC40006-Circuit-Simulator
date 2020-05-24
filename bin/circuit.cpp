#include "circuit.hpp"

#include "../bin/components/branch.hpp"
#include "../bin/components/resistor.hpp"
#include "../bin/components/vsource.hpp"
#include "../bin/components/isource.hpp"

circuit::~circuit()
{
    
};

void circuit::parse(std::istream& cin)
{
    bool firstline = true;
    std::string line;
    std::vector<std::string> store;

    while (std::getline(std::cin, line))
    {
        // Check for beginning TITLE and skip
        if (firstline){firstline = false; continue;}
        // Check for .end
        if (line == ".end"){break;}
        // Check if this line is a comment, denoted by '*'
        std::size_t presence = line.find('*');
        if (presence!=std::string::npos){continue;}

        store = tokeniser(line); //Tokenise

        // Get circuit element name
        if (tolower(store[0][0]) == 'r')
        {
            store[0].erase(store[0].begin() + 0); // Remove element identifier
            
            if (store.size() < 3) {std::cerr << "No values entered." << std::endl;} // Ensure there is values entered

            int n1 = GetNode(store[1]), n2 = GetNode(store[2]); // Get the two nodes
            if (n1 == '0' && n2 == '0') {std::cerr << "n1: " << n1 << "n2: " << n2 << "Both nodes cannot be grounded." << std::endl;}; // Ensure nodes cannot be both grounded

            this->N++;
            this->branch_store.push_back(new resistor(store[0], n1, n2, converter(store[3])));
        }
        else if (tolower(store[0][0]) == 'c')
        {
            // To be implemented
            this->N++;
        }
        else if (tolower(store[0][0]) == 'l')
        {
            // To be implemented
            this->N++;
        }
        else if (tolower(store[0][0]) == 'v')
        {
            store[0].erase(store[0].begin() + 0); // Remove element identifier

            if (store.size() < 3) {std::cerr << "No values entered." << std::endl;} // Ensure there is values entered

            int n1 = GetNode(store[1]), n2 = GetNode(store[2]); // Get the two nodes
            if (n1 == '0' && n2 == '0') {std::cerr << "n1: " << n1 << "n2: " << n2 << "Both nodes cannot be grounded." << std::endl;}; // Ensure nodes cannot be both grounded

            this->branch_store.push_back(new vsource(store[0], n1, n2, converter(store[3])));
            this->M++;
        }
        else if (tolower(store[0][0]) == 'i')
        {
            store[0].erase(store[0].begin() + 0); // Remove element identifier

            if (store.size() < 3) {std::cerr << "No values entered." << std::endl;} // Ensure there is values entered

            int n1 = GetNode(store[1]), n2 = GetNode(store[2]); // Get the two nodes
            if (n1 == '0' && n2 == '0') {std::cerr << "n1: " << n1 << "n2: " << n2 << "Both nodes cannot be grounded." << std::endl;}; // Ensure nodes cannot be both grounded

            this->branch_store.push_back(new isource(store[0], n1, n2, converter(store[3])));
            this->M++;
        }
        else
        {
            // To be implemented
        }
    };
};

std::vector<branch*> circuit::get_circuit()
{
    return branch_store;
};

int circuit::get_N()
{ 
    return this->N;
};

int circuit::get_M()
{ 
    return this->M;
};

// Outputs the content of the circuit vector
void circuit::print_data_structure()
{
    std::cout << "Circuit Parser Report" << std::endl;
    std::cout << std::endl;
    // Get nodes and voltage sources
    std::cout << "Number of nodes in circuit: " << get_N() << std::endl;
    std::cout << "Number of independent voltage sources in circuit: " << get_M() << std::endl;
    std::cout << std::endl;

    for (int i = 0; i < branch_store.size(); i++) // Print all elements stored in the vector
    {
        std::cout << (i+1);
        branch_store[i]->print();
    }
};      