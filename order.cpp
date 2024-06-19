#include"order.hpp"

void Order::setNumberDish(int number)
{
    number_dish = number;
}

Dish Order::getDish() const 
{
    return dish;
}

int Order::getNumberDish() const
{
    return number_dish;
}
