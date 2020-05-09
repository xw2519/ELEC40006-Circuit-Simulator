#include "../../../Documents/ELEC40006/Bin/CirElement.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    std::string line;
    vector<CirElement> store;
    CirElement x;

    while (std::getline(std::cin, line))
    {
        // cout << "Input " << line << endl;
        store.push_back(parse(line));
    }
    
    for (int i = 0; i < store.size(); i++)
    {
        cout << store[i].D << store[i].descrip << "         " << store[i].n1 << "         " << store[i].n2 << "         " << store[i].value << "         " << store[i].initval << endl;
    }
    
}
