/*
# ===============================================================
# About the code
# ===============================================================
# This header file contains all support functions that determines 
# and extracts the necessary information regarding the types of 
# voltage sources e.g. SINE and DC
# ===============================================================
*/

#ifndef vsrc_resolver_hpp
#define vsrc_resolver_hpp

// Classes 
#include "../bin/components/vsource.hpp"

#include "header.hpp"

// Parser component
// Returns the type 'vsource' and determines the correct type of voltage source
vsource* src_resolver (std::vector<std::string> store);

#endif