#pragma once

#include <array>
#include <string_view>

namespace kindergarten_garden {

// TODO: add your solution here

enum Plants{
    grass,
    clover,
    radishes,
    violets
};

Plants letter_to_plants(char& c);
std::array<Plants, 4> plants(std::string_view diagram, std::string_view student);


}  // namespace kindergarten_garden
