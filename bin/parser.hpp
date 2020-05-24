/*
# ===============================================================
# About the code
# ===============================================================
# This code forms the structure of type 'CirElement' including all 
# the methods and variables.
# 
# ===============================================================
*/

#ifndef parser_hpp
#define parser_hpp

#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <assert.h>
#include <regex>
#include <algorithm>


// struct for circuit element
struct CirElement
{
    char D;
    std::string descrip;
    int n1;
    int n2;
    float value;
};

// struct for circuit sources
struct CirSrc
{
    char D;
    std::string descrip;
    int n1;
    int n2;
    std::string type;
    float DC;
    float A;
    float freq;
};

// struct for circuit function parameters
struct CirFunctions
{
    std::string func_name;
    float tprint;
    float tstop;
    float tstart;
    float tmax;
};

// Parser module
// Returns boolean true if there is an aplhabetical letter
bool is_digit(const std::string& input);

// Return the float version of the abbreviated string 
float converter(const std::string& val_str);

// Spilts string into words separated by space and pushed into a vector
std::vector<std::string> tokeniser (std::string input);

// Sorts input into respective vectors: vector<CirElement> and vector<CirSrc>
void parser(std::istream& cin, std::vector<CirElement>& circuit, std::vector<CirSrc>& sources, std::vector<CirFunctions>& functions);

// Return number of elements in circuit: N
int N_int(const std::vector<CirElement> &circuit);

// Return number of independent voltage sources in circuit: M
int M_int(const std::vector<CirSrc> &voltages);

#endif
