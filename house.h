#ifndef _HOUSE_H_
#define _HOUSE_H_
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class House {
private:
    string owner;
    string occupier;
    string name;
    string location;
    int creditPrice;
    double houseRating;
    double requiredRating;
    
public:
    House();
    House(string owner, string occupier, string name, string location, int creditPrice, double houseRating, double requiredRating);

    string getOwner();

    string getOccupier();

    string getName();

    string getLocation();

    int getCreditPrice();

    double getHouseRating();

    double getRequiredRating();

    void viewHouseInfo();

    void calHouseRating(double a);
};

void viewAllHouses();

#endif
