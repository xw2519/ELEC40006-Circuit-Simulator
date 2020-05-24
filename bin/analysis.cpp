#include "analysis.hpp"

analysis::~analysis()
{

};

void analysis::makeDenseMatrix(circuit& input)
{
    std::vector<branch*> circuit = input.get_circuit();
    N = input.get_N();
    M = input.get_M();
    vcount=0;

    A.setZero((N+M),(N+M));
    b = Eigen::VectorXf::Zero((N+M));
    
    // Loop over entire circuit vector and fill in values
    for(auto const& value: circuit)
    {
        int n1 = value->getNodeL();
        int n2 = value->getNodeR();

        switch (value->getID())
        {
        case 'r':
            // Check for grounded nodes
            if (n1 == 0) {A(n2-1, n2-1) = A(n2-1, n2-1)+value->getconductance();}
            else if (n2 == 0) {A(n1-1, n1-1) = A(n1-1, n1-1)+value->getconductance();}
            else
                {
                    A(n1-1, n1-1) = A(n1-1, n1-1)+value->getconductance();
                    A(n2-1, n2-1) = A(n2-1, n2-1)+value->getconductance();
                    // Check if at the boundary of inner matrix A_a of size [N X N]
                    if (n1 != N || n2 != N)
                    {
                        A(n1-1, n2-1) = (-1)*value->getconductance();
                        A(n2-1, n1-1) = (-1)*value->getconductance();
                    }
                }
            break;

        case 'c':
            break;

        case 'l':
            break;

        case 'v':
            vcount++;
            if (n2 == 0 && n1 != 0) {A(n1-1,(N+vcount-1)) = 1; A((N+vcount-1),n1-1) = 1;}
            if (n1 == 0 && n2 != 0){A(n2-1,(N+vcount-1)) = -1; A((N+vcount-1),n2-1) = -1;}
            if (n1 != 0 && n2 != 0) // n1 is + terminal and n2 is - terminal
            {
                /* Debugging purposes
                cout << "None grounded node detected" << endl;
                */
                A(n2-1,(N+vcount-1)) = -1; A((N+vcount-1),n2-1) = -1;
                A(n1-1,(N+vcount-1)) = 1; A((N+vcount-1),n1-1) = 1;
            }
            b(N+vcount-1) = value->getvoltage();
            break;

        case 'i':
            if (n1!=0) {b(n1-1) = b(n1-1) - value->getvoltage();}
            if (n2!=0) {b(n2-1) = b(n2-1) + value->getvoltage();}
            break;

        default:
            break;
        }
    }
};

void analysis::update()
{

};

void analysis::solve()
{
    x = A.colPivHouseholderQr().solve(b);
};

void analysis::print()
{
    int vcount = 0;
    std::cout << "MNA Report:" << std::endl;
    std::cout << std::endl;
    std::cout << "Nodal voltages:" << std::endl;
    for (int i = 0; i < N; i++)
    {
        std::cout << "Node " << (i+1) << ":" << x[i] << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Voltage source currents:" << std::endl;
    for (int i = N; i < (N+M); i++)
    {
        vcount++;
        std::cout << "v" << "[" << vcount << "]" << " " << "current" << ":" << x[i] << std::endl;
    }
};