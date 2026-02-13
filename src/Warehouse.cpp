#include "Warehouse.h"
#include <iostream>
#include <iomanip>

void Warehouse::addProduct(const Product& product) {
    catalog.push_back(product);
}

Product* Warehouse::findProduct(const std::string& productId) {
    for (auto& product : catalog) {
        if (product.getId() == productId) return &product;
    }
    return nullptr;
}

void Warehouse::generateInventoryReport() const {
    std::cout << "Отчет по складу:\n";
    std::cout << std::setw(10) << "ID"
              << std::setw(20) << "Название"
              << std::setw(10) << "Цена"
              << std::setw(30) << "Кол-во на складе"
              << std::endl;

    for (const auto& product: catalog) {
        std::cout << std::setw(10) << product.getId()
                  << std::setw(20) << product.getName()
                  << std::setw(10) << std::fixed << std::setprecision(2) << product.getPrice()
                  << std::setw(30) << product.getQuantity()
                  << std::endl;
    }
}
