<<<<<<< HEAD
<<<<<<< HEAD
#include "../../../Documents/ELEC40006/Bin/Parser_module.hpp"
=======
#include "../../../Documents/ELEC40006/Bin/CirElement.hpp"
>>>>>>> master
=======
#include "../../../Documents/ELEC40006/Bin/Parser.hpp"
>>>>>>> 6eb1d5cdf2a0046d86b102093ff9f9892d052f58
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    std::string line;
    vector<CirElement> store;
    CirElement x;

<<<<<<< HEAD
    store = parser(cin);
<<<<<<< HEAD
=======
    while (std::getline(std::cin, line))
    {
        // cout << "Input " << line << endl;
        store.push_back(parse(line));
    }
>>>>>>> master
=======

    cout << "N: " << N_int(store) << " " << "M: " << M_int(store) << endl;
>>>>>>> 6eb1d5cdf2a0046d86b102093ff9f9892d052f58
    
    for (int i = 0; i < store.size(); i++)
    {
        cout << store[i].D << store[i].descrip << "         " << store[i].n1 << "         " << store[i].n2 << "         " << store[i].value << "         " << store[i].initval << endl;
    }
    
}
