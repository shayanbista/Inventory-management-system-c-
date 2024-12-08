// #include <iostream>
// #include "Product.h"  
// #include "Organization.h"
// #include "Supplier.h"
// #include <memory>


// int main() {
//     // Create a shared_ptr for Organization with proper initialization
//     auto o1 = std::make_shared<Organization>();

//     Product p1(101, "Product1", "Category1", 29.99, 50, 10);  
//     Product p2(104, "Product1", "Category1", 29.99, 50, 10); 
//     Product p3(105, "Product2", "Category1", 29.99, 50, 10); 

//     // Use -> operator since o1 is a shared_ptr
//     o1->addProduct(&p1);
//     o1->addProduct(&p2);
//     o1->addProduct(&p3);

//     LocalSupplier localSupplier("Local Supplier");
//     GlobalSupplier globalSupplier("Global Supplier");

//     // Subscribe to the organization using shared_ptr
//     localSupplier.subscribeToOrganization(o1);

//     return 0;
// }





// // using namespace std;

// // int main() {
// //     try {

// //         Product p1(101, "Product1", "Category1", 29.99, 50, 10);  
// //         Product p2(104, "Product1", "Category1", 29.99, 50, 10); 
// //         Product p3(105, "Product2", "Category1", 29.99, 50, 10); 

// //         // Organization o1;
// //         // o1.addProduct(&p1);
// //         // o1.addProduct(&p2);
// //         // o1.addProduct(&p3);

// //         auto o1 = std::make_shared<Organization>;

// //         o1.addProduct(&p1);
// //         o1.addProduct(&p2);
// //         o1.addProduct(&p3);

// //         // o1.searchProduct(&p3.productID,nullptr);
// //         // o1.displayInventory();

// //         // LocalSupplier  localSupplier("Local Supplier");
// //         // GlobalSupplier globalSupplier("Global Supplier");
// //         // localSupplier.subscribeToOrganization(&o1);




        

// //     } catch (const std::invalid_argument& e) {
// //         cerr << e.what() << endl;
// //     }

// //     return 0;
// // }


#include <iostream>
#include "Product.h"  
#include "Organization.h"
#include "Supplier.h"
#include <memory>

int main() {
    // Create shared_ptr for Organization
    auto o1 = std::make_shared<Organization>();

    Product p1(101, "Product1", "Category1", 29.99, 50, 10);  
    Product p2(104, "Product1", "Category1", 29.99, 50, 10); 
    Product p3(105, "Product2", "Category1", 29.99, 50, 10); 

    o1->addProduct(&p1);
    o1->addProduct(&p2);
    o1->addProduct(&p3);

    // Create suppliers using make_shared
    auto localSupplier = std::make_shared<LocalSupplier>("Local Supplier");
    auto globalSupplier = std::make_shared<GlobalSupplier>("Global Supplier");

    // Subscribe to the organization
    localSupplier->subscribeToOrganization(o1);
    globalSupplier->subscribeToOrganization(o1);
    localSupplier->subscribeToOrganization(o1);


    return 0;
}



