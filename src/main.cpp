#include <iostream>
#include "Product.h"  

int main() {
    try {

        Product p1(101, "Product1", "Category1", 29.99, 50, 10);  
        Product p2(104, "Product1", "Category1", 29.99, 50, 10); 
        p1.updateStockLevel(45);
        cout<<p1.checkReorderThreshold()<<endl;

    } catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}