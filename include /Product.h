#pragma once
#include <string>
#include <iostream>
#include <stdexcept>

class Product {
private:
    std::string productId;
    std::string name;
    double price;
    int quantityInStock;

public:
    Product();
    Product(const std::string& productId, const std::string& name,
            double price, int quantityInStock);

    std::string getProductId() const { return productId; }
    std::string getName() const { return name; }
    double getPrice() const { return price; }
    int getQuantityInStock() const { return quantityInStock; }

    void setName(const std::string& name);
    void setPrice(double price);
    void setQuantityInStock(int quantity);

    void restock(int quantity);
    void sell(int quantity);
    bool isAvailable() const;

    void print() const;

    bool operator==(const Product& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Product& product);
};
