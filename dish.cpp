#include"dish.hpp"
#include<string>

int Dish::getID() const { return id; }

void Dish::setPrice(int newPrice) { price = newPrice; }
int Dish::getPrice() const { return price; }
string Dish::getName() const { return name; }