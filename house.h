#ifndef _HOUSE_H_
#define _HOUSE_H_
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "member.h"

using namespace std;

class House {
private:
    string owner;
    string occupier;
    string houseName;
    string location;
    int creditPrice;
    double houseRating;
    double requiredRating;
    
public:
    House();
    House(string owner, string occupier, string houseName, string location, int creditPrice, double houseRating, double requiredRating);

    string getOwner();

    string getOccupier();

    string getHouseName();

    string getLocation();

    int getCreditPrice();

    double getHouseRating();

    double getRequiredRating();

    void setOwner(string a);

    void setOccupier(string a);

    void setHouseName(string a);

    void setLocation(string a);

    void setCreditPrice(int a);

    void setHouseRating(double a);

    void setRequiredRating(double a);

    void viewHouseInfo(int a);

    void calHouseRating(double a);
};

void viewAllHouses(int a);

vector<House>tempHouseMemory();

vector<House>viewHouseLocation (string location, Member currentLogIn);

House viewHousePossess(string house_possess_user);

House housePick(string house_name);

#endif
