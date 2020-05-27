#include "circuit.hpp"
#include "header.hpp"


/* Class operations */

circuit::circuit(std::istream& cin)
{
    bool firstline = true;
    std::string line;
    std::vector<std::string> store;

     while (std::getline(std::cin, line))
    {
        // Check for beginning TITLE and skip
        if (firstline) {firstline = false; continue;}
        // Check for .end
        if (line == ".end") {break;}
        // Check if this line is a comment, denoted by '*'
        std::size_t presence = line.find('*');
        if (presence!=std::string::npos) {continue;}

        store = tokeniser(line); //Tokenise the string

        // Get circuit element name
        if (tolower(store[0][0]) == 'r')
        {
            store[0].erase(store[0].begin() + 0); // Remove element identifier
            
            if (store.size() < 3) {std::cerr << "Error: No values entered." << std::endl;} // Ensure there is values entered
            int n1 = GetNode(store[1]), n2 = GetNode(store[2]); // Get the two nodes
            if (n1 == '0' && n2 == '0') {std::cerr << "n1: " << n1 << "n2: " << n2 << "Error: Both nodes cannot be grounded." << std::endl;}; // Ensure nodes cannot be both grounded
            
            this->Edges.push_back(new resistor(store[0], n1, n2, converter(store[3])));
        }
        else if (tolower(store[0][0]) == 'c')
        { 
            store[0].erase(store[0].begin() + 0); // Remove element identifier
            
            if (store.size() < 3) {std::cerr << "Error: No values entered." << std::endl;} // Ensure there is values entered

            int n1 = GetNode(store[1]), n2 = GetNode(store[2]); // Get the two nodes
            if (n1 == '0' && n2 == '0') {std::cerr << "n1: " << n1 << "n2: " << n2 << "Error: Both nodes cannot be grounded." << std::endl;}; // Ensure nodes cannot be both grounded

            this->Edges.push_back(new capacitor(store[0], n1, n2, converter(store[3]))); 
        }
        else if (tolower(store[0][0]) == 'l')
        {
            store[0].erase(store[0].begin() + 0); // Remove element identifier
            
            if (store.size() < 3) {std::cerr << "Error: No values entered." << std::endl;} // Ensure there is values entered

            int n1 = GetNode(store[1]), n2 = GetNode(store[2]); // Get the two nodes
            if (n1 == '0' && n2 == '0') {std::cerr << "n1: " << n1 << "n2: " << n2 << "Error: Both nodes cannot be grounded." << std::endl;}; // Ensure nodes cannot be both grounded

            this->Edges.push_back(new inductor(store[0], n1, n2, converter(store[3]))); 
        }
        else if (tolower(store[0][0]) == 'v')
        {
            store[0].erase(store[0].begin() + 0); // Remove element identifier
            if (store.size() < 3) {std::cerr << "Error: No values entered." << std::endl;} // Ensure there is values entered

            int n1 = GetNode(store[1]), n2 = GetNode(store[2]); // Get the two nodes
            if (n1 == '0' && n2 == '0') {std::cerr << "n1: " << n1 << "n2: " << n2 << "Error: Both nodes cannot be grounded." << std::endl; break;}; // Ensure nodes cannot be both grounded

            // Deterimine if 'SINE' is mentioned in input
            if (store[3] == "SINE" || store[3] == "sine")
            {
                /* Debugging purposes std::cout << "Sine detected." << std::endl */
                this->Edges.push_back(new vsource(store[0], GetNode(store[1]), GetNode(store[2]), "SINE", converter(store[4]), converter(store[5]), converter(store[6])));
            }
            else if (store.size() == 4) // Treat as DC source
            {
                /* Debugging purposes std::cout << "DC detected." << std::endl */
                this->Edges.push_back(new vsource(store[0], GetNode(store[1]), GetNode(store[2]), "DC", converter(store[3]), 0, 0));
            }
            else{std::cerr << "Error: Unsupported voltage source type." << std::endl;}
        }
        else if (tolower(store[0][0]) == 'i')
        {
            store[0].erase(store[0].begin() + 0); // Remove element identifier
            if (store.size() < 3) {std::cerr << "Error: No values entered." << std::endl;} // Ensure there is values entered

            int n1 = GetNode(store[1]), n2 = GetNode(store[2]); // Get the two nodes
            if (n1 == '0' && n2 == '0') {std::cerr << "n1: " << n1 << "n2: " << n2 << "Error: Both nodes cannot be grounded." << std::endl;}; // Ensure nodes cannot be both grounded

            this->Edges.push_back(new isource(store[0], n1, n2, converter(store[3])));
        }
        else if (store[0] == ".op") // DC analysis
        {
            this->Analysis_param.type = ".op";
            this->Analysis_param.start_time = 0;
            this->Analysis_param.stop_time = 0;
            this->Analysis_param.interval = 0;
        }
        else if (store[0] == ".tran") // E.g. .tran 0 <stop time> 0 <timestep>
        {
            this->Analysis_param.type = ".tran";
            this->Analysis_param.start_time = converter(store[2]);
            this->Analysis_param.stop_time = 0;
            this->Analysis_param.interval = converter(store[4]);
        }
        else {std::cerr << "Error: Unsupported component or instruction inputted." << std::endl;}
    };
    /* Debugging purposes std::cerr<<"Progess report: Edges stored."<<std::endl; */
};

