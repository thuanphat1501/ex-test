#ifndef TABLE_H
#define TABLE_H

#include "order.hpp"
#include "dish.hpp"
#include <list>
#include <iostream>
#include <string>

using namespace std;

class Table
{
private:
    int id_table;
    bool status_table;
    const list<Dish>* menu; // Dùng con tr? ?? l?u tr? tham chi?u ??n menu
    list<Order> list_order;
    double bill;

public:
    Table() : id_table(-1), status_table(false), menu(nullptr), bill(0.0) {} // Constructor m?c ??nh
    Table(int id, bool status_table, const list<Dish>& menu) :
        id_table(id), status_table(status_table), menu(&menu), bill(0.0) {}

    int getID() const;
    bool getStatusTable() const;
    void orderDish();
    void deleteDish(int dishId);
    void getListOrder() const;
    void changeDish(int oldDishId, int newDishId);
    void makePayment();
    void setMenu(const list<Dish>& newMenu) { menu = &newMenu; } // Thêm ph??ng th?c ?? l?y menu
    const list<Dish>& getMenu() const { return *menu; }
};

#endif // !TABLE_H
