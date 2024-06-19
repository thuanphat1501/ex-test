#ifndef ORDER_H
#define ORDER_H

#include"dish.hpp"

class Order
{
private:
	Dish dish;
	int number_dish;
public:
	Order(Dish dish, int number) : dish(dish), number_dish(number) {};
	void setNumberDish(int number);
	Dish getDish() const;
	int getNumberDish() const;

};

#endif // !ORDER

