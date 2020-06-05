/*
# ===============================================================
# About the code
# ===============================================================
# This code forms the 'Analysis' module' # 
# ===============================================================
*/

#ifndef circuit_hpp
#define circuit_hpp

#include "header.hpp"
#include "simulate.hpp"
#include "node.hpp"
#include "../bin/components/edge.hpp"
#include "../bin/components/resistor.hpp"
#include "../bin/components/capacitor.hpp"
#include "../bin/components/inductor.hpp"
#include "../bin/components/vsource.hpp"
#include "../bin/components/isource.hpp"

class circuit
{
    private: // ---------------------------------------------------------------------

        // The edges in the circuit used to create the vector 'nodes'
        std::vector<edge*> Edges;

        // The number of nodes in circuit and its connected edges
        std::vector<node> Nodes; 

        // Contains the necessary inputted information for analysis
        simulate Simulation;

    public: //-----------------------------------------------------------------------

        /* Class operations */
        circuit(std::istream& cin);
        ~circuit();


        /* Edges operations */
        std::vector<edge*> Get_Edges();
        int Get_M(); // Return number of independent voltage sources
        int Get_N(); // Return number of nodes in the circuit
        void Print_Edges();


        /* Nodes operations */
        void Init_nodes(); // Initialises the content of Nodes vector
        std::vector<node> Get_Nodes();
        void Print_Nodes();


        /* Simulation operations */
        void Init_simulation();
        void Simul_solve();
        void Transient_solve();

        void Print_simul_parameters();
        void Print_vsource();
        void Print_simul_results();
};

#endif