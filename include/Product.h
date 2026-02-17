#pragma once
#include <string>

class Product {
    std::string productId;
    std::string name;
    double price;
    int quantityInStock;

public:
    Product(std::string id, std::string n, double p, int q)
        : productId(id), name(n), price(p), quantityInStock(q) {}

    void restock(int quantity);
    void sell(int quantity);
    bool isAvailable() const;

    std::string getId() const;
    std::string getName() const;
    double getPrice() const;
    int getQuantity() const;
};
