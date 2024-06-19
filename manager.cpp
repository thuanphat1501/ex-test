#include"manager.hpp"
#include"table.hpp"
#include"dish.hpp"
#include"employer.hpp"
#include<iostream>
//list<Dish> menu;

void Manager::setTable(int number)
{
    number_table = number;

}



// Hàm để thêm món ăn vào danh sách menu
void Manager::newDish()
{
    string dishName;
    double dishPrice;
    // Nhập thông tin món ăn từ người dùng
    cout << "Enter dish name: ";
    cin >> dishName;
    cout << "Enter dish price: ";
    cin >> dishPrice;

    // Tạo đối tượng Dish mới và thêm vào danh sách menu
    Dish newDish(dishName, dishPrice);
    menu.push_back(newDish);

    cout << "Dish added successfully!" << endl;
}
void Manager::updatePrice() {
    string dishName;
    double newDishPrice;
    // Nhập tên món ăn cần cập nhật
    cout << "Enter dish name to update: ";
    cin >> dishName;

    // Tìm món ăn trong danh sách menu
    for (auto& dish : menu) {
        if (dish.getName() == dishName) {
            cout << "Enter new price for " << dishName << ": ";
            cin >> newDishPrice;
            dish.setPrice(newDishPrice); // Cập nhật giá món ăn
            cout << "ID: " << dish.getID() << ", Name: " << dish.getName() << ", Price: " << dish.getPrice() << endl;
            cout << "Dish updated successfully!" << endl;
            return; 
        }
    }

    // Nếu không tìm thấy món ăn
    cout << "Dish not found. Please check the name and try again." << endl;
}

void Manager::deleteDish(int dishId) {
    for (auto it = menu.begin(); it != menu.end(); ++it) {
        if (it->getID() == dishId) {
            menu.erase(it); // Xóa món ăn khỏi danh sách
            cout << "Dish with ID " << dishId << " deleted successfully!" << endl;
            return;
        }
    }
    cout << "Dish with ID " << dishId << " not found." << endl;
}
// Hàm để in ra danh sách các món ăn
void Manager::listDish() const {
    cout << "List of Dishes:" << endl;
    for (const auto& dish : menu) {
        cout << "ID: " << dish.getID() << ", Name: " << dish.getName() << ", Price: " << dish.getPrice() << endl;
    }
}