/*
# ===================================================================================
# About the code
# ===================================================================================
# This code forms the 'Analysis' module' # 
# ===================================================================================
*/

#ifndef node_hpp
#define node_hpp

// Classes 
#include "../bin/components/edge.hpp"

class node
{
    private: // ---------------------------------------------------------------------

        std::vector<edge*> connected_edges;
    
    public: //-----------------------------------------------------------------------

        /* Class operations */
        ~node();

        /* Vector operations */
        void update_node(edge* in_edge);
        int connected_edges_size();
        std::vector<edge*> get_connected();

        /* Output operations */
        void print_node();
};

#endif