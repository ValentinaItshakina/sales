#include "Product.h"
#include <iomanip>

Product::Product() : productId("N/A"), name("Unnamed"), price(0.0), quantityInStock(0) {}

Product::Product(const std::string& productId, const std::string& name,
                 double price, int quantityInStock)
    : productId(productId), name(name), price(price), quantityInStock(quantityInStock) {
    if (!isValidPrice(price)) {
        throw std::invalid_argument("Price cannot be negative");
    }
    if (quantityInStock < 0) {
        throw std::invalid_argument("Quantity cannot be negative");
    }
}

void Product::setName(const std::string& name) {
    if (name.empty()) {
        throw std::invalid_argument("Product name cannot be empty");
    }
    this->name = name;
}

void Product::setPrice(double price) {
    if (!isValidPrice(price)) {
        throw std::invalid_argument("Price cannot be negative");
    }
    this->price = price;
}

void Product::setQuantityInStock(int quantity) {
    if (quantity < 0) {
        throw std::invalid_argument("Quantity cannot be negative");
    }
    this->quantityInStock = quantity;
}

void Product::restock(int quantity) {
    if (quantity <= 0) {
        throw std::invalid_argument("Restock quantity must be positive");
    }
    quantityInStock += quantity;
}

void Product::sell(int quantity) {
    if (quantity <= 0){
        throw std::invalid_argument("Sell quantity must be positive");
    }
    if (quantityInStock >= quantity) {
        quantityInStock -= quantity;
    }
}

bool Product::isAvailable() const {
    return quantityInStock > 0;
}

void Product::print() const {
    std::cout << std::left
              << "ID: " << std::setw(10) << productId
              << "Name: " << std::setw(20) << name
              << "Price: $" << std::fixed << std::setprecision(2) << std::setw(8) << price
              << "Stock: " << std::setw(5) << quantityInStock
              << "Status: " << (isAvailable() ? "Available" : "Out of stock")
              << std::endl;
}

bool Product::operator==(const Product& other) const {
    return productId == other.productId;
}

std::ostream& operator<<(std::ostream& os, const Product& product) {
    os << std::left
       << std::setw(12) << product.productId
       << std::setw(25) << product.name
       << "$" << std::fixed << std::setprecision(2) << std::setw(10) << product.price
       << std::setw(8) << product.quantityInStock
       << (product.isAvailable() ? "✓" : "✗");
    return os;
}
