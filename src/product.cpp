#include <iostream>
#include "Product.h"


set<int> Product::existingIds;


Product::Product(int productID, string productName, string category, double price, int stockLevel, int reorderThreshold)
    : productID(productID), productName(productName), category(category), price(price), stocklevel(stockLevel), reorderThreshold(reorderThreshold) {
        checkExistingId(productID);
        existingIds.insert(productID);
}


void Product::checkExistingId(int productID) {
    if (existingIds.find(productID) != existingIds.end()) {
        throw invalid_argument("Product ID " + to_string(productID) + " already exists");
    }
}

void Product::updateStockLevel(int purchasedLevel) {
   stocklevel -= purchasedLevel;  
}

bool Product::checkReorderThreshold() {
    return stocklevel < reorderThreshold;
}