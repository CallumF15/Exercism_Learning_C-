#pragma once

#include <vector>
#include <string>

namespace lasagna_master {

struct amount {
    int noodles;
    double sauce;
};

int preparationTime(std::vector<std::string>& layers, int prepTime = 2);
amount quantities(std::vector<std::string>& layers);
    
void addSecretIngredient(std::vector<std::string>& myList, const std::vector<std::string>& friendList);
void addSecretIngredient(std::vector<std::string>& myList, const std::string& auntiesSecret);
    
std::vector<double> scaleRecipe(std::vector<double> quantities, int portionQuantity);

}  // namespace lasagna_master
