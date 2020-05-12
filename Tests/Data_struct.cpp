#include "../../../Documents/ELEC40006/Bin/Parser_module.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    std::string line;
    vector<CirElement> store;
    CirElement x;

    store = parser(cin);
    
    for (int i = 0; i < store.size(); i++)
    {
        cout << store[i].D << store[i].descrip << "         " << store[i].n1 << "         " << store[i].n2 << "         " << store[i].value << "         " << store[i].initval << endl;
    }
    
}
