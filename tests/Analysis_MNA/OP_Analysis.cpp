#include <iostream>
#include <string>
#include "../../bin/Eigen/Core"
#include "../../bin/Eigen/Dense"
#include "../../bin/Parser.hpp"
#include "../../bin/Analysis.hpp"
#include <vector>

using namespace std;

int main()
{
    // Call Parser component
    vector<CirElement> circuit;
    vector<CirSrc> sources;

    parser(cin, circuit, sources);

    
    Eigen::VectorXf x = OP_Analysis(circuit, sources);
    int node = N_int(circuit);
    int source = M_int(sources);

    cout << "Matrix x: " << endl;
    for (int i = 0; i < node; i++)
    {
        cout << "Node " << i << " " << x[i];
        cout << endl;
    }
    for (int j = node; j < node+source; j++)
    {
        cout << "Source current " << j << " " << x[j];
        cout << endl;
    }
    
    
}
