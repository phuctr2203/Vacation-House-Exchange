#include <iostream>
#include <string>
#include <vector>

using namespace std;

class House {
private:
    string owner;
    string name;
    string location;
    string occupier;
    int creditPrice;
    double houseRating;

public:
    //Constructors
    House() {};
    House(string owner, string name, string location, string occupier, int creditPrice, double houseRating) {
        this->owner = owner;
        this->name = name;
        this->location = location;
        this->occupier = occupier;
        this->creditPrice = creditPrice;
        this->houseRating = houseRating;
    }

    void viewHouse();
    void addHouse(House house);
};