circuit::~circuit()
{
    for (auto node : Nodes) {node.~node();}
    /* Debugging purposes std::cerr << "Progess report: Nodes deleted." << std::endl; */

    for (auto edge : Edges) {edge->~edge();}
    /* Debugging purposes std::cerr << "Progess report: Edges deleted." << std::endl; */
};


/* Nodes operations */
void circuit::init_nodes()
{
    int Node_count=0;

    // Find largest node
    for (int i=0; i<Edges.size();i++)
    {
        Node_count = std::max(Node_count, Edges[i]->Get_p_N()); 
        Node_count = std::max(Node_count, Edges[i]->Get_n_N());
    }
    /* Debugging purposes std::cerr<<"Progess report: Largest node calaculated: "<<Node_count<<std::endl; */
    
    // Initialises the vector to the required size before entry process
    for (int i = 0; i < Node_count; i++) {node input; Nodes.push_back(input);}

    // Entry process by looping over 'Edges' vector
    for (int i=0; i<Edges.size();i++)
    {
        Nodes[Edges[i]->Get_p_N()].update_node(Edges[i]);
        Nodes[Edges[i]->Get_n_N()].update_node(Edges[i]);
    }
    /* Debugging purposes std::cerr<<"Progess report: Node initialisation successful."<<std::endl;*/

    // Perform basic semantic check: Ensure node starts from 0 and is continuous
    for (int i=0; i<Nodes.size(); i++)
    {
        /* Debugging purposes std::cerr<<"Progess report: Semantic check initialised."<<std::endl; */
        if (Nodes[i].connected_edges_size()== 0)
        {
            std::cerr<<"Error: Node semantic check failed. Incorrect input data."<<std::endl; 
            assert(0);
        }
    }
    /* Debugging purposes std::cerr<<"Progess report: Circuit semantic check successful."<<std::endl; */
};

std::vector<node> circuit::Get_Nodes() {return this->Nodes;};

void circuit::Print_Nodes() 
{
    std::cout<<std::endl; 
    std::cout<<"Circuit Nodes Report: "<<std::endl;
    std::cout<<std::endl; 

    for (int i=0; i<Nodes.size(); i++) 
    {
        std::cout << "Node: "<<i<<" "<<std::endl;;
        Nodes[i].print_node();
    }
};


/* Edges operations */
std::vector<edge*> circuit::Get_Edges() {return this->Edges;};

void circuit::Print_Edges() 
{
    std::cout<<std::endl;
    std::cout<<"Circuit Edge Report: "<<std::endl;
    std::cout<<std::endl;
    for (auto edge : Edges) {edge->print_edge();}
};


/* Analysis operations */
AnalysisType circuit::Get_Analysis_param() {return this->Analysis_param;};