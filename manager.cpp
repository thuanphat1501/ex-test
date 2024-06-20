#include "manager.hpp"
#include <iostream>

void Manager::setTable(int number) {
    number_table = number;
}

void Manager::newDish() {
    string dishName;
    int dishPrice;
    cout << "Enter dish name: ";
    cin >> dishName;
    cout << "Enter dish price: ";
    cin >> dishPrice;

    Dish newDish(dishName, dishPrice);
    menu.push_back(newDish);

    cout << "Dish added successfully!" << endl;
}

void Manager::updatePrice() {
    string dishName;
    int newDishPrice;
    cout << "Enter dish name to update: ";
    cin >> dishName;

    for (auto& dish : menu) {
        if (dish.getName() == dishName) {
            cout << "Enter new price for " << dishName << ": ";
            cin >> newDishPrice;
            dish.setPrice(newDishPrice);
            cout << "Dish updated successfully!" << endl;
            return;
        }
    }
    cout << "Dish not found." << endl;
}

void Manager::deleteDish(int dishId) {
    for (auto it = menu.begin(); it != menu.end(); ++it) {
        if (it->getID() == dishId) {
            menu.erase(it);
            cout << "Dish deleted successfully!" << endl;
            return;
        }
    }
    cout << "Dish not found." << endl;
}

void Manager::listDish() const {
    for (const auto& dish : menu) {
        cout << "ID: " << dish.getID() << ", Name: " << dish.getName() << ", Price: " << dish.getPrice() << endl;
    }
}
