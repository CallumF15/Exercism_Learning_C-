#include "kindergarten_garden.h"
#include <stdexcept>
#include <algorithm>

namespace kindergarten_garden {

// TODO: add your solution here

    Plants letter_to_plant(char c)
    {
        switch (c)
            {
                case 'C': return Plants::clover;
                case 'G': return Plants::grass;
                case 'R': return Plants::radishes;
                case 'V': return Plants::violets;
                default:  throw std::invalid_argument("invalid plant code");
            }
    }

    std::array<Plants, 4> plants(std::string_view diagram, std::string_view student)
    {
        static constexpr std::array<std::string_view, 12> students{
            "Alice", "Bob", "Charlie", "David", "Eve", "Fred",
            "Ginny", "Harriet", "Ileana", "Joseph", "Kincaid", "Larry"
        };

        auto it = std::find(students.begin(), students.end(), student);

        if (it != students.end())
        {
            auto index = std::distance(students.begin(), it);

            auto newlinePos = diagram.find('\n');
            std::string_view row1 = diagram.substr(0, newlinePos);
            std::string_view row2 = diagram.substr(newlinePos + 1);
    
            std::size_t start = static_cast<std::size_t>(index) * 2; // multply index by number of plants per row
    
            return {
                letter_to_plant(row1[start]),      //(Alice (index = 0) -> 0) || Bob (index = 1) -> 2 
                letter_to_plant(row1[start + 1]),  //    ( +1 -> 1)           || +1 -> 3
                letter_to_plant(row2[start]),
                letter_to_plant(row2[start + 1])
            };
        }else
             throw std::runtime_error("Student not found");
    }



}  // namespace kindergarten_garden
