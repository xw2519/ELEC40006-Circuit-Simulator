#include "Analysis.hpp"

using namespace std;

Eigen::VectorXf Analysis(std::vector<CirElement> circuit, std::vector<CirSrc> sources ,std::complex omega)
{
    // Get 'N' and 'M' 
    int N = N_int(circuit);
    int M = M_int(circuit);

    // Form matrices "Ax = b"
    // Declare and intialise matrices to 0
    Eigen::MatrixXcf A; A.setZero((N+M),(N+M));
    Eigen::VectorXcf b = Eigen::VectorXcf::Zero((N+M));


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
        switch(tolower(sources.D))
        {
            case 'v': // Notation: < n+ >, < n- >
            {
                vcount++;
                if (sources.n2 == 0)
                {
                    A(sources.n1-1,(N+vcount-1)) = 1;
                    A((N+vcount-1),sources.n1-1) = 1;
                }
                if (sources.n1 == 0)
                {
                    A(sources.n2-1,(N+vcount-1)) = -1;
                    A((N+vcount-1),sources.n2-1) = -1;
                }
                b(N+vcount-1) = sources.value;
                break;
            }
            case 'i': // Current goes from N1 to N2
            {
                if (sources.n1!=0)
                {
                    b(sources.n1-1) = b(sources.n1-1) - sources.value;
                }
                if (sources.n2!=0)
                {
                    b(sources.n2-1) = b(sources.n2-1) + sources.value;
                }
                break;
            }
        }
    }

    // Get solution: matrix x
    Eigen::VectorXf x = A.colPivHouseholderQr().solve(b);
    return x;
}