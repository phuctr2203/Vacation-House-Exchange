#include <iostream>
#include <vector>
#include "review.cpp"
#include "request.cpp"

using namespace std;

class house {
private:
    float houseRating;
    string location;
    string owner;

    float minOccupierRate;
    bool isOccupied;

    vector<request> requestList;
    vector<review> reviewList;

public:
    void viewHistory();
};
