/*
# ===============================================================
# About the code
# ===============================================================
# This code forms the structure of type 'CirElement' including all 
# the methods and variables.
# 
# ===============================================================
*/

<<<<<<< HEAD:Bin/Parser_module.hpp
#ifndef Parser_module_hpp
#define Parser_module_hpp
=======
#ifndef Parser_hpp
#define Parser_hpp
>>>>>>> 6eb1d5cdf2a0046d86b102093ff9f9892d052f58:Bin/Parser.hpp

#include <string>
#include <iostream>
#include <vector>


struct CirElement
{
    char D;
    std::string descrip;
    int n1;
    int n2;
    float value;
    float initval;
};

// Returns boolean true if there is an aplhabetical letter
bool is_digit(const std::string& input);

// Return the float version of the abbreviated string 
float converter(std::string val_str);

// Spilts string into words separated by space and pushed into a vector
std::vector<std::string> tokeniser (std::string input);

// Returns type CirElement from input stream
std::vector<CirElement> parser(std::istream& cin);


// Analysis module
// Return number of elements in circuit: N
int N_int(std::vector<CirElement> circuit);

// Return number of independent voltage sources in circuit: M
int M_int(std::vector<CirElement> circuit);

#endif
