#include <iostream>
#include "Product.h"  
#include "Organization.h"
#include "Supplier.h"
#include <memory>

int main() {

    auto o1 = make_shared<Organization>();

    Product p1(101, "Product1", "Category1", 29.99, 50, 10); 
    Product p2(104, "Product1", "Category1", 29.99, 50, 10); 
    Product p3(105, "Product2", "Category1", 29.99, 50, 10); 


    o1->addProduct(&p1);
    o1->addProduct(&p2);
    o1->addProduct(&p3);

   
    auto localSupplier = make_shared<LocalSupplier>("Local Supplier");
    auto globalSupplier = make_shared<GlobalSupplier>("Global Supplier");
    auto globalSupplier1 = make_shared<GlobalSupplier>("Global Supplier");

 
    localSupplier->subscribeToOrganization(o1);
    globalSupplier->subscribeToOrganization(o1);
    localSupplier->subscribeToOrganization(o1);

    // p1.updateStockLevel(41);
    p1.setStockLevel(1);
    o1->generateReport();


    return 0;
}



