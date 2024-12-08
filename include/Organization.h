#ifndef Organization_H
#define Organization_H

#include <string>
#include <vector>
#include <list>
#include <memory>

using namespace std;


class Product;  
class Supplier; 



class Organization: public enable_shared_from_this<Organization> {
private:
    list<Product*> products = {};
    list<shared_ptr<Supplier>> subscribers;

public:
    void addProduct(Product* product);
    void removeProduct(int* productId);
    void searchProduct(int* productID, string* productName);
    void displayInventory();
    void addSubscriber(shared_ptr<Supplier> supplier);
    void notifySuppliers(Product* product);
    void generateReport();
};

#endif 