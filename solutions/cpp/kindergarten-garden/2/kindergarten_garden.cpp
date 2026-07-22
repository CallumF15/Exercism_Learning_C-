#include "kindergarten_garden.h"
#include <stdexcept>
#include <algorithm>

namespace kindergarten_garden {

// TODO: add your solution here

    std::array<Plants, 4> plants(std::string_view diagram, std::string_view student)
    {
        static constexpr std::array<std::string_view, 12> students{
            "Alice", "Bob", "Charlie", "David", "Eve", "Fred",
            "Ginny", "Harriet", "Ileana", "Joseph", "Kincaid", "Larry"
        };

        auto it = std::find(students.begin(), students.end(), student);

        if (it == students.end())
            throw std::runtime_error("Student not found");

        auto index = std::distance(students.begin(), it);
        auto newlinePos = diagram.find('\n');

        if (newlinePos == std::string_view::npos) //Did the search fail to find a newline
            throw std::runtime_error("Invalid diagram");
        
        std::string_view row1 = diagram.substr(0, newlinePos);
        std::string_view row2 = diagram.substr(newlinePos + 1);

        std::size_t start = static_cast<std::size_t>(index) * 2;  //multiply the student index by the number of plants assigned to each student
       

        return {
            static_cast<Plants>(row1[start]),
            static_cast<Plants>(row1[start + 1]),
            static_cast<Plants>(row2[start]),
            static_cast<Plants>(row2[start + 1])
        };
    }
}  // namespace kindergarten_garden
