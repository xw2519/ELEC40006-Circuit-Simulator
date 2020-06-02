/*
# ===============================================================
# About the code:
# ===============================================================
# This header file contains all support functions that modifies 
# and extracts necessary information from strings such as 
# converting a 'string' into 'double' data types.
# ===============================================================
*/

#ifndef str_handler_hpp
#define str_handler_hpp

#include "header.hpp"

// Returns boolean true if there is an aplhabetical letter
bool is_digit(const std::string& input);

// Return the float version of the abbreviated string 
double converter(const std::string& val_str);

// Spilts string into words separated by space and pushed into a vector
std::vector<std::string> tokeniser (std::string input);

// Extract nodes from string and return its integer
int GetNode (std::string& node);

#endif