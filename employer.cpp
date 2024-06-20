#include "employer.hpp"
#include "dish.hpp"
#include"table.hpp"
#include"manager.hpp"
#include <vector>
#include <string>
#include<iostream>
void Employer::updateTableList(list<Dish> menu, int number)
{
    list_table.clear(); // Xóa danh sách bàn hiện tại
    for (int i = 1; i <= number; ++i)
    {
        Table table(i, true, menu);
        list_table.push_back(table); // Thêm bàn mới vào danh sách
    }
}
// Trong lớp Employer
Table& Employer::getTable(int id)
{
    for (auto& table : list_table) // Dùng auto& để tránh copy
    {
        if (table.getID() == id)
        {
            cout << "Table is found\n";
            return table;
        }
    }
    cout << "Table not found\n";
    static Table invalidTable; // Đối tượng Table không hợp lệ
    return invalidTable;
}




void Employer::displaySelectedTable(int num)
{
    cout << "Selected table: ";
    for (int i = 1; i <= num; ++i)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "Table Status: \t";
    for (int i = 1; i <= num; ++i)
    {
        cout << "O ";
    }
    cout << endl;
    cout << "X: is not available\n";
    cout << "O: is available\n";
}

// ...