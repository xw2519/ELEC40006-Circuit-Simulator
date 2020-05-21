
#include "../../../../Documents/ELEC40006/bin/parser.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    std::string line;
    vector<CirElement> store;
    vector<CirSrc> sources;
    vector<CirFunctions> functions;
    CirElement x;

    // Sort input
    parser(cin, store, sources, functions);

    cout << "N: " << N_int(store) << endl;
    cout << "M: " << M_int(sources) << endl;
    cout << endl;
    if (store.size() != 0)
    {
        cout << "Circuit elements" << endl;
        for (int i = 0; i < store.size(); i++)
        {
            cout << store[i].D << store[i].descrip << "         " << store[i].n1 << "         " << store[i].n2 << "         " << store[i].value << endl;
        }
    }
    cout << endl;
    if (sources.size() != 0)
    {
        cout << "Sources" << endl;
        for (int i = 0; i < sources.size(); i++)
        {
            cout << sources[i].D << sources[i].descrip << "         " << sources[i].n1 << "         " << sources[i].n2 << "         " << sources[i].type << "         " << sources[i].DC << "         " << sources[i].A << "         " << sources[i].freq << endl;
        }
    }
    cout << endl;
    int i = 0;
    if (functions.size() != 0)
    {
        cout << "Functions" << endl;
        while(i != functions.size())
        {
            cout << functions[i].func_name << "         " << functions[i].tprint << "         " << functions[i].tstop << "         " << functions[i].tstart << "         " << functions[i].tmax << endl;
            i ++;
        }
    }
}
