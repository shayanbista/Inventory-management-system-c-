#include <iostream>
#include "Product.h"  
#include "Organization.h"

int main() {
    try {

        Product p1(101, "Product1", "Category1", 29.99, 50, 10);  
        Product p2(104, "Product1", "Category1", 29.99, 50, 10); 
        Product p3(105, "Product2", "Category1", 29.99, 50, 10); 

        Organization o1;
        o1.addProduct(&p1);
        o1.addProduct(&p2);
        o1.addProduct(&p3);

        o1.searchProduct(&p3.productID,nullptr);
        o1.displayInventory();

    } catch (const std::invalid_argument& e) {
        cerr << e.what() << std::endl;
    }

    return 0;
}
