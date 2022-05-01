#include <iostream>
#include "house.cpp"

using namespace std;

class owner {
private:
    house house;
    
public:
    void list();
    void unList();
    void acceptRequest();
    void rateOccupier();
};
