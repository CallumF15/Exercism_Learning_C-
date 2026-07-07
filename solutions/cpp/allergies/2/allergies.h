#pragma once

#include <string> 
#include <unordered_map>
#include <unordered_set>

namespace allergies {

// TODO: add your solution here
    class allergy_test{
    
            int score {};
            static inline const std::unordered_map<std::string, int> allergy_values {
                {"eggs", 1},
                {"peanuts", 2},
                {"shellfish", 4},
                {"strawberries", 8},
                {"tomatoes", 16},
                {"chocolate", 32},
                {"pollen", 64},
                {"cats", 128}
            };

        public:
            allergy_test(int score);
            bool is_allergic_to(const std::string&  food) const;
            std::unordered_set<std::string> get_allergies();
    };

}  // namespace allergies
