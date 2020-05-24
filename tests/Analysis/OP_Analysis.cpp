#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include "../../bin/Eigen/Core"
#include "../../bin/Eigen/Dense"
#include "../../bin/parser.hpp"
#include "../../bin/analysis.hpp"


using namespace std;

int main()
{
    // Get starting time 
    auto start = chrono::high_resolution_clock::now(); 

    // Call Parser component
    vector<CirElement> circuit;
    vector<CirSrc> sources;
    vector<CirFunctions> functions;

    parser(cin, circuit, sources, functions);

    Eigen::VectorXf x = OP_Analysis(circuit, sources);
    int node = N_int(circuit);
    int source = M_int(sources);

    // Get ending time 
    auto stop = chrono::high_resolution_clock::now(); 

    // Get difference between start and end
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start); 
    cout << endl;
    cout << "Time taken for module to execute: " << duration.count() << " microseconds" << endl; 
    cout << endl;
    cout << "Analysis module report:" << endl;
    cout << endl;

    cout << "Matrix x: " << endl;
    cout << x << endl;
}
