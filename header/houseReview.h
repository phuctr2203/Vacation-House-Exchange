#ifndef _HOUSEREVIEW_H_
#define _HOUSEREVIEW_H_
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <cmath>
#include "house.h"

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

    double getReviewRate();

    string getReviewHouseName();

    void setOccupierReviewer(string a);

    void setCommentHouse(string a);

    void setReviewHouseName(string a);

    void setReviewRate(double a);

    void showHouseReview();

};

void viewAllHouseReview();

vector<houseReview>tempHouseReview();

vector<houseReview>viewHouseReview();

vector<houseReview>getHouseRate(string reviewHouseName);

void addReview(House review_house);

double calRating(string reviewHouseName);

void updateRating(House current_occupied_house_user);

#endif
