#include "Parser.hpp"

std::vector<std::string> tokeniser (std::string input)
{

    // Remove '(' char
    replace(input.begin(), input.end(), '(', ' ');

    // Remove ')' char
    input.erase(std::remove(input.begin(), input.end(), ')'), input.end());

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

float converter(std::string val_str)
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
        }
        
        if (str_digits.size() == 0)
        {
            return 0;
        }
        else
        {
            return std::stof(str_digits);
        }
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
    return digits;
}

void parser(std::istream& cin, std::vector<CirElement>& circuit, std::vector<CirSrc>& sources)
{
    CirElement x;
    CirSrc y;
    std::vector<std::string> store;
    std::string line;
    bool firsttime = true;

    while (std::getline(std::cin, line))
    {
        // Check for beginning TITLE
        if (firsttime)
        {
            firsttime = false;
            continue;
        }

        // Check for .end
        if (line == ".end")
        {
            break;
        }
        
        //Tokenise
        store = tokeniser(line);

        // Get circuit element name
        // If R, C, L then proceed normal
        if (tolower(store[0][0]) == 'r' || tolower(store[0][0]) == 'c' || tolower(store[0][0]) == 'l')
        {
            // Store the element and description
            x.D = store[0][0];
            store[0].erase(store[0].begin() + 0);
            x.descrip = store[0];

            // Get nodes in the format "n1", "n2", etc
            // Remove 'N' char from string
            x.n1 = stoi(store[1].erase(0,1));
            x.n2 = stoi(store[2].erase(0,1));

            // Detect and get values. Must have values
            if (store.size() < 3)
            {
                std::cerr << "No values entered." << std::endl;
            }
            std::string values;
            values = store[3];

            // Ensure all digits
            //assert(is_digit(values));
            x.value = converter(values);

            // Push into vector representing circuit inputted
            circuit.push_back(x);
        }

        // If V or I then call Src resolver
        else if (tolower(store[0][0]) == 'v' || tolower(store[0][0]) == 'i')
        {
            // Store the element and description
            y.D = store[0][0];
            store[0].erase(store[0].begin() + 0);
            y.descrip = store[0];

            // Get nodes in the format "n1", "n2", etc
            // Remove 'N' char from string
            y.n1 = stoi(store[1].erase(0,1));
            y.n2 = stoi(store[2].erase(0,1));

            if (store[3] != "SINE") // Case of DC input
            {
                // Detect and get values. Must have values
                if (store.size() < 3)
                {
                    std::cerr << "No values entered." << std::endl;
                    exit;
                }

                // Ensure all digits
                //assert(is_digit(values));
                y.type = "DC";
                y.DC = converter(store[3]);
                y.A = 0;
                y.freq = 0;

                // Push into sources vector
                sources.push_back(y);
            }
            else if (store[3] == "SINE")
            {
                // Ensure all digits
                //assert(is_digit(values));
                y.type = "SINE";
                y.DC = converter(store[4]);
                y.A = converter(store[5]);
                y.freq = converter(store[6]);

                // Push into sources vector
                sources.push_back(y);
            }
            else
            {
                std::cerr << "Source type recognised." << std::endl;
                exit;
            }
        }
        else
        {
            //std::cout << buf[0] << std::endl;
            std::cerr << "Unknown element" << std::endl;
            exit;
        }
        store.clear();
    }
}

int N_int(std::vector<CirElement> circuit)
{
     return circuit.size();
}

int M_int(std::vector<CirSrc> sources)
{
    return sources.size();
}
