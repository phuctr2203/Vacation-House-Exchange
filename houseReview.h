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
    string name;
    double score;
    string comment;
public:
    houseReview();
    houseReview(string name, double score, string comment);

    string getName();
    double getScore();
    string getCmt();

    void showHouseCmt();
    void addHouseCmt();
    void addHouseScore();
    void updateReview();
};

void viewAllHouseReview();

#endif
