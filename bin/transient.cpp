#include "transient.hpp"
#include "parser.hpp"
#include "analysis.hpp"

using namespace std;

void transient (std::vector<CirElement>& circuit,std::vector<CirSrc>& voltages, std::vector<CirSrc>& currents, std::vector<CirFunctions>& functions)
{
    // Create and open a text file
    ofstream MyFile("Analysis output.csv");

    /* 
        In this case there is only the .tran function. But the architecture is designed to accommodate other functions easily.
        It is assumed there is only the .tran function in the vector, no other checks are performed
    */

    // Declare transient parameters
    CirFunctions tran_ctrl;

    if (functions[0].func_name == ".tran")
    {
        tran_ctrl = functions[0];
    }
    else{cerr << "Unrecognised analysis function.";}
    
    // Implement transient structure


}

void outputCSV (const Eigen::VectorXcd &sol, ofstream &MyFile)
{
    // Write to file following .CSV format
    int rows = sol.rows();
    
    for (int i = 0; i < rows; i++)
    {
        if (i == rows)
        {
            MyFile << sol[i] << endl;
        }
        else
        {
            MyFile << sol[i] << ",";
        }
    }
    
    // Close the file
    MyFile.close();
}