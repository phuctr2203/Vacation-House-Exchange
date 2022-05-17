#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <numeric>
#include <iomanip>
#include <cmath>
#include "..\header\houseReview.h"
#include "..\header\house.h"
#include "..\header\member.h"

using namespace std;
using std::cout;
using std::cin;

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

void houseReview::setOccupierReviewer(string a)
{
    occupierReviewer = a;
}

void houseReview::setCommentHouse(string a)
{
    commentHouse = a;
}

void houseReview::setReviewHouseName(string a)
{
    reviewHouseName = a;
}

void houseReview::setReviewRate(double a)
{
    reviewRate = a;
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

//List of House Review to VEC
vector<houseReview> tempHouseReview(){
    vector<houseReview> houseReviewList;

    ifstream iFile("houseReview.txt");
    if (iFile.fail())
    {
        cout << "Fail to open file";
    }
    if(iFile.peek() == std::ifstream::traits_type::eof())
    {
        cout << "";
    }
    else
    {

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
    }
    iFile.close();
    return houseReviewList;
}

//View All Review
void viewAllHouseReview() 
{
    vector<houseReview> houseReviewList = tempHouseReview();

    for (int i = 0; i < houseReviewList.size(); i++) {
        houseReviewList[i].showHouseReview();
    }
}

//Show House Review According to House Name
vector<houseReview>viewHouseReview() {
    vector<houseReview> houseReviewList = tempHouseReview();
    vector<houseReview> houseNameList;
    string reviewHouseName;

    if (is_empty_file("houseReview.txt")) {
        cout << "There's no review available at the moment!" << endl;
    } else {
            
        cout << "Please enter house name you want to view review: ";
        cin.ignore();
        getline(cin, reviewHouseName);

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

    houseRate_avg = round(sum_of_houseRate/houseNameList.size() * 10) / 10;

    return houseRate_avg;
}

void updateRating(House current_occupied_house_user){
    vector<House> currentHouseList = tempHouseMemory();

    double ave = calRating(current_occupied_house_user.getHouseName());
    for(int i = 0; i < currentHouseList.size(); i++)
    {
        if(current_occupied_house_user.getHouseName() == currentHouseList[i].getHouseName())
        {
            currentHouseList[i].setHouseRating(ave);
        }
    }

    ofstream houseFile("houseList.txt", std::ofstream::trunc);
    for (int i = 0; i < currentHouseList.size(); i++) {
        string owner = currentHouseList[i].getOwner();
        string occupier = currentHouseList[i].getOccupier();
        string houseName = currentHouseList[i].getHouseName();
        string location = currentHouseList[i].getLocation();
        int creditPrice = currentHouseList[i].getCreditPrice();
        double houseRating = currentHouseList[i].getHouseRating();
        double requiredRating = currentHouseList[i].getRequiredRating();

        if (i != currentHouseList.size() - 1) {
            houseFile << owner << ","
            << occupier << ","
            << houseName << ","
            << location << ","
            << creditPrice << ","
            << houseRating << ","
            << requiredRating << endl;
        } else {
            houseFile << owner << ","
            << occupier << ","
            << houseName << ","
            << location << ","
            << creditPrice << ","
            << houseRating << ","
            << requiredRating;
        }
    }
    houseFile.close();
}

void addReview(House review_house) {
    vector<houseReview> reviews = tempHouseReview();
    
    string review_input;
    double rating_house_input;
    houseReview newReview;

    cout << "\nShare your review: ";
    cin.ignore();
    getline(cin, review_input);

    cout << "\nRating this house from -10 to 10: ";
    cin >> rating_house_input;
    while (rating_house_input < -10 || rating_house_input > 10) {
        cout <<"\nInvalid input!"
             <<"Please rating again from -10 to 10: ";
        cin >> rating_house_input;
    }

    newReview.setOccupierReviewer(review_house.getOccupier());
    newReview.setCommentHouse(review_input);
    newReview.setReviewHouseName(review_house.getHouseName());
    newReview.setReviewRate(rating_house_input);

    reviews.push_back(newReview);

    ofstream oFile("houseReview.txt", std::ofstream::trunc);
    for(int i = 0; i < reviews.size(); i++)
    {
        string occupierReviewer =reviews[i].getOccupierReviewer();
        string commentHouse = reviews[i].getCommentHouse();
        string reviewHouseName =reviews[i].getReviewHouseName();
        double reviewRating = reviews[i].getReviewRate();

        if(i != reviews.size() - 1){
            oFile << occupierReviewer << "," 
                << commentHouse << "," 
                << reviewHouseName << "," 
                << reviewRating << endl;
        } else {
            oFile << occupierReviewer << "," 
                    << commentHouse << "," 
                    << reviewHouseName << "," 
                    << reviewRating;
        }
    }

    oFile.close();
    cout << "Review complete" << endl;
}
