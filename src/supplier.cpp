#include "Supplier.h"
#include "Organization.h"


#include <iostream>
#include <algorithm>


void Supplier::subscribeToOrganization(shared_ptr<Organization> org) {
    organization = org; 
    organization->addSubscriber(shared_from_this());  
}

LocalSupplier::LocalSupplier(const string supplierName) : name(supplierName) {};


void LocalSupplier:: LocalSupplier::notifyRestock(int productID, int quantity) {
    cout << "hey Local restocking of the product is required , productID:"<< productID<< " "<< "quantity"<<" "<< quantity<< endl;
}

GlobalSupplier::GlobalSupplier(const string supplierName): name(supplierName) {};

void GlobalSupplier::notifyRestock(int productID, int quantity) {
    cout << "hey Global restocking of the product is required, productID:"<<productID<< " "<< "quantity"<<" "<< quantity<< endl;
}
