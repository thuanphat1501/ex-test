#ifndef MANAGER_H
#define MANAGER_H

#include <list>
#include <string>
#include "dish.hpp"

using namespace std;

class Manager {
private:
    list<Dish> menu;
    int number_table;
    string password;

public:
    Manager(list<Dish>& menu, int& number_table, string password = "ADMIN") :
        menu(menu), number_table(number_table), password(password) {}
    void setTable(int number);
    void newDish();
    void updatePrice();
    void deleteDish(int dishId);
    void listDish() const;
    const list<Dish>& getMenu() const { return menu; }
};

#endif // MANAGER_H
