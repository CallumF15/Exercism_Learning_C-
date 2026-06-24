#include <string>
#include <cmath>
#include <algorithm>

namespace log_line 
{
    std::string GetFirstSegment(std::string& line, char delimiter)
    {
        std::size_t pos = line.find(delimiter); //Use delimiter 
        return line.substr(pos + 1); //get the text after delimiter
    }

    std::string GetTextInBrackets(std::string& line)
    {
        size_t start = line.find('[');
        size_t end = line.find(']');
        return line.substr(start + 1, end - start - 1); //get text between brackets
    }

    std::string TrimWhiteSpace(std::string& Segment)
    {
        size_t position = Segment.find_first_not_of(" \t\n\r\f\v"); //find first char that is not whitespace
        std::string trimmed = (position == std::string::npos) //no white space found
                                ? "" : Segment.substr(position); // return first string

        return trimmed;
    }
    
    std::string message(std::string line) 
    {
        // return the message
        std::string Segment = GetFirstSegment(line, ':');
        return TrimWhiteSpace(Segment);
    }
    
    std::string log_level(std::string line) {
        // return the log level
        size_t start = line.find('[');
        size_t end = line.find(']');
        std::string Segment = line.substr(start + 1, end - start - 1); //get text between brackets

        std::transform(Segment.begin(), Segment.end(), Segment.begin(),
              ::toupper);

        return Segment;
    }
    
    std::string reformat(std::string line) 
    {
        // return the reformatted message
        std::string firstSegment = GetFirstSegment(line, ':');
        std::string errorText = GetTextInBrackets(line);
        firstSegment = TrimWhiteSpace(firstSegment);
        
        std::string word = firstSegment + " " + "(" + errorText + ")";
        return word;
    }

  


}  // namespace log_line
