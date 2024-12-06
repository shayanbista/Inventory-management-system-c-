#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <set>

using namespace std;

class Product{

    public:
        Product(int productID, string productName, string category, double price, int stockLevel, int reorderThreshold);
       
        void updateStockLevel(int purchasedLevel);
        bool checkReorderThreshold();

    private:
        static set<int> existingIds;
        int productID;
        string productName;
        string category;
        double price;
        int stocklevel;
        int reorderThreshold;

        static void checkExistingId(int productID);
};

#endif  