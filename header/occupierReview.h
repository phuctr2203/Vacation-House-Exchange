#ifndef _REVIEWOCCUPIER_H_
#define _REVIEWOCCUPIER_H_
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <cmath>
#include "member.h"

using namespace std;

class occupierReview {
private:
    string hostReviewer;
    string commentOccupier;
    string reviewOccupierName;
    double reviewRate;
public:
    occupierReview();
    occupierReview(string hostReviewer, string commentOccupier, string reviewOccupierName, double reviewRate);

    string getHostReviewer();

    string getCommentOccupier();

    string getReviewOccupierName();

    double getReviewRate();

    void setHostReviewer(string a);

    void setCommentOccupier(string a);

    void setReviewOccupierName(string a);

    void setReviewRate(double a);

    void showOccupierReview();

};

void viewAllOccupierReview();

vector<occupierReview> tempOccupierReview();

vector<occupierReview>viewOccupierReview();

vector<occupierReview>getOccupierRate(string reviewOccupierName);

double calOccupierRating(string reviewOccupierName);

void updateOccupierRating(Member current_occupied_house_user);

void addOccupierReview(Member review_member);

Member getOccupierInfo(string owner_username);

#endif
