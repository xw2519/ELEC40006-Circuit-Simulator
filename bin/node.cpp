#include "node.hpp"

node::~node() {for(auto edge : connected_edges){delete edge;}};

void node::update_node(edge* in_edge) {connected_edges.push_back(in_edge);};

int node::connected_edges_size() {return connected_edges.size();};

void node::print_node()
{
    std::cout<<std::endl<<"Connected Edges Report: "<<std::endl;

    for (int i = 0; i < connected_edges.size(); i++)
    {
        for(auto edge : connected_edges) {edge->print_edge();}
    }
};