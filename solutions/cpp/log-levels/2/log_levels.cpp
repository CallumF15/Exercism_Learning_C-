#include <string>
#include <cmath>
#include <algorithm>

namespace log_line 
{
    std::string message(std::string line) 
    {
        return line.substr(line.find(' ') + 1); //get the text after empty space
    }
    
    std::string log_level(std::string line) 
    {
        return line.substr(1, line.find(']') - 1); //get text between brackets [1 -> first letter | -1 -> last letter]
    }
    
    std::string reformat(std::string line) 
    {
        return message(line) + " (" + log_level(line) + ")";  
    }
}  // namespace log_line
