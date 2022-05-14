#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>
#include "house.h"
#include "member.h"

using namespace std;

House::House(){}
House::House(string owner, string occupier, string houseName, string location, int creditPrice, double houseRating, double requiredRating)
{ 
    this->owner = owner;
    this->occupier = occupier;
    this->houseName = houseName;
    this->location = location;
    this->creditPrice = creditPrice;
    this->houseRating = houseRating;
    this->requiredRating = requiredRating;
}

string House::getOwner(){
    return owner;
}

string House::getHouseName(){
    return houseName;
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

void House::setOwner(string a){
    owner = a;
}

void House::setOccupier(string a){
    occupier = a;;
}

void House::setHouseName(string a){
    houseName = a;;
}

void House::setLocation(string a){
    location = a;
}

void House::setCreditPrice(int a){
    creditPrice = a;
}

void House::setHouseRating(double a){
    houseRating = a;
}

void House::setRequiredRating(double a){
    requiredRating = a;
}

void House::calHouseRating(double a)
{
    houseRating += a;
}

// View House Infor
void House::viewHouseInfo(int a){
    if(a == 1)
    {
        cout
        << "\nHouse Owner: " << owner
        << "\nHouse Name: " << houseName
        << "\nLocation: " << location
        << "\nPrice: " << creditPrice << "/Night"
        << "\nRating: " << houseRating
        << "\nRequired Rating: " << requiredRating << endl;
    }
    else if(a == 2)
    {
        cout
        << "\nHouse Owner: " << owner
        << "\nHouse Name: " << houseName
        << "\nLocation: " << location
        << "\nPrice: " << creditPrice << "/Night"
        << "\nRating: " << houseRating
        << "\nRequired Rating: " << requiredRating << endl;
    }
    else if(a == 3)
    {
        cout
        << "\nHouse Owner: " << owner
        << "\nHouse Name: " << houseName
        << "\nLocation: " << location
        << "\nPrice: " << creditPrice << "/Night"
        << "\nRating: " << houseRating
        << "\nRequired Rating: " << requiredRating
        << "\nCurrent Occupier: " << occupier << endl;
    }
}

// List of House to VECTOR
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
        string houseName;
        string location;
        string creditPrice_str;
        string houseRating_str;
        string requiredRating_str;
        string file_string;
        getline(iFile, file_string);
        stringstream ss(file_string);
        getline(ss, owner, ',');
        getline(ss, occupier, ',');
        getline(ss, houseName, ',');
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

        House house1(owner, occupier, houseName, location, creditPrice, houseRating, requiredRating);
        houseList.push_back(house1);
    }
    iFile.close();
    return houseList;
}


// View All House Info
void viewAllHouses(int a) {
    vector<House> houseList = tempHouseMemory();

    for (int i = 0; i < houseList.size(); i++) {
        houseList[i].viewHouseInfo(a);
    }
}

// Show House According to Location
vector<House>viewHouseLocation(string location, Member currentLogIn) {
    vector<House> cityList;

    vector<House> houseList = tempHouseMemory();
    
    for(int i = 0; i < houseList.size(); i++)
    {
        if((location == houseList[i].getLocation()) && 
           (currentLogIn.getCreditPoints() >= houseList[i].getCreditPrice()) &&
           (currentLogIn.getRatingScore() >= houseList[i].getRequiredRating()) && houseList[i].getOccupier() == "none")
        {
            cityList.push_back(houseList[i]);
        }
    }

    for (int i = 0; i < cityList.size(); i++) {
        cityList[i].viewHouseInfo(2);
    }
    
    return cityList;
}

// View House that member signed in possess
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

    if (house_result.getOwner() == "") {
        cout << "You have not listed a house"<< endl;
    } else {
        house_result.viewHouseInfo(3);
    }

    return house_result;
}



