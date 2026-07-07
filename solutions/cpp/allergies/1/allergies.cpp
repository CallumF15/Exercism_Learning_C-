#include "allergies.h"

namespace allergies {

     // Binary
     //128| 64 | 32 | 16 | 8 | 4 | 2 | 1 |
     // ↓ | ↓  | ↓  | ↓  | ↓ | ↓ | ↓ | ↓ |
     // 0 | 0  | 1  | 0  | 0 | 0 | 1 | 0 |  32 + 2

    //Example: 
    // 0 | 0  | 1  | 0  | 0 | 0 | 1 | 0 |  score = 34
    // 0 | 0  | 0  | 0  | 0 | 0 | 1 | 0 |  food = peanut (2)
    // AND --------------------------------------------------
    // 0 | 0  | 0  | 0  | 0 | 0 | 1 | 0 |  produced 1 in peanut slot = allergic to peanut (0 = no allergic)

    const std::unordered_map<std::string, int> allergy_test::allergy_values {
        {"eggs", 1},
        {"peanuts", 2},
        {"shellfish", 4},
        {"strawberries", 8},
        {"tomatoes", 16},
        {"chocolate", 32},
        {"pollen", 64},
        {"cats", 128}
    };

// TODO: add your solution here
    allergy_test::allergy_test(int score)
        : score {score}
    {   
    }

    // Compares the score against the food's bit value using AND.
    // If the result is non-zero, the person is allergic.
    bool allergy_test::is_allergic_to(const std::string& food) const
    {
        auto it = allergy_values.find(food); //returns iterator pointing to food 

        if (it == allergy_values.end()) //searched entire map & didn't find value
            return false;
        
        return (score & it->second) != 0; //second allows access to value in key/value pair 
    }

    //Compares persons score to all foods and cross checks if any values yield 1 and adds to list if they are allergic
    std::unordered_set<std::string> allergy_test::get_allergies()
    {
        std::unordered_set<std::string> result;
    
        for (const auto& [food, value] : allergy_values)
        {
            if (score & value) //is the person allergic? 
            {
                result.emplace(food);
            }
        }
    
        return result;
    }


}  // namespace allergies
