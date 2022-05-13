#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>
#include "house.h"
#include "member.h"
#include "editHouse.h"

using namespace std;

void listHouse(string owner) {
    int dm = 0;
    int condition_true = 0;
    int count = 0;
    int choose;
    int index;
    bool check = false;

    vector<House> houseList = tempHouseMemory();
    House newHouse;

    cout << "----- List House -----" << endl;
    
    do {
        string owner_input;
        if (count == 0) {
            owner_input = owner;
        } else {
            cout << "You have listed a house, please unlist before list new house." << endl;
            cout << "Please select options: "
                    "\n1. Unlist house"
                    "\n2. Exit" << endl;
            listHouse:
            cin >> index;
            switch (index) {
                case 1:
                {
                    unListHouse(owner);
                    break;
                }
                case 2:
                {
                    exit(0);
                    break;
                }
                default:
                {
                    cout << "Please choose 1 or 0" << endl;
                    goto listHouse;
                }
            }
            break;
        }

        for (int i = 0; i < houseList.size(); i++) {
            if (owner_input == houseList[i].getOwner()) {
                condition_true = 0;
                check = false;
                break;
            } else {
                condition_true = 1;
                check = true;
            }
        }
        newHouse.setOwner(owner);
        count++;
    }while(condition_true == 0);

    string houseName_input;
    string location_input;
    int creditPrice_input;
    double requiredRating_input;
    
    cout << "Please enter house name: ";
    getline(cin, houseName_input);
    newHouse.setHouseName(houseName_input);

    cout << "Please choose your location: " 
            "\n1. Hanoi"
            "\n2. Danang"
            "\n3. Saigon" << endl;
    menuLocation:
    cin >> choose;
    switch (choose) {
        case 1:
        {
            location_input = "Hanoi";
            break;
        }
        case 2:
        {
            location_input = "Danang";
            break;
        }
        case 3:
        {
            location_input = "Saigon";
            break;
        }
        default:
        {   
            cout << "Please choose from 1 to 3" << endl;
            goto menuLocation;
        }
    }
    newHouse.setLocation(location_input);

    cout << "Please enter credit price: " << endl;
    cin >> creditPrice_input;
    newHouse.setCreditPrice(creditPrice_input);

    cout << "Please enter required rating: " << endl;
    cin >> requiredRating_input;
    newHouse.setRequiredRating(requiredRating_input);
    
    newHouse.setHouseRating(0);
    newHouse.setOwner(owner);
    newHouse.setOccupier("none");

    houseList.push_back(newHouse);

    ofstream oFile("houseList.txt", std::ofstream::trunc);
    for (int i = 0; i < houseList.size(); i++) {
        string owner = houseList[i].getOwner();
        string occupier = houseList[i].getOccupier();
        string houseName = houseList[i].getHouseName();
        string location = houseList[i].getLocation();
        int creditPrice = houseList[i].getCreditPrice();
        double houseRating = houseList[i].getHouseRating();
        double requiredRating = houseList[i].getRequiredRating();

        if (i != houseList.size() - 1) {
            oFile << owner << ","
            << occupier << ","
            << houseName << ","
            << location << ","
            << creditPrice << ","
            << houseRating << ","
            << requiredRating << endl;
        } else {
            oFile << owner << ","
            << occupier << ","
            << houseName << ","
            << location << ","
            << creditPrice << ","
            << houseRating << ","
            << requiredRating;
        }
    }

    cout << "List house complete" << endl;
}

void unListHouse(string owner) {
    
    vector<House> deleteHouse = tempHouseMemory();

    for(int i = 0; i < deleteHouse.size(); i++)
    {
        if(owner == deleteHouse[i].getOwner())
        {
            deleteHouse.erase(deleteHouse.begin() + i);
            break;
        }
    }
    
    ofstream oFile("houseList.txt", std::ofstream::trunc);
    for (int i = 0; i < deleteHouse.size(); i++) {
        string owner = deleteHouse[i].getOwner();
        string occupier = deleteHouse[i].getOccupier();
        string houseName = deleteHouse[i].getHouseName();
        string location = deleteHouse[i].getLocation();
        int creditPrice = deleteHouse[i].getCreditPrice();
        double houseRating = deleteHouse[i].getHouseRating();
        double requiredRating = deleteHouse[i].getRequiredRating();

        if (i != deleteHouse.size() - 1) {
            oFile << owner << ","
            << occupier << ","
            << houseName << ","
            << location << ","
            << creditPrice << ","
            << houseRating << ","
            << requiredRating << endl;
        } else {
            oFile << owner << ","
            << occupier << ","
            << houseName << ","
            << location << ","
            << creditPrice << ","
            << houseRating << ","
            << requiredRating;
        }
    }
    cout << "House unlisted" << endl;
}

int main() {
    listHouse("shelby");
}