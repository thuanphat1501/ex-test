#include "dish.hpp"

int Dish::getID() const { return id; }
void Dish::setPrice(int newPrice) { price = newPrice; }
int Dish::getPrice() const { return price; }
string Dish::getName() const { return name; }
