
#include "lasagna_master.h"
#include <vector>
#include <string>

namespace lasagna_master 
{
   int preparationTime(std::vector<std::string>& layers, int prepTime)
    {
        int total_layers = layers.size();
        return total_layers * prepTime;
    };

    amount quantities(std::vector<std::string>& layers)
    {
        amount result{0,0};
        
        for(auto& layer : layers)
        {
            if(layer == "noodles")
                result.noodles += 50;

            if(layer == "sauce")
                result.sauce += 0.2;
        }

        return result;
    };

    void addSecretIngredient(std::vector<std::string>& myList, const std::vector<std::string>& friendList)
    {
         myList.back() = friendList.back();
    }

    void addSecretIngredient(std::vector<std::string>& myList, const std::string& auntiesSecret)
    {
        myList.back() = auntiesSecret;
    }

    std::vector<double> scaleRecipe(std::vector<double> quantities, int portions)
    {
        for(auto& amount : quantities)
        {
            amount *= portions / 2.0;
        }

        return quantities;
    }
}