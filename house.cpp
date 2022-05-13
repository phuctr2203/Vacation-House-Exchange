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

void House::viewHouseInfo(){
    cout
    << "\nHouse Owner: " << owner
    << "\nHouse Name: " << name
    << "\nLocation: " << location
    << "\nPrice: " << creditPrice
    << "\nRating: " << houseRating
    << "\nRequired Rating: " << requiredRating
    << "\nAvailablity: " << occupier << endl;
}

void viewAllHouses() {
    vector<House> house;

    ifstream iFile("D:/Code/C++ RMIT/EEET2824/data/houseList.txt");

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
        int creditPrice;
        double houseRating;
        double requiredRating;
        char ch;
        stringstream ss;
        string file_string;
        getline(iFile, file_string);
        ss << file_string;
        ss >> owner >> occupier >> name >> location >> creditPrice >> ch >> houseRating >> ch >> requiredRating;

        if (!owner.empty()){
            owner.pop_back();
        }

        if (!name.empty()){
            name.pop_back();
        }

        if (!location.empty()){
            location.pop_back();
        }

        if (!occupier.empty()){
            occupier.pop_back();
        }

        House house1(owner, occupier, name, location, creditPrice, houseRating, requiredRating);
        house.push_back(house1);
    }
    iFile.close();

    for (int i = 0; i < house.size(); i++)
    {
        house[i].viewHouseInfo();
    }
    
    ofstream oFile("D:/Code/C++ RMIT/EEET2824/data/houseList.txt", std::ofstream::trunc);
    for (int i = 0; i < house.size(); i++)
    {
        string owner = house[i].getOwner();
        string occupier = house[i].getOccupier();
        string name = house[i].getName();
        string location = house[i].getLocation();
        int creditPrice = house[i].getCreditPrice();
        double houseRating = house[i].getHouseRating();
        double requiredRating = house[i].getRequiredRating();

        if (i != house.size() - 1)
        {
            oFile
            << owner << ", "
            << occupier << ", "
            << name << ", "
            << location << ", "
            << creditPrice << ", "
            << houseRating << ", "
            << requiredRating << endl;
        }
        else
        {
            oFile
            << owner << ", "
            << occupier << ", "
            << name << ", "
            << location << ", "
            << creditPrice << ", "
            << houseRating << ", "
            << requiredRating;
        }
    }
    oFile.close();
    
}
/*class House {
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
    House(string owner, string name, string location, int creditPrice, double houseRating, string occupier) {
        this->owner = owner;
        this->name = name;
        this->location = location;
        this->occupier = occupier;
        this->creditPrice = creditPrice;
        this->houseRating = houseRating;
    }

    string getOwner(){
        return owner;
    }

    string getName(){
        return name;
    }

    string getLocation(){
        return location;
    }

    string getOccupier(){
        return occupier;
    }

    int getCreditPrice(){
        return creditPrice;
    }

    double getHouseRating(){
        return houseRating;
    }

    void calHouseRating(double a)
    {
        houseRating += a;
    }

    void viewHouseInfo(){
        cout
        << "\nHouse Owner: " << owner
        << "\nHouse Name: " << name
        << "\nLocation: " << location
        << "\nPrice: " << creditPrice
        << "\nRating: " << houseRating
        << "\nAvailablity: " << occupier
        << endl;
    }
};

void houseInfo() {
    vector<House> house;

    ifstream iFile("C:/Users/Binh Nguyen/Desktop/Folder của trường R/EEET2482/Group Assignment/sed-group-asm/data/houseList.txt");

    if (iFile.fail())
    {
        cout << "Fail to open file";
    }

    while (!iFile.eof())
    {
        string owner;
        string name;
        string location;
        int creditPrice;
        double houseRating;
        string occupier;
        char ch;
        stringstream ss;
        string file_string;
        getline(iFile, file_string);
        ss << file_string;
        ss >> owner >> name >> location >> creditPrice >> ch >> houseRating >> occupier;

        if (!owner.empty()){
            owner.pop_back();
        }

        if (!name.empty()){
            name.pop_back();
        }

        if (!location.empty()){
            location.pop_back();
        }

        if (!occupier.empty()){
            occupier.pop_back();
        }

        House house1(owner, name, location, creditPrice, houseRating, occupier);
        house.push_back(house1);
    }
    iFile.close();

    for (int i = 0; i < house.size(); i++)
    {
        house[i].viewHouseInfo();
    }
    
    ofstream oFile("C:/Users/Binh Nguyen/Desktop/Folder của trường R/EEET2482/Group Assignment/sed-group-asm/data/houseList.txt", ofstream::trunc);
    for (int i = 0; i < house.size(); i++)
    {
        string owner = house[i].getOwner();
        string name = house[i].getName();
        string location = house[i].getLocation();
        int creditPrice = house[i].getCreditPrice();
        double houseRating = house[i].getHouseRating();
        string occupier = house[i].getOccupier();

        if (i != house.size() - 1)
        {
            oFile
            << owner << ", "
            << name << ", "
            << location << ", "
            << creditPrice << ", "
            << houseRating << ", "
            << occupier << endl;
        }
        else
        {
            oFile
            << owner << ", "
            << name << ", "
            << location << ", "
            << creditPrice << ", "
            << houseRating << ", "
            << occupier;
        }
    }
    oFile.close();
}
*/
