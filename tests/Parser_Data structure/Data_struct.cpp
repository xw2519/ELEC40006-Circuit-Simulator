
#include "../../../../Documents/ELEC40006/bin/Parser.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    std::string line;
    vector<CirElement> store;
    vector<CirSrc> sources;
    CirElement x;

    // Sort input
    parser(cin, store, sources);

    cout << "N: " << N_int(store) << endl;
    cout << "M: " << M_int(sources) << endl;
    cout << "Circuit elements" << endl;
    for (int i = 0; i < store.size(); i++)
    {
        cout << store[i].D << store[i].descrip << "         " << store[i].n1 << "         " << store[i].n2 << "         " << store[i].value << endl;
    }
    cout << "Sources" << endl;
    for (int i = 0; i < sources.size(); i++)
    {
        cout << sources[i].D << sources[i].descrip << "         " << sources[i].n1 << "         " << sources[i].n2 << "         " << sources[i].type << "         " << sources[i].DC << "         " << sources[i].A << "         " << sources[i].freq << endl;
    }
    
}
