#include "simulate.hpp"


// Simualtion parameter functions --------------------------------------------------------------------------------------


void simulate::update_parameters(std::string in_type, double start, double stop, double in_interval)
{
    this->type=in_type; this->start_time=start; 
    this->stop_time=stop; this->timestep=in_interval;
};


// Matrix functions ----------------------------------------------------------------------------------------------------


void simulate::Init_matrices(int N, int M, std::vector<edge*>& Edges)
{
    this->N_store = N; this->M_store=M;
    // Initialise matrices to appropriate sizes defult to 0: Dense matrix approach
    A.setZero((N+M),(N+M));
    b = Eigen::VectorXd::Zero((N+M));
    int vcount=0;
    /* Debugging purposes std::cerr << A << std::endl; std::cout << b << std::endl; */

    for(auto const& edge:Edges)
    {
        int p_N = edge->Get_p_N(); int n_N = edge->Get_n_N(); // Get edges

        switch (edge->Get_ID()) // Non-zero nodes need to be -1 to conform to Eigen notation
        {
            case 'r':
            {
                // Standard procedure to enter conductances
                double g = edge->Get_g();
                if (p_N == 0) {n_N = n_N-1; A(n_N, n_N) = A(n_N, n_N)+g;}
                else if (n_N == 0) {p_N = p_N-1; A(p_N, p_N) = A(p_N, p_N)+g;}
                else
                {
                    assert(p_N!=0 && n_N!=0);
                    p_N=p_N-1; n_N=n_N-1; // Non-zero nodes need to be -1 to conform to Eigen notation
                    A(p_N, p_N) = A(p_N, p_N)+g;
                    A(n_N, n_N) = A(n_N, n_N)+g;
                    // Check if at the boundary of inner matrix A_a of size [N X N] then insert negative conductances
                    if (p_N != N || n_N != N) {A(p_N, n_N) = A(p_N, n_N)-g; A(n_N, p_N) = A(n_N,p_N)-g;}
                }
                break;
            }
            case 'v':
            {
                // Standard procedure to enter voltages contributed
                if (n_N == 0 && p_N != 0) {p_N = p_N-1; A(p_N,(N+vcount)) = 1; A((N+vcount),p_N) = 1;}
                else if (p_N == 0 && n_N != 0) {n_N = n_N-1; A(n_N,(N+vcount)) = 1; A((N+vcount), n_N) = 1;}
                else
                {
                    assert(p_N!=0 && n_N!=0);
                    p_N=p_N-1; n_N=n_N-1; // Non-zero nodes need to be -1 to conform to Eigen notation
                    A(n_N,(N+vcount)) = -1; A((N+vcount),n_N) = -1;
                    A(p_N,(N+vcount)) = 1; A((N+vcount),p_N) = 1;
                }
                b(N+vcount) = edge->Get_voltage(0);
                edge->Update_assigned_ID(vcount);
                vcount++;
                break;
            }
            case 'i':
            {
                // Standard procedure to enter currents contributed
                if (p_N!=0) {p_N = p_N-1; b(p_N) = b(p_N) - edge->Get_current();}
                if (n_N!=0) {n_N = n_N-1; b(n_N) = b(n_N) + edge->Get_current();}
                break;
            }
        }
    }
    /* Debugging purposes std::cerr << A << std::endl; std::cout << b << std::endl; */
};

void simulate::Update_source(std::vector<edge*>vsources)
{
    // Update source value and input new value into matrix
    double voltage;
    for (int i = 0; i < vsources.size(); i++) 
    {
        voltage = vsources[i]->Get_voltage(current_time);
        b(N_store+vsources[i]->Get_assigned_ID()) = voltage;
    }
};

