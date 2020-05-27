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
#include "analysis_type.hpp"
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

        // The number of nodes in circuit and its connected edges
        std::vector<node> Nodes; 

        // The edges in the circuit used to create the vector 'nodes'
        std::vector<edge*> Edges;

        // Contains the necessary inputted information for analysis
        AnalysisType Analysis_param;

    public: //-----------------------------------------------------------------------

        /* Class operations */
        circuit(std::istream& cin);
        ~circuit();


        /* Nodes operations */
        void init_nodes(); // Initialises the content of Nodes vector
        std::vector<node> Get_Nodes();
        void Print_Nodes();


        /* Edges operations */
        std::vector<edge*> Get_Edges();
        void Print_Edges();


        /* Analysis operations */
        AnalysisType Get_Analysis_param();
};

#endif