#ifndef SUPPLIER_H
#define SUPPLIER_H

#include <memory>
#include <string>
#include <list>

#include "Organization.h"  


using namespace std;

// Abstract Supplier class
class Supplier : public enable_shared_from_this<Supplier> {
protected:
    shared_ptr<Organization> organization;

public:
    virtual ~Supplier() = default;
    virtual void notifyRestock(int productID, int quantity) = 0;
    void subscribeToOrganization(shared_ptr<Organization> organization);
};

class LocalSupplier : public Supplier {
private:
    string name;
public:
    LocalSupplier(const string supplierName);
    void notifyRestock(int productID, int quantity) override;
};

class GlobalSupplier : public Supplier {
private:
    string name;
public:
    GlobalSupplier(const string supplierName);
    void notifyRestock(int productID, int quantity) override;
};

#endif
