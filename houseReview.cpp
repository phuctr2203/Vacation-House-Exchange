#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <numeric>
#include "houseReview.h"

using namespace std;

houseReview::houseReview(){};
houseReview::houseReview(string occupierReviewer, string commentHouse, string reviewHouseName, double reviewRate)
{
    this->occupierReviewer = occupierReviewer;
    this->commentHouse = commentHouse;
    this->reviewHouseName = reviewHouseName;
    this->reviewRate = reviewRate;
}

string houseReview::getOccupierReviewer()
{
    return occupierReviewer;
}

string houseReview::getCommentHouse()
{
    return commentHouse;
}

string houseReview::getReviewHouseName()
{
    return reviewHouseName;
}

double houseReview::getReviewRate()
{
    return reviewRate;
}

//View House Review
void houseReview::showHouseReview()
{
    cout
    << "\nReviewer: " << occupierReviewer
    << "\nComment: " << commentHouse
    << "\nHouse Review Name: " << reviewHouseName 
    << "\nRating: " << reviewRate << endl;
}

void houseReview::addCommentHouse() 
{

}

void houseReview::addReviewRate() 
{

}

//List of House Review to VEC
vector<houseReview> tempHouseReview(){
    vector<houseReview> houseReviewList;

    ifstream iFile("reviewHouse.txt");
    if (iFile.fail())
    {
        cout << "Fail to open file";
    }

    while (!iFile.eof())
    {
        string occupierReviewer;
        string commentHouse;
        string reviewHouseName;
        string reviewRate_str;
        string file_string;
        getline(iFile, file_string);
        stringstream ss(file_string);
        getline(ss, occupierReviewer, ',');
        getline(ss, commentHouse, ',');
        getline(ss, reviewHouseName, ',');
        
        double reviewRate;
        getline(ss, reviewRate_str, ',');
        reviewRate = stod(reviewRate_str);

        houseReview houseReview1(occupierReviewer, commentHouse, reviewHouseName, reviewRate);
        houseReviewList.push_back(houseReview1);
    }
    iFile.close();
    return houseReviewList;
}

//View All House Review
void viewAllHouseReview() 
{
    vector<houseReview> houseReviewList = tempHouseReview();

    for (int i = 0; i < houseReviewList.size(); i++) {
        houseReviewList[i].showHouseReview();
    }
}

//Show House Review According to House Name
vector<houseReview>viewHouseReview(string reviewHouseName) {
    vector<houseReview> houseReviewList = tempHouseReview();
    vector<houseReview> houseNameList;

    for (int i = 0; i < houseReviewList.size(); i++)
    {
        if (reviewHouseName == houseReviewList[i].getReviewHouseName())
        {
            houseNameList.push_back(houseReviewList[i]);
        }
    }

    for (int i = 0; i < houseNameList.size(); i++)
    {
        houseNameList[i].showHouseReview();
    }
    
    return houseNameList;
}

//Get house review rate according to house name
vector<houseReview>getHouseRate(string reviewHouseName) {
    vector<houseReview> houseReviewList = tempHouseReview();
    vector<houseReview> houseNameList;

    for (int i = 0; i < houseReviewList.size(); i++)
    {
        if (reviewHouseName == houseReviewList[i].getReviewHouseName())
        {
            houseNameList.push_back(houseReviewList[i]);
        }
    }
    
    return houseNameList;
}

//calculate new house rating base on review
double calRating(string reviewHouseName)
{
    double houseRate_avg = 0;
    double sum_of_houseRate = 0;
    vector<double> houseRate;
    vector<houseReview> houseNameList = getHouseRate(reviewHouseName);

    for (int i = 0; i < houseNameList.size(); i++)
    {
        houseRate.push_back(houseNameList[i].getReviewRate());
    }

    sum_of_houseRate = accumulate(houseRate.begin(), houseRate.end(),decltype(houseRate)::value_type(0));

    houseRate_avg = sum_of_houseRate/houseNameList.size();

    return houseRate_avg;
}

/*int main() {
    string reviewHouseName;
    vector<houseReview> houseNameList;

    cout << "\nEnter House Name: ";
    getline(cin, reviewHouseName);
    houseNameList = viewHouseReview(reviewHouseName);
    cout << calRating(reviewHouseName) << endl;
}*/
