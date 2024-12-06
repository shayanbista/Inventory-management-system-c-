#include <iostream>
#include "Organization.h"
#include "Product.h"
#include <algorithm>


void Organization::addProduct(Product* product) {
    if (!product) {
        std::cout << "Error: Cannot add null product" << std::endl;
        return;
    }

    bool productExists = find_if(products.begin(), products.end(),
        [product](Product* p) { return p->productID == product->productID; }) != products.end();

    if (!productExists) {

            products.push_back(product);
            cout << "Product added successfully: ID " << product->productID << std::endl;      
    }

    cout << "Product with ID " << product->productID << " already exists" << std::endl;
    return;

}

void Organization::removeProduct(int *productID) {

    auto id=find_if(products.begin(),products.end(),[productID](Product* p) {return p -> productID ==*productID;});

     if(id == products.end()) {
        throw invalid_argument("Product ID " + to_string(*productID) + " doesn't exist");
    }

    cout << "Product with ID " << *productID << " has been removed." << endl;

    products.erase(id); 

    cout<<"products"<<products<<endl;
    
}

