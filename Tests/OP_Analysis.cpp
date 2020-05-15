#include <iostream>
#include <string>
#include "../Bin/Eigen/Core"
#include "../Bin/Eigen/Dense"
#include "../Bin/Parser.hpp"
#include "../Bin/Analysis.hpp"
#include <vector>

using namespace std;

int main()
{
    // Call Parser component
    vector<CirElement> circuit;
    vector<CirSrc> sources;

    parser(cin, circuit, sources);

    
    Eigen::VectorXf x = OP_Analysis(circuit, sources);

    cout << "x: " << endl;
    cout << x << endl;
}
