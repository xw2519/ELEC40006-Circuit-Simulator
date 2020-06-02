#include "node.hpp"


// Class operations ----------------------------------------------------------------------------------------------------


node::~node() 
{
    // This method prevents 'double free' problem and potential accessing unintended memory contents
    for(int i=0;i<connected_edges.size();i++) {if (connected_edges[i]!=NULL) {connected_edges[i]=NULL;}}
};


// Vector operations ---------------------------------------------------------------------------------------------------


void node::update_node(edge* in_edge) {connected_edges.push_back(in_edge);};

int node::connected_edges_size() {return connected_edges.size();};

std::vector<edge*> node::get_connected(){return connected_edges;};


// Class operations ----------------------------------------------------------------------------------------------------


void node::print_node()
{
    for(int i=0;i<connected_edges.size();i++) {std::cout<<"     "; connected_edges[i]->print_edge();}
    std::cout<<std::endl;
};