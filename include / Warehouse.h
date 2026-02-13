#pragma once
#include <string>
#include <vector>
#include "Product.h"

class Warehouse {
private:
    std::vector<std::string, Product> catalog; // productId -> Product

public:
    Warehouse() = default;

    bool addProduct(const Product& product);
    Product* findProduct(const std::string& productId);
    void generateInventoryReport() const;

    bool sellProduct(const std::string& productId, int quantity);
    bool restockProduct(const std::string& productId, int quantity);
    size_t getProductCount() const { return catalog.size(); }
};
