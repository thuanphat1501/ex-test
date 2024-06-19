#ifndef MANAGER_H
#define MANAGER_H


#include"dish.hpp"
#include<list>
#include<string>

using namespace std;
class Manager
{
private:
	list<Dish> menu;
	int number_table;
	string password;
public:
	Manager(list<Dish>& menu, int& number_table, string password = "ADMIN") :
		menu(menu), number_table(number_table), password(password) {};
	void setTable(int number);
	void newDish();
	void updatePrice();
	void deleteDish(int dishId);
	void listDish() const;


};
#endif // !MANAGER_H