void simulate::Update_dynamic_g(std::vector<edge*>inductors,std::vector<edge*>capacitors)
{
    for (int i = 0; i < inductors.size(); i++)
    {
        int p_N = inductors[i]->Get_p_N(); int n_N = inductors[i]->Get_n_N(); // Get nodes
        // Standard procedure to enter conductances
        double g = inductors[i]->Get_g();
        if (p_N == 0) {n_N = n_N-1; A(n_N, n_N) = A(n_N, n_N)+g;}
        else if (n_N == 0) {p_N = p_N-1; A(p_N, p_N) = A(p_N, p_N)+g;}
        else
        {
            assert(p_N!=0 && n_N!=0);
            p_N=p_N-1; n_N=n_N-1; // Non-zero nodes need to be -1 to conform to Eigen notation
            A(p_N, p_N) = A(p_N, p_N)+g;
            A(n_N, n_N) = A(n_N, n_N)+g;
            // Check if at the boundary of inner matrix A_a of size [N X N] 
            // then insert negative conductances
            if (p_N!=N_store||n_N!=N_store){A(p_N,n_N)=A(p_N,n_N)-g;A(n_N,p_N)=A(n_N,p_N)-g;}
        }

        // Enter current contributed at that point in time into 'b' matrix
        if (p_N!=0) {p_N = p_N-1; b(p_N) = b(p_N) - inductors[i]->Get_instant_current();}
        if (n_N!=0) {n_N = n_N-1; b(n_N) = b(n_N) + inductors[i]->Get_instant_current();}
    }
    
    for (int i = 0; i < capacitors.size(); i++)
    {
        int p_N = capacitors[i]->Get_p_N(); int n_N = capacitors[i]->Get_n_N(); // Get nodes
        // Standard procedure to enter conductances
        double g = capacitors[i]->Get_g();
        if (p_N == 0) {n_N = n_N-1; A(n_N, n_N) = A(n_N, n_N)+g;}
        else if (n_N == 0) {p_N = p_N-1; A(p_N, p_N) = A(p_N, p_N)+g;}
        else
        {
            assert(p_N!=0 && n_N!=0);
            p_N=p_N-1; n_N=n_N-1; // Non-zero nodes need to be -1 to conform to Eigen notation
            A(p_N, p_N) = A(p_N, p_N)+g;
            A(n_N, n_N) = A(n_N, n_N)+g;
            // Check if at the boundary of inner matrix A_a of size [N X N] 
            // then insert negative conductances
            if (p_N!=N_store||n_N!=N_store){A(p_N,n_N)=A(p_N,n_N)-g;A(n_N,p_N)=A(n_N,p_N)-g;}
        }

        // Enter current contributed at that point in time into 'b' matrix
        if (p_N!=0) {p_N = p_N-1; b(p_N) = b(p_N) - capacitors[i]->Get_instant_current();}
        if (n_N!=0) {n_N = n_N-1; b(n_N) = b(n_N) + capacitors[i]->Get_instant_current();}
    }
};

void simulate::Update_prev_values(std::vector<edge*>inductors,std::vector<edge*>capacitors)
{
    // Operation is based on 'Backward Euler' method
    for (int i = 0; i < inductors.size(); i++)
    {
        double I_n = 
    }

    for (int i = 0; i < capacitors.size(); i++)
    {
        // Get capacitor nodes
        int p_node=capacitors[i]->Get_p_N(); int n_node=capacitors[i]->Get_n_N();


        capacitors[i]->Set_instant_current(V_n*capacitors[i]->Get_g());
    } 
};

void simulate::Solve_matrices() {x = A.colPivHouseholderQr().solve(b);};


// Transient simulation functions --------------------------------------------------------------------------------------


void simulate::Transient(std::vector<edge*>& Edges)
{
    // Load simulation parameters
    assert(stop_time>start_time && "Fatal Error: Stop Time cannot be earlier than Start Time.");
    current_time=0; // Start time 0
    intervals=(stop_time-start_time)/timestep; 

    // Record dynamic elements and voltage source for transient analysis
    std::vector<edge*> inductors; std::vector<edge*> capacitors; std::vector<edge*> vsources;
    for (int i = 0; i <= Edges.size(); i++)
    {
        if (Edges[i]->Get_ID() == 'l') {inductors.push_back(Edges[i]);}
        if (Edges[i]->Get_ID() == 'c') {capacitors.push_back(Edges[i]);}
        if (Edges[i]->Get_ID() == 'v') {vsources.push_back(Edges[i]);}
    }
    
    // Set C and L conductances
    for (int i = 0; i < inductors.size(); i++) {inductors[i]->Set_g_value(timestep);}
    for (int i = 0; i < capacitors.size(); i++) {capacitors[i]->Set_g_value(timestep);}
    
    // Transient loop
    for (int i = 0; i < intervals; i++)  
    {
        this->Update_source(vsources);
        this->Update_dynamic_g(inductors,capacitors);
        this->Solve_matrices();
        this->Update_prev_values(inductors,capacitors);
        this->print_CSV();     

        current_time=current_time+timestep;
        if (current_time<stop_time) {std::cerr<<"Note: Current_time exceeded Stop_time."<<std::endl;break;}   
    }
    /* Debugging purposes: std::cerr<<"Transient completed."<<std::endl; */
};


// Output functions ----------------------------------------------------------------------------------------------------


void simulate::print_param()
{
    std::cout<<"Simulation type: "<<this->type<<std::endl;
    std::cout<<"Start time: "<<this->start_time<<std::endl;
    std::cout<<"Stop time: "<<this->stop_time<<std::endl;
    std::cout<<"Interval: "<<this->timestep<<std::endl;
};

void simulate::print_x() 
{
    int vcount = 0;
    std::cout << std::endl;
    std::cout << "Modified Nodal Analysis Report:" << std::endl;
    std::cout << std::endl;
    std::cout << "Nodal voltages:" << std::endl;
    for (int i = 0; i < this->N_store; i++) {std::cout << "Node " << (i+1) << ": " << x[i] << std::endl;}
    std::cout << std::endl;
    std::cout << "Voltage source currents:" << std::endl;
    for (int i = N_store; i < (this->N_store+this->M_store); i++)
    {
        vcount++;
        std::cout << "v" << "[" << vcount << "]" << " " << "current" << ": " << x[i] << std::endl;
    }
};

void simulate::print_CSV() // Output voltages only in CSV format
{
    std::cout<<current_time<<","; 
    for(int i = 0; i < this->N_store; i++){std::cout<<x[i]<<","<<std::endl;}
};
