#include "Product.h"
#include <iostream>
#include <stdexcept>

#include "Organization.h"

set<int> Product::existingIds;  


Product::Product(int productID, string productName, string category, double price, int stockLevel, int reorderThreshold)
    : productID(productID), productName(productName), category(category), price(price), stockLevel(stockLevel), reorderThreshold(reorderThreshold), organization(nullptr) {
    checkExistingId(productID);  
    existingIds.insert(productID);  
}

void Product::checkExistingId(int productID) {
    if (existingIds.find(productID) != existingIds.end()) {
        throw invalid_argument("Product ID " + to_string(productID) + " already exists.");
    }
}

void Product::setStockLevel(int newStockLevel) {
        if (newStockLevel < 0) {
            throw invalid_argument("Stock level cannot be negative.");
        }

        stockLevel = newStockLevel;
        cout << "Stock level updated to " << stockLevel << " for Product ID " << productID << "." << endl;

        
        if (organization != nullptr) {
            organization->notifySuppliers(this);
            cout << "Notification sent to organization." << endl;
        } else {
            cout << "Organization is nullptr." << endl;
        }
    }


void Product::updateStockLevel(int purchasedLevel) {
    if (purchasedLevel <= 0) {
        throw invalid_argument("Purchased level must be positive.");
    }

    if (purchasedLevel > stockLevel) {
        throw invalid_argument("Stock limit is reached.");
    }

    stockLevel -= purchasedLevel;
    cout << "Stock level updated to " << stockLevel << " for Product ID " << productID << "." << endl;


    if (organization != nullptr) {
    organization->notifySuppliers(this); 
    cout<<"pointer is not null."<<endl;
    }

    else{
        cout<<"Organization is nullptr"<<endl;
    }

}


bool Product::checkReorderThreshold() {
    return stockLevel < reorderThreshold;
}

