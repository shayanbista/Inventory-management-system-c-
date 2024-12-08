#include "Supplier.h"
#include <iostream>
#include <algorithm>

void Supplier::subscribeToOrganization(shared_ptr<Organization> organization) {
    auto it = find_if(subscribedOrganizations.begin(), subscribedOrganizations.end(),
        [&organization](const shared_ptr<Organization>& org) {
            return org == organization; 
        });

    if (it == subscribedOrganizations.end()) {
        subscribedOrganizations.push_back(organization);
        cout << "Supplier subscribed to organization." << endl;
    } else {
        cout << "Supplier is already subscribed to this organization." << endl;
    }
}

LocalSupplier::LocalSupplier(const string& supplierName) {
    cout<<"supplierName: "<< supplierName;
}

void LocalSupplier:: LocalSupplier::notifyRestock(int productID, int quantity) {
    cout << "Local Supplier notified: Restock Product"<< endl;
}

GlobalSupplier::GlobalSupplier(const string& supplierName) {
    cout<<"supplierName: "<< supplierName;
}

void GlobalSupplier::notifyRestock(int productID, int quantity) {
    cout << "Global Supplier notified: Restock Product"<<endl;
}
