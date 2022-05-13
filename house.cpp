#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>
#include "house.h"

using namespace std;

House::House(){}
House::House(string owner, string occupier, string name, string location, int creditPrice, double houseRating, double requiredRating)
{ 
    this->owner = owner;
    this->occupier = occupier;
    this->name = name;
    this->location = location;
    this->creditPrice = creditPrice;
    this->houseRating = houseRating;
    this->requiredRating = requiredRating;
}

string House::getOwner(){
    return owner;
}

string House::getName(){
    return name;
}

string House::getLocation(){
    return location;
}

string House::getOccupier(){
    return occupier;
}

int House::getCreditPrice(){
    return creditPrice;
}

double House::getHouseRating(){
    return houseRating;
}

double House::getRequiredRating(){
    return requiredRating;
}

void House::calHouseRating(double a)
{
    houseRating += a;
}

void House::viewHouseInfo(int a){
    if(a == 1)
    {
        cout
        << "\nHouse Owner: " << owner
        << "\nHouse Name: " << name
        << "\nLocation: " << location
        << "\nPrice: " << creditPrice << "/Night"
        << "\nRating: " << houseRating
        << "\nRequired Rating: " << requiredRating << endl;
    }
    else if(a == 2)
    {
        cout
        << "\nHouse Owner: " << owner
        << "\nHouse Name: " << name
        << "\nLocation: " << location
        << "\nPrice: " << creditPrice << "/Night"
        << "\nRating: " << houseRating
        << "\nRequired Rating: " << requiredRating
        << "\nAvailability: " << occupier << endl;
    }
    else
    {
        cout
        << "\nHouse Owner: " << owner
        << "\nHouse Name: " << name
        << "\nLocation: " << location
        << "\nPrice: " << creditPrice << "/Night"
        << "\nRating: " << houseRating
        << "\nRequired Rating: " << requiredRating
        << "\nCurrent Occupier: " << occupier << endl;
    }
}

vector<House>tempHouseMemory(){
    vector<House> houseList;

    ifstream iFile("houseList.txt");
    if (iFile.fail())
    {
        cout << "Fail to open file";
    }

    while (!iFile.eof())
    {
        string owner;
        string occupier;
        string name;
        string location;
        string creditPrice_str;
        string houseRating_str;
        string requiredRating_str;
        string file_string;
        getline(iFile, file_string);
        stringstream ss(file_string);
        getline(ss, owner, ',');
        getline(ss, occupier, ',');
        getline(ss, name, ',');
        getline(ss, location, ',');
        
        int creditPrice;
        getline(ss, creditPrice_str, ',');
        creditPrice = stoi(creditPrice_str);

        double houseRating;
        getline(ss, houseRating_str, ',');
        houseRating = stod(houseRating_str);

        double requiredRating;
        getline(ss, requiredRating_str, ',');
        requiredRating = stod(requiredRating_str);

        House house1(owner, occupier, name, location, creditPrice, houseRating, requiredRating);
        houseList.push_back(house1);
    }
    iFile.close();
    return houseList;
}

void viewAllHouses(int a) {
    vector<House> houseList = tempHouseMemory();

    for (int i = 0; i < houseList.size(); i++) {
        houseList[i].viewHouseInfo(a);
    }
}

vector<House>viewHouseLocation (string location) {
    vector<House> cityList;

    vector<House> houseList = tempHouseMemory();
    
    for(int i = 0; i < houseList.size(); i++)
    {
        if(location == houseList[i].getLocation()) {
            cityList.push_back(houseList[i]);
        };
    }

    for (int i = 0; i < cityList.size(); i++) {
        cityList[i].viewHouseInfo(2);
    }
    
    return cityList;
}

House viewHousePossess(string house_possess_user)
{
    House house_result;
    vector<House> house_total = tempHouseMemory();
    for(int i = 0; i < house_total.size(); i++)
    {
        if(house_possess_user == house_total[i].getOwner())
        {
            house_result = house_total[i];
        }
    }
    house_result.viewHouseInfo(3);

    return house_result;
}
