#include "../include/Warehouse.h"
#include <iostream>

int main() {
    Warehouse sklad;
    sklad.addProduct(Product("P001", "Молоко", 85.5, 50));
    sklad.addProduct(Product("P002", "Хлеб", 45.0, 100));
    sklad.addProduct(Product("P003", "Сыр", 320.0, 30));
    sklad.addProduct(Product("P004", "Масло", 120.0, 40));
    sklad.addProduct(Product("P005", "Яйца", 95.0, 60));
    sklad.addProduct(Product("P006", "Сахар", 70.0, 80));
    sklad.addProduct(Product("P007", "Мука", 65.0, 70));
    sklad.addProduct(Product("P008", "Кофе", 450.0, 25));
    sklad.addProduct(Product("P009", "Чай", 280.0, 35));
    sklad.addProduct(Product("P010", "Соль", 25.0, 90));

    std::cout << "=== НАЧАЛО РАБОЧЕГО ДНЯ ===\n";
    sklad.generateInventoryReport();

    Product* p1 = sklad.findProduct("P001");
    if (p1) p1->sell(15);
    Product* p2 = sklad.findProduct("P002");
    if (p2) p2->sell(30);
    Product* p3 = sklad.findProduct("P003");
    if (p3) p3->sell(10);
    Product* p5 = sklad.findProduct("P005");
    if (p5) p5->sell(25);
    Product* p8 = sklad.findProduct("P008");
    if (p8) p8->sell(8);

    Product* p4 = sklad.findProduct("P004");
    if (p4) p4->restock(20);
    Product* p6 = sklad.findProduct("P006");
    if (p6) p6->restock(15);
    Product* p9 = sklad.findProduct("P009");
    if (p9) p9->restock(10);

    sklad.addProduct(Product("P011", "Орехи", 520.0, 20));
    sklad.addProduct(Product("P012", "Мед", 480.0, 15));

    std::cout << "\n=== КОНЕЦ РАБОЧЕГО ДНЯ ===\n";
    sklad.generateInventoryReport();
    return 0;
}
