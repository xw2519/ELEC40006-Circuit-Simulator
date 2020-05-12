#include "Parser_module.hpp"
#include <cmath>
#include <assert.h>
#include <regex>


std::vector<std::string> tokeniser (std::string input)
{
    // Regex for tokenizing whitespaces
    std::regex reg("\\s+");
 
    // Get an iterator after filtering through the regex
    std::sregex_token_iterator iter(input.begin(), input.end(), reg, -1);
    // Keep a dummy end iterator - Needed to construct a vector
    // using (start, end) iterators.
    std::sregex_token_iterator end;
 
    std::vector<std::string> vec(iter, end);

    return vec;
}

bool is_digit(const std::string& input)
{
    std::string::const_iterator it = input.begin();
    while (it != input.end() && std::isdigit(*it) || it != input.end() && (*it=='.')) ++it;
    return !input.empty() && it == input.end();
}

float custom_pow(std::string val_str)
{
    float digits;
    // Check if there are any abbreviations
    size_t abbre_pos = val_str.find_first_of("fpnumkMGT");

    if (abbre_pos==std::string::npos)
    {
        // No recognised abbreviation, extract digits
        std::string str_digits;
        for (char const &c: val_str)
        {
            if (isdigit(c))
            {
                str_digits = str_digits + c;
            }
            return std::stof(str_digits);
        }
        return 0;
    }

    // A recognised abbreviation detected
    std::string str_digits = val_str.substr(0, (abbre_pos));

    digits = stof(str_digits);
    switch (val_str[abbre_pos])
    {
    case 'f':
        digits = digits/pow(10, 15);
        break;
    case 'p':
        digits = digits/pow(10, 12);
        break;
    case 'n':
        digits = digits/pow(10, 9);
        break;
    case 'u':
        digits = digits/pow(10, 6);
        break;
    case 'm':
        digits = digits/pow(10, 3);
        break;
    case 'k':
        digits = digits*1000;
        break;
    case 'M':
        digits = digits*1000000;
        break;
    case 'G':
        digits = digits*1000000000;
        break;
    case 'T':
        digits = digits*1000000000000;
        break;
    default:
        break;
    }
    val_str.erase(0, abbre_pos+1);

    // Recursion to cover the rest of the string
    return digits + custom_pow(val_str);
}

std::vector<CirElement> parser(std::istream& cin)
{
    CirElement x;
    std::vector<CirElement> circuit;
    std::vector<std::string> store;
    std::string line;
    bool firsttime = true;

    while (std::getline(std::cin, line)){

    // Skip first line as it is the title
    if (firsttime)
    {
        firsttime = false;
        continue;
    }
    
    // Check if end of the line 
    if (line == ".END")
    {
        break;
    }
    
    //Tokenise
    store = tokeniser(line);

    // Get circuit element name
    if (tolower(store[0][0]) == 'r' || tolower(store[0][0]) == 'c' || tolower(store[0][0]) == 'l' || tolower(store[0][0]) == 'v' || tolower(store[0][0]) == 'i')
    {
        //std::cout << "got ehre" << std::endl;
        x.D = store[0][0];
        store[0].erase(store[0].begin() + 0);
        x.descrip = store[0];
    }
    else
    {
        //std::cout << buf[0] << std::endl;
        std::cerr << "Unknown element" << std::endl;
        exit;
    }
    
    // Get nodes
    x.n1 = store[1];
    x.n2 = store[2];
    
    // Detect and get values. Must have values
    if (store.size() < 3)
    {
        std::cerr << "No values entered." << std::endl;
    }
    std::string values;
    values = store[3];

    // Ensure all digits
    //assert(is_digit(values));
    x.value = custom_pow(values);

    // Detect if optional entry is entered otherwise default to 0
    if (store.size()!=4)
    {
        x.initval = stof(store[4]);
    }
    else
    {
        x.initval = 0;
    }
    
    // Push into vector representing circuit inputted
    circuit.push_back(x);
    }
    return circuit;
}

