#pragma once

#include <string> 
#include <unordered_map>
#include <unordered_set>

namespace allergies {

// TODO: add your solution here
    class allergy_test{
    
            int score {};
            static const std::unordered_map<std::string, int> allergy_values;

        public:
            allergy_test(int score);
            bool is_allergic_to(const std::string&  food) const;
            std::unordered_set<std::string> get_allergies();
    };

}  // namespace allergies
