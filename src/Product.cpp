#include "Product.h"

void Product::restock(int quantity) {
    quantityInStock += quantity;
}

void Product::sell(int quantity) {
    quantityInStock -= quantity;
}

bool Product::isAvailable() const {
    return quantityInStock > 0;
}

std::string Product::getId() const {
    return productId;
}

std::string Product::getName() const {
    return name;
}

double Product::getPrice() const {
    return price;
}

int Product::getQuantity() const {
    return quantityInStock;
}
