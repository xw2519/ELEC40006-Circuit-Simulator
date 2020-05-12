#include <iostream>
#include <string>
#include "Eigen/Core"
#include "CirElement.hpp"
#include <vector>

using namespace std;

int main()
{
    // Call Parser component
    vector<CirElement> circuit = parser(cin);

    // Get 'N' and 'M' 
    int N = N_int(circuit);
    int M = M_int(circuit);

    // Form matrices "Ax = b"
    // Declare and intialise matrices to 0
    Eigen::MatrixXf A = Eigen::MatrixXf::Zero((N+M)); // Declare square matrix type float and size N+M
    Eigen::VectorXf x = Eigen::VectorXf::Zero((N+M)); // Declare [(N+M) X 1] matrix of type float
    Eigen::VectorXf b = Eigen::VectorXf::Zero((N+M));

    // Variable declarations
    int vcount = 0;

    // Loop over entire circuit vector and fill in values
    for(auto const& value: circuit)
    {
        switch(tolower(value.D))
        {
            case 'r':
            {
                // Find conductance
                float g = 1/value.value;
                // Check for grounded nodes
                if (value.n1 == 0) //
                {
                    A(value.n2, value.n2) = A(value.n2, value.n2)+g;
                }
                else if (value.n2 == 0)
                {
                    A(value.n1, value.n1) = A(value.n1, value.n1)+g;
                }
                else
                {
                    A(value.n1, value.n1) = A(value.n1, value.n1)+g;
                    A(value.n2, value.n2) = A(value.n2, value.n2)+g;

                    // Check if at the boundary of inner matrix A_a of size [N X N]
                    if (value.n1 != N || value.n2 != N)
                    {
                        A(value.n1, value.n2) = (-1)*g;
                        A(value.n2, value.n1) = (-1)*g;
                    }
                }
                break;
            }
            case 'c': // Support to be added
            {
                break;
            }
            case 'l': // Support to be added
            {
                break;
            }
            case 'v': // Notation: < n+ >, < n- >
            {
                vcount++;
                if (value.n2 == 0)
                {
                    A(value.n1,(N+vcount)) = 1;
                    A((N+vcount),value.n1) = 1;
                }
                if (value.n1 == 0)
                {
                    A(value.n2,(N+vcount)) = -1;
                    A((N+vcount),value.n2) = -1;
                }
                b(N+vcount) = value.value;
                break;
            }
            case 'i': // Current goes from N1 to N2
            {
                if (value.n1!=0)
                {
                    b(value.n1) = b(value.n1) - value.value;
                }
                if (value.n2!=0)
                {
                    b(value.n2) = b(value.n2) + value.value;
                }
                break;
            }
        }
    }

    cout << "A: " << A << endl;
    cout << "x: " << x << endl;
    cout << "b: " << b << endl;
}
