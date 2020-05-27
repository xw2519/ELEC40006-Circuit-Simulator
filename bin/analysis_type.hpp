/*
# ===============================================================
# About the code
# ===============================================================
# This code forms the 'Analysis' module' # 
# ===============================================================
*/

#ifndef analysis_type_hpp
#define analysis_type_hpp

#include "header.hpp"

struct AnalysisType
{
    std::string type;

    double 
        start_time,
        stop_time,
        interval;
};

#endif