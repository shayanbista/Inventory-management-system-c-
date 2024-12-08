#include <iostream>
#include <algorithm>
#include <cmath> 

#include "Organization.h"
#include "Product.h"
#include "Supplier.h"  




void Organization::addProduct(Product* product) {
    if (!product) {
        throw invalid_argument("Empty product cant be added"); 
    }

    bool productExists = find_if(products.begin(), products.end(),
        [product](Product* p) { return p->productID == product->productID; }) != products.end();

    if (!productExists) {
        products.push_back(product);
        product->organization = shared_from_this();

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


void Organization::addSubscriber(shared_ptr<Supplier> supplier) {
    if (!supplier) {
        throw invalid_argument("Cannot add null supplier");
    }

    // Check if supplier already exists
    auto it = find_if(subscribers.begin(), subscribers.end(),
        [&supplier](const shared_ptr<Supplier>& existing) {
            return existing == supplier;
        });

    if (it == subscribers.end()) {
        subscribers.push_back(supplier);
        cout << "Supplier added successfully" << endl;
    } else {
        cout << "This supplier is already subscribed to the organization" << endl;
    }
}


void Organization::notifySuppliers(Product* product) {
    for (auto it = subscribers.begin(); it != subscribers.end(); ++it) {
        (*it)->notifyRestock(product->productID, abs(product->stockLevel - product->reorderThreshold));
    }
}


void Organization::displayInventory() {

    for(auto &product:products){
        cout << "Product ID: " << product->productID << endl;
        cout << "Product Name: " << product->productName << endl;
        cout << "Category: " << product->category << endl;
        cout << "Price: " << product->price << endl;
        cout << "Stock Level: " << product->stockLevel << endl;
        cout << "Reorder Threshold: " << product->reorderThreshold << endl;
        cout << "---------------------------" << endl;  
    }
}

void Organization::generateReport() {

  for (auto &product:products){

                cout<<"----------------------------------------------------------"<<endl;
                cout << "Product ID: " << product->productID << endl;
                cout << "Product Name: " << product->productName << endl;
                cout << "Category: " << product->category << endl;
                cout << "Stock Level: " << product->stockLevel << endl;
                cout << "Threshold: " << product->reorderThreshold << endl;
                cout<<"----------------------------------------------------------"<<endl;
  }


}