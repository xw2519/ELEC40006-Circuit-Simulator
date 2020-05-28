#include "simulate.hpp"

void simulate::update_parameters(std::string in_type, double start, double stop, double in_interval)
{
    this->type=in_type; this->start_time=start; 
    this->stop_time=stop; this->interval=in_interval;
};

void simulate::init_matrices(int N, int M, std::vector<node> Nodes)
{
    // Initialise matrices to appropriate sizes defult to 0: Dense matrix approach
    A.setZero((N+M),(N+M));
    b = Eigen::VectorXf::Zero((N+M));
    int vcount=0;
    /* Debugging purposes std::cerr << A << std::endl; std::cout << b << std::endl; */

    // Iterate over every node and fill in attached components in the required place
    for (int i=0; i<Nodes.size(); i++)
    {
        std::vector<edge*> connected = Nodes[i].get_connected();
        for (auto element : connected) // Conductance matrix affect by 'r' and 'v'
        {
            int p_N = element->Get_p_N();
            int n_N = element->Get_n_N();
    
            switch (element->Get_ID())
            {
            case 'r':
                double g = element->Get_g();
                // Check for grounded nodes
                if (p_N==0) {A(n_N-1, n_N-1) = A(n_N-1, n_N-1)+g;}
                else if (n_N==0) {A(p_N-1, p_N-1) = A(p_N-1, p_N-1)+g;}
                else
                {
                    A(p_N-1, p_N-1) = A(p_N-1, p_N-1)+g;
                    A(n_N-1, n_N-1) = A(n_N-1, n_N-1)+g;
                    // Check if at the boundary of inner matrix A_a of size [N X N]
                    if (p_N != N || n_N != N) {A(p_N-1, n_N-1) = (-1)*g; A(n_N-1, p_N-1) = (-1)*g;}
                }
                break;

            case 'v':
                vcount++;
                if (n_N == 0 && p_N != 0) {A(p_N-1,(N+vcount-1)) = 1; A((N+vcount-1),p_N-1) = 1;}
                if (p_N == 0 && n_N != 0){A(n_N-1,(N+vcount-1)) = -1; A((N+vcount-1),n_N-1) = -1;}
                if (p_N != 0 && n_N != 0) // p_N is + terminal and n_N is - terminal
                {
                /* Debugging purposes cerr << "None grounded node detected" << endl; */
                A(n_N-1,(N+vcount-1)) = -1; A((N+vcount-1),n_N-1) = -1;
                A(p_N-1,(N+vcount-1)) = 1; A((N+vcount-1),p_N-1) = 1;
                }
                b(N+vcount-1) = element->Get_voltage();
                break;

            case 'i':
                if (p_N!=0) {b(p_N-1) = b(p_N-1) - element->Get_current();}
                if (n_N!=0) {b(n_N-1) = b(n_N-1) + element->Get_current();}
                break;
            }
        }
    }
    /* Debugging purposes */ std::cerr << A << std::endl; std::cout << b << std::endl; 
};

void simulate::update_matrices()
{

};

void simulate::solve_matrices() {x = A.colPivHouseholderQr().solve(b);};

double simulate::find_voltage()
{

};

double simulate::find_current()
{

};

void simulate::print_param()
{
    std::cout<<"Simulation type: "<<this->type<<std::endl;
    std::cout<<"Start time: "<<this->start_time<<std::endl;
    std::cout<<"Stop time: "<<this->stop_time<<std::endl;
    std::cout<<"Interval: "<<this->interval<<std::endl;
};

void simulate::print_x() {std::cout<<this->x<<std::endl;};