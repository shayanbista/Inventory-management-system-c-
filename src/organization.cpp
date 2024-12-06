#include <iostream>
#include "Organization.h"
#include "Product.h"
#include <algorithm>


void Organization::addProduct(Product* product) {
    if (!product) {
        std::cout << "Error: Cannot add null product" << std::endl;
        return;
    }

    bool product_exists = find_if(products.begin(), products.end(),
        [product](Product* p) { return p->productID == product->productID; }) != products.end();

    if (!product_exists) {

            products.push_back(product);
            cout << "Product added successfully: ID " << product->productID << std::endl;      
    }

    cout << "Product with ID " << product->productID << " already exists" << std::endl;
    return;

}