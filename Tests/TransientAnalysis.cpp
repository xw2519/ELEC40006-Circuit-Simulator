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
    vector<CirElement> circuit = parser(cin);

    
    Eigen::VectorXf x = Analysis(circuit);

    cout << "x: " << endl;
    cout << x << endl;
}
