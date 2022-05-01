#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Member {
private:
    int id; 
    string username;
    string password;
    string name;
    string phone;
    int creditPoints = 500;

public:
    bool isSignIn();
    void viewAllHouses();
    void viewInformation();
    void searchHouses();
    void requestOccupy();
};
