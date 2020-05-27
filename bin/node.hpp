/*
# ===============================================================
# About the code
# ===============================================================
# This code forms the 'Analysis' module' # 
# ===============================================================
*/

#ifndef node_hpp
#define node_hpp

// Classes 
#include "../bin/components/edge.hpp"

class node
{
    protected: // -------------------------------------------------------------------

        std::vector<edge*> connected_edges;
    
    public: //-----------------------------------------------------------------------

        node(){};

        ~node(){};

        void print_node(){};

};

#endif