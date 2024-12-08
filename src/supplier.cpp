#include "Supplier.h"
#include "Organization.h"


#include <iostream>
#include <algorithm>


void Supplier::subscribeToOrganization(std::shared_ptr<Organization> org) {
    organization = org; 
    organization->addSubscriber(shared_from_this());  
}

LocalSupplier::LocalSupplier(const string supplierName) : name(supplierName) {};


void LocalSupplier:: LocalSupplier::notifyRestock(int productID, int quantity) {
    cout << "Local Supplier notified: Restock Product"<< endl;
}

GlobalSupplier::GlobalSupplier(const string supplierName): name(supplierName) {};

void GlobalSupplier::notifyRestock(int productID, int quantity) {
    cout<<"name"<<name<<endl;
    cout << "Global Supplier notified: Restock Product"<<endl;
}
