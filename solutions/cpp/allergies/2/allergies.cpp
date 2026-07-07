#include "allergies.h"

namespace allergies {

    // TODO: add your solution here
    
    // Binary
    //128| 64 | 32 | 16 | 8 | 4 | 2 | 1 |
    // ↓ | ↓  | ↓  | ↓  | ↓ | ↓ | ↓ | ↓ |
    // 0 | 0  | 1  | 0  | 0 | 0 | 1 | 0 |  32 + 2 = 34

    //Example: 
    // 0 | 0  | 1  | 0  | 0 | 0 | 1 | 0 |  score = 34
    // 0 | 0  | 0  | 0  | 0 | 0 | 1 | 0 |  food = peanut (2)
    // AND --------------------------------------------------
    // 0 | 0  | 0  | 0  | 0 | 0 | 1 | 0 |  produced 1 in peanut slot = allergic to peanut (0 = no allergic)


    allergy_test::allergy_test(int score)
        : score {score} { }

    // Compares the score against the food's bit value using AND.
    // If the result is non-zero, the person is allergic.
    bool allergy_test::is_allergic_to(const std::string& food) const
    {
        auto it = allergy_values.find(food); //returns iterator pointing to food 

        if (it == allergy_values.end()) //searched entire map & didn't find value
            return false;
        
        return (score & it->second) != 0; //is this allergen's bit set in the score?
    }

    // Checks each allergen's bit against the score; any non-zero result means allergic.
    std::unordered_set<std::string> allergy_test::get_allergies()
    {
        std::unordered_set<std::string> result;
        result.reserve(allergy_values.size()); //specifiy size so container doesn't resize
    
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
