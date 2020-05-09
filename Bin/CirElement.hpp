/*
# ===============================================================
# About the code
# ===============================================================
# This code forms the structure of type 'CirElement' including all 
# the methods and variables.
# 
# ===============================================================
*/

#ifndef CirElement_hpp
#define CirElement_hpp

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

// Returns type CirElement from input stream
CirElement parse(std::string input);

std::vector<std::string> tokeniser (std::string input);

#endif
