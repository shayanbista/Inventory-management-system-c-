#include <iostream>
#include "Organization.h"
#include "Product.h"
#include <algorithm>


void Organization::addProduct(Product* product) {
    if (!product) {
        throw invalid_argument("Empty product cant be added"); 
    }

    bool productExists = find_if(products.begin(), products.end(),
        [product](Product* p) { return p->productID == product->productID; }) != products.end();

    if (!productExists) {
        products.push_back(product);
        cout << "Product added successfully: ID " << product->productID << endl;      
    }

    cout << "Product with ID " << product->productID << " already exists" << endl;
    return;

}

void Organization::removeProduct(int *productID) {

    auto id=find_if(products.begin(),products.end(),[productID](Product* p) {return p -> productID ==*productID;});

     if(id == products.end()) {
        throw invalid_argument("Product ID " + to_string(*productID) + " doesn't exist");
    }

    cout << "Product with ID " << *productID << " has been removed." << endl;

    products.erase(id); 
}

void Organization::searchProduct(int *productID, string *productName) {
    bool found = false;

    if (productID && *productID != -1) {
        auto searchedProduct = find_if(products.begin(), products.end(),
            [productID](Product* p) { return p->productID == *productID; });

        if (searchedProduct != products.end()) {
            cout << "Product found by ID!" << endl;
            cout << "Product ID: " << (*searchedProduct)->productID << endl;
            cout << "Product Name: " << (*searchedProduct)->productName << endl;
            cout << "Category: " << (*searchedProduct)->category << endl;
            cout << "Stock Level: " << (*searchedProduct)->stockLevel << endl;
            cout << "Threshold: " << (*searchedProduct)->reorderThreshold << endl;
            found = true;
        } else {
            cout << "Product with ID " << *productID << " doesn't exist." << endl;
        }
    }

    if (productName && !productName->empty()) {
      
        for (auto& product : products) {
            if (product->productName == *productName) {
                cout << "Product found by Name!" << endl;
                cout << "Product ID: " << product->productID << endl;
                cout << "Product Name: " << product->productName << endl;
                cout << "Category: " << product->category << endl;
                cout << "Stock Level: " << product->stockLevel << endl;
                cout << "Threshold: " << product->reorderThreshold << endl;
                found = true;
            }
        }

        if (!found) {
            cout << "No products found with Name " << *productName << endl;
        }
    }

    if (!productID && !productName) {
        throw invalid_argument("Either Product ID or Name must be provided.");
    }

    if (!found) {
        cout << "No product found with the given ID or Name." << endl;
    }
}
