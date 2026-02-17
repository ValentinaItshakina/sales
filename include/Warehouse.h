#pragma once
#include <string>
#include <vector>
#include "Product.h"

class Warehouse {
    std::vector<Product> catalog;

public:
    Warehouse() = default;

    void addProduct(const Product& product);
    Product* findProduct(const std::string& productId);
    void generateInventoryReport() const;
};
