#include "str_handler.hpp"

std::vector<std::string> tokeniser (std::string input)
{
    // Remove '(' char if present
    replace(input.begin(),input.end(),'(',' ');

    // Remove ')' char if present
    input.erase(std::remove(input.begin(),input.end(),')'),input.end());

    std::istringstream iss(input);
    std::vector<std::string> tokensied ((std::istream_iterator<std::string>(iss)), std::istream_iterator<std::string>());
    return tokensied;
}

bool is_digit(const std::string& input)
{
    std::string::const_iterator it = input.begin();
    while (it != input.end() && std::isdigit(*it) || it != input.end() && (*it=='.')) ++it;
    return !input.empty() && it == input.end();
}

double converter(const std::string& val_str)
{
    double digits;

    // Check if there are any abbreviations
    size_t abbre_pos = val_str.find_first_of("fpnumkMGT");

    if (abbre_pos==std::string::npos)
    {
        // No recognised abbreviation, extract digits
        try {return std::stod(val_str);}
        catch(std::exception& e) {std::cerr<<"Invalid digit inputted."<<std::endl; assert(0);};
    }

    // A recognised abbreviation detected
    std::string str_digits = val_str.substr(0, (abbre_pos));

    switch (val_str[abbre_pos])
    {
    case 'f': return stof(str_digits)/1000000000000000;
    case 'p': return stof(str_digits)/1000000000000;
    case 'n': return stof(str_digits)/1000000000;
    case 'u': return stof(str_digits)/1000000;
    case 'k': return stof(str_digits)*1000;
    case 'G': return stof(str_digits)*1000000000;
    case 'T': return stof(str_digits)*1000000000000;
    default: break;
    }

    // Special case of Meg and m
    if ((val_str.size() - str_digits.size() == 3) && (val_str.substr(abbre_pos, 3) == "Meg"))
    {
        return stof(str_digits)*1000000;
    }
    if ((val_str.size() - str_digits.size() == 1) && (val_str[abbre_pos] == 'm'))
    {
        return stof(str_digits)/1000;
    }
    
    // Failure to perform any conversion
    std::cerr << "Error. Failed to perform any form of conversion." << std::endl;
    assert(0);
}

int GetNode (std::string& node)
{
    // Check if node is grounded represented as '0'
    if (tolower(node[0]) != 'n') {return stoi(node);}

    else if (tolower(node[0]) == 'n') {return stoi(node.erase(0,1));}

    else {std::cerr << "Wrong node input format." << std::endl; assert(0);}
};