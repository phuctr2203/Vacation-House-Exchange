#ifndef _HOUSEREVIEW_H_
#define _HOUSEREVIEW_H_
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class houseReview {
private:
    string occupierReviewer;
    string commentHouse;
    string reviewHouseName;
    double reviewRate;
public:
    houseReview();
    houseReview(string occupierReviewer, string commentHouse, string reviewHouseName, double reviewRate);

    string getOccupierReviewer();
    string getCommentHouse();
    string getReviewHouseName();
    double getReviewRate(); 

    void showHouseReview();
    void addCommentHouse();
    void addReviewRate();
    void calRating();
};

void viewAllHouseReview();

vector<houseReview>tempHouseReview();
vector<houseReview>viewHouseReview(string reviewHouseName);


#endif
