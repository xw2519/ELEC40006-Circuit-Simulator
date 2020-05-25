#include "circuit.hpp"

circuit::~circuit()
{
    
};

void circuit::parse(std::istream& cin)
{
    bool firstline = true;
    std::string line;
    std::vector<std::string> store;
    N=0; M=0;

    while (std::getline(std::cin, line))
    {
        // Check for beginning TITLE and skip
        if (firstline){firstline = false; continue;}
        // Check for .end
        if (line == ".end"){break;}
        // Check if this line is a comment, denoted by '*'
        std::size_t presence = line.find('*');
        if (presence!=std::string::npos){continue;}

        store = tokeniser(line); //Tokenise

        // Get circuit element name
        if (tolower(store[0][0]) == 'r')
        {
            store[0].erase(store[0].begin() + 0); // Remove element identifier
            
            if (store.size() < 3) {std::cerr << "No values entered." << std::endl;} // Ensure there is values entered

            int n1 = GetNode(store[1]), n2 = GetNode(store[2]); // Get the two nodes
            if (n1 == '0' && n2 == '0') {std::cerr << "n1: " << n1 << "n2: " << n2 << "Both nodes cannot be grounded." << std::endl;}; // Ensure nodes cannot be both grounded

            this->N++;
            this->branch_store.push_back(new resistor(store[0], n1, n2, converter(store[3])));
        }
        else if (tolower(store[0][0]) == 'c')
        {
            // To be implemented
            this->N++;
        }
        else if (tolower(store[0][0]) == 'l')
        {
            // To be implemented
            this->N++;
        }
        else if (tolower(store[0][0]) == 'v')
        {
            store[0].erase(store[0].begin() + 0); // Remove element identifier

            if (store.size() < 3) {std::cerr << "No values entered." << std::endl;} // Ensure there is values entered

            int n1 = GetNode(store[1]), n2 = GetNode(store[2]); // Get the two nodes
            if (n1 == '0' && n2 == '0') {std::cerr << "n1: " << n1 << "n2: " << n2 << "Both nodes cannot be grounded." << std::endl; break;}; // Ensure nodes cannot be both grounded

            vsource* pointer = new vsource();
            pointer->source_resolver(store);
            this->branch_store.push_back(pointer);
            this->M++;
        }
        else if (tolower(store[0][0]) == 'i')
        {
            store[0].erase(store[0].begin() + 0); // Remove element identifier

            if (store.size() < 3) {std::cerr << "No values entered." << std::endl;} // Ensure there is values entered

            int n1 = GetNode(store[1]), n2 = GetNode(store[2]); // Get the two nodes
            if (n1 == '0' && n2 == '0') {std::cerr << "n1: " << n1 << "n2: " << n2 << "Both nodes cannot be grounded." << std::endl;}; // Ensure nodes cannot be both grounded

            this->branch_store.push_back(new isource(store[0], n1, n2, converter(store[3])));
            this->M++;
        }
        else if (store[0] == ".op") // DC analysis
        {
            func_name = ".op"; stop_time=0; timestep=0;
        }
        else if (store[0] == ".tran") // E.g. .tran 0 <stop time> 0 <timestep>
        {
            func_name = ".tran"; stop_time = converter(store[2]); stop_time = converter(store[4]);
        }
        else
        {
            std::cerr << "Unsupported component or instruction inputted." << std::endl;
        }
    };
};

void circuit::func_param(std::string& func_name, double& stop_time, double& timestep)
{
    func_name = this->func_name; stop_time = this->stop_time; timestep = this->timestep;
}

void circuit::makeDenseMatrix()
{
    A.setZero((N+M),(N+M));
    b = Eigen::VectorXf::Zero((N+M));
    vcount=0;

    /* Debugging purposes 
    std::cout << A << std::endl;
    std::cout << b << std::endl; */
    
    // Loop over entire circuit vector and fill in values
    for(auto const& value: branch_store)
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

void circuit::update()
{

};

void circuit::solve()
{
    x = A.colPivHouseholderQr().solve(b);
};

void circuit::print_data_structure()
{
    std::cout << "Circuit Parser Report" << std::endl;
    std::cout << std::endl;
    // Get nodes and voltage sources
    std::cout << "Number of nodes in circuit: " << N << std::endl;
    std::cout << "Number of independent voltage sources in circuit: " << M << std::endl;
    std::cout << std::endl;

    for (int i = 0; i < branch_store.size(); i++) // Print all elements stored in the vector
    {
        std::cout << (i+1);
        branch_store[i]->print();
    }
};   

void circuit::print_dc_sol()
{
    int vcount = 0;
    std::cout << "MNA Report:" << std::endl;
    std::cout << std::endl;
    std::cout << "Nodal voltages:" << std::endl;
    for (int i = 0; i < N; i++)
    {
        std::cout << "Node " << (i+1) << ": " << x[i] << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Voltage source currents:" << std::endl;
    for (int i = N; i < (N+M); i++)
    {
        vcount++;
        std::cout << "v" << "[" << vcount << "]" << " " << "current" << ": " << x[i] << std::endl;
    }
};

void print_csv()
{

};