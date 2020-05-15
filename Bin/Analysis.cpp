#include "Analysis.hpp"

using namespace std;

Eigen::VectorXf Analysis(std::vector<CirElement> circuit, std::vector<CirSrc> sources)
{
    // Get 'N' and 'M' 
    int N = N_int(circuit);
    int M = M_int(sources);

    // Form matrices "Ax = b"
    // Declare and intialise matrices to 0
    Eigen::MatrixXf A; A.setZero((N+M),(N+M));
    Eigen::VectorXf b = Eigen::VectorXf::Zero((N+M));


    // Matrix entry module for circuit elements
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
        }
    }

    // Matrix entry module for sources
    // Loop over entire circuit vector and fill in values
    int vcount = 0;

    for(auto const& src: sources)
    {
        switch(tolower(src.D))
        {
            case 'v': // Notation: < n+ >, < n- >
            {
                vcount++;
                if (src.n2 == 0)
                {
                    A(src.n1-1,(N+vcount-1)) = 1;
                    A((N+vcount-1),src.n1-1) = 1;
                }
                if (src.n1 == 0)
                {
                    A(src.n2-1,(N+vcount-1)) = -1;
                    A((N+vcount-1),src.n2-1) = -1;
                }
                b(N+vcount-1) = src.DC;
                break;
            }
            case 'i': // Current goes from N1 to N2
            {
                if (src.n1!=0)
                {
                    b(src.n1-1) = b(src.n1-1) - src.DC;
                }
                if (src.n2!=0)
                {
                    b(src.n2-1) = b(src.n2-1) + src.DC;
                }
                break;
            }
        }
    }

    cout << A << endl;
    cout << b << endl;

    // Get solution: matrix x
    Eigen::VectorXf x = A.colPivHouseholderQr().solve(b);
    return x;
}