#ifndef DISH_H
#define DISH_H

#include <string>
using namespace std;
class Dish
{
private:
    int id;
    string name;
    int price;

public:
    Dish(string name, int price) : name(name), price(price)
    {
        static int ID = 24001;
        id = ID;
        ID++;
    }
    Dish() : id(-1), name(""), price(0) {}

    int getID() const;
    void setPrice(int newPrice);
    int getPrice() const;
    string getName() const;
};

#endif // DISH_H
