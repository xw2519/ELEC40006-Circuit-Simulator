#include "Analysis.hpp"

using namespace std;

Eigen::VectorXf Analysis(std::vector<CirElement> circuit)
{
    // Get 'N' and 'M' 
    int N = N_int(circuit);
    int M = M_int(circuit);

    // Form matrices "Ax = b"
    // Declare and intialise matrices to 0
    Eigen::MatrixXf A; A.setZero((N+M),(N+M));
    Eigen::VectorXf b = Eigen::VectorXf::Zero((N+M));

    // Variable declarations
    int vcount = 0;

    // Matrix entry module
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
                    A(value.n2-1, value.n2-1) = A(value.n2-1, value.n2-1)+g;
                }
                else if (value.n2 == 0)
                {
                    A(value.n1-1, value.n1-1) = A(value.n1-1, value.n1-1)+g;
                }
                else
                {
                    A(value.n1-1, value.n1-1) = A(value.n1-1, value.n1-1)+g;
                    A(value.n2-1, value.n2-1) = A(value.n2-1, value.n2-1)+g;

                    // Check if at the boundary of inner matrix A_a of size [N X N]
                    if (value.n1 != N || value.n2 != N)
                    {
                        A(value.n1-1, value.n2-1) = (-1)*g;
                        A(value.n2-1, value.n1-1) = (-1)*g;
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
                    A(value.n1-1,(N+vcount-1)) = 1;
                    A((N+vcount-1),value.n1-1) = 1;
                }
                if (value.n1 == 0)
                {
                    A(value.n2-1,(N+vcount-1)) = -1;
                    A((N+vcount-1),value.n2-1) = -1;
                }
                b(N+vcount-1) = value.value;
                break;
            }
            case 'i': // Current goes from N1 to N2
            {
                if (value.n1!=0)
                {
                    b(value.n1-1) = b(value.n1-1) - value.value;
                }
                if (value.n2!=0)
                {
                    b(value.n2-1) = b(value.n2-1) + value.value;
                }
                break;
            }
        }
    }

    // Get solution: matrix x
    Eigen::VectorXf x = A.colPivHouseholderQr().solve(b);
    return x;
}