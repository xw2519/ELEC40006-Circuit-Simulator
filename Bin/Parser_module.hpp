/*
# ===============================================================
# About the code
# ===============================================================
# This code forms the structure of type 'CirElement' including all 
# the methods and variables.
# 
# ===============================================================
*/

#ifndef Parser_module_hpp
#define Parser_module_hpp

#include <string>
#include <iostream>
#include <vector>


struct CirElement
{
    char D;
    std::string descrip;
    std::string n1;
    std::string n2;
    float value;
    float initval;
};

// Returns boolean true if there is an aplhabetical letter
bool isdigit(const std::string& input);

// Return the float version of the abbreviated string 
float custom_pow(std::string val_str);

// Spilts string into words separated by space and pushed into a vector
std::vector<std::string> tokeniser (std::string input);

// Returns type CirElement from input stream
std::vector<CirElement> parser(std::istream& cin);


#endif
