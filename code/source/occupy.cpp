#include <iostream>
#include <vector>
#include "history.cpp"

using namespace std;

class occupy {
private:
    float occupierRating;
    bool isRequest;
    vector <history> history;

public:
    void rateHouse();
    void requestOccupy();
    void checkRequest();
    void showHistory();
    void addHistory();
};
