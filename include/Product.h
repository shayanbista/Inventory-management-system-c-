#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <set>
#include <memory>

class Organization;

using namespace std;

class Product {

public:
    static set<int> existingIds;  
    int productID;
    string productName;
    string category;
    double price;
    int stockLevel;
    int reorderThreshold;


    shared_ptr<Organization> organization;

    Product(int productID, string productName, string category, double price, int stockLevel, int reorderThreshold);
    static void checkExistingId(int productID);  
    void updateStockLevel(int purchasedLevel);
    bool checkReorderThreshold();
    void setStockLevel(int newStockLevel);
};



#endif
