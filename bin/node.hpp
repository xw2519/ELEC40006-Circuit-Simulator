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

        ~node();

        void update_node(edge* in_edge);

        int connected_edges_size();

        void print_node();
};

#endif