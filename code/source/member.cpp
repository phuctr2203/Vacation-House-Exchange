#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "history.cpp"
#include "house.cpp"

using namespace std;

class Member {
protected:
    string username;
    string password;
    string name;
    string phone;
    int creditPoints;

public:
    // Constructor
    Member() {};
    Member(string name, string phone) {
        this->name = name;
        this->phone = phone;
    }

    virtual void viewAllHouses();
    virtual void viewInformation();
    virtual void searchHouses();
    virtual void requestOccupy();
};

class Owner: public Member {
private:
    vector<House *> house;
    
public:
    // Constructor
    Owner() {};
    Owner(string name, string phone) : Member(name, phone) {}

    void listHouse() {
        fstream file;
        string path = "D:/Code/C++ RMIT/EEET2824/data/house.txt";
    };
    void unListHouse();
    void acceptRequest();
    void rateOccupier();
};

class Occupy: public Member {
private:
    float occupierRating;
    bool isRequest;
    vector <History> history;

public:
    void rateHouse();
    void requestOccupy();
    void checkRequest();
    void showHistory();
    void addHistory();
};
