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

bool list_available(string check_owner)
{
    vector<House> houseList = tempHouseMemory();
    for(int i = 0; i < houseList.size(); i++)
    {
        if(houseList[i].getOwner() == check_owner)
        {
            return false;
        }
    }
    return true;
}

void listHouse(string owner) {
    int choose;
    int index;

    vector<House> houseList = tempHouseMemory();
    House newHouse;

    cout << "----- List House -----" << endl;
    while(!list_available(owner))
    {
        cout << "You have listed a house, please unlist before list new house." << endl;
        cout << "Please select options: "
                    "\n1. Unlist house"
                    "\n2. Exit" << endl;
        cin >> index;
        while(index != 1 && index != 2)
        {
            cout << "Invalid Input!" << endl;
            cout << "Please select options: "
            "\n1. Unlist house"
            "\n2. Exit" << endl;
            cin >> index;
        }
        if(index == 1)
        {
            unListHouse(owner);
        }
        else if(index == 2)
        {
            exit(0);
        }
    }

    newHouse.setOwner(owner);
    string houseName_input;
    string location_input;
    int creditPrice_input;
    double requiredRating_input;
    
    cout << "Please enter house name: ";
    cin.ignore();
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
