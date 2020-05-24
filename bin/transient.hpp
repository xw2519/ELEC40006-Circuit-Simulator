/*
# ===============================================================
# About the code
# ===============================================================
# This code forms the structure of type 'CirElement' including all 
# the methods and variables.
# 
# ===============================================================
*/

#ifndef transient_hpp   
#define transient_hpp

#include <fstream>

void transient (std::vector<CirElement>& circuit,std::vector<CirSrc>& voltages, std::vector<CirSrc>& currents, std::vector<CirFunctions>& functions);

void outputCSV (const Eigen::VectorXcd &sol, ofstream &MyFile);

#endif