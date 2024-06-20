#include "table.hpp"
#include <iostream>

using namespace std;

int Table::getID() const {
    return id_table;
}

bool Table::getStatusTable() const {
    return status_table;
}

void Table::orderDish() {
    if (!menu || menu->empty()) {
        cout << "Menu is empty or not initialized." << endl;
        return;
    }

    cout << "MENU:" << endl;
    for (const auto& dish : *menu) {
        cout << "ID: " << dish.getID() << ", Name: " << dish.getName() << ", Price: " << dish.getPrice() << endl;
    }

    int dishId;
    cout << "Enter Dish ID: ";
    cin >> dishId;

    bool found = false;
    Dish selectedDish;
    for (const auto& dish : *menu) {
        if (dish.getID() == dishId) {
            found = true;
            selectedDish = dish;
            break;
        }
    }

    if (found) {
        int quantity;
        cout << "Enter quantity: ";
        cin >> quantity;

        Order order(selectedDish, quantity);
        list_order.push_back(order);

        cout << "Ordered dish: ID " << selectedDish.getID() << ", Name: " << selectedDish.getName() << ", Quantity: " << quantity << endl;
    }
    else {
        cout << "The dish does not exist on the menu." << endl;
    }
}

void Table::deleteDish(int dishId) {
    if (list_order.empty()) {
        cout << "No dishes have been ordered yet." << endl;
        return;
    }

    // Print the list of ordered dishes before deletion
    getListOrder();

    auto it = list_order.begin();
    while (it != list_order.end()) {
        if (it->getDish().getID() == dishId) {
            cout << "Dish found: ID: " << it->getDish().getID() << ", Name: " << it->getDish().getName()
                << ", Quantity: " << it->getNumberDish() << endl;

            int quantityToDelete;
            cout << "Enter quantity to delete: ";
            cin >> quantityToDelete;

            if (quantityToDelete >= it->getNumberDish()) {
                it = list_order.erase(it); // Remove the order if the quantity is equal or greater
                cout << "Dish removed from order." << endl;
            }
            else {
                it->setNumberDish(it->getNumberDish() - quantityToDelete); // Update the quantity
                cout << "Updated dish quantity to: " << it->getNumberDish() << endl;
                ++it;
            }

            return; // Exit after processing the specified dish
        }
        else {
            ++it;
        }
    }

    cout << "The dish with ID " << dishId << " was not found in the order list." << endl;
}
void Table::changeDish(int oldDishId, int newDishId) {
    if (list_order.empty()) {
        cout << "No dishes have been ordered yet." << endl;
        return;
    }

    auto it = list_order.begin();
    while (it != list_order.end()) {
        if (it->getDish().getID() == oldDishId) {
            cout << "Dish to change found: ID: " << it->getDish().getID() << ", Name: " << it->getDish().getName()
                << ", Quantity: " << it->getNumberDish() << endl;

            bool newDishFound = false;
            Dish newDish;
            for (const auto& dish : *menu) {
                if (dish.getID() == newDishId) {
                    newDishFound = true;
                    newDish = dish;
                    break;
                }
            }

            if (newDishFound) {
                int quantityToChange = it->getNumberDish();
                *it = Order(newDish, quantityToChange);
                cout << "Changed to new dish: ID: " << newDish.getID() << ", Name: " << newDish.getName()
                    << ", Quantity: " << quantityToChange << endl;
            }
            else {
                cout << "The new dish with ID " << newDishId << " does not exist on the menu." << endl;
            }

            return; // Exit after processing the specified dish
        }
        else {
            ++it;
        }
    }

    cout << "The dish with ID " << oldDishId << " was not found in the order list." << endl;
}


void Table::getListOrder() const {
    if (list_order.empty()) {
        cout << "No dishes have been ordered yet." << endl;
        return;
    }

    cout << "List of Ordered Dishes:" << endl;
    for (const auto& order : list_order) {
        cout << "ID: " << order.getDish().getID() << ", Name: " << order.getDish().getName()
            << ", Quantity: " << order.getNumberDish() << endl;
    }
}


void Table::makePayment() {
    int totalPayment = 0;
    for (const Order& order : list_order) {
        totalPayment += order.getDish().getPrice() * order.getNumberDish();
    }

    bill = totalPayment;
    list_order.clear();
}
