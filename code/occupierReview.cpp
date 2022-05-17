#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <numeric>
#include <iomanip>
#include <cmath>
#include "..\header\occupierReview.h"
#include "..\header\house.h"
#include "..\header\member.h"

using namespace std;
using std::cout;
using std::cin;

occupierReview::occupierReview(){};
occupierReview::occupierReview(string hostReviewer, string commentOccupier, string reviewOccupierName, double reviewRate)
{
    this->hostReviewer = hostReviewer;
    this->commentOccupier = commentOccupier;
    this->reviewOccupierName = reviewOccupierName;
    this->reviewRate = reviewRate;
}

string occupierReview::getHostReviewer()
{
    return hostReviewer;
}

string occupierReview::getCommentOccupier()
{
    return commentOccupier;
}

string occupierReview::getReviewOccupierName()
{
    return reviewOccupierName;
}

double occupierReview::getReviewRate()
{
    return reviewRate;
}

void occupierReview::setHostReviewer(string a)
{
    hostReviewer = a;
}

void occupierReview::setCommentOccupier(string a)
{
    commentOccupier = a;
}

void occupierReview::setReviewOccupierName(string a)
{
    reviewOccupierName = a;
}

void occupierReview::setReviewRate(double a)
{
    reviewRate = a;
}

//View occupier Review
void occupierReview::showOccupierReview()
{
    cout
    << "\nHouse Host: " << hostReviewer
    << "\nComment: " << commentOccupier
    << "\nHouse Name: " << reviewOccupierName 
    << "\nRating: " << reviewRate << endl;
}

vector<occupierReview> tempOccupierReview(){
    vector<occupierReview> occupierReviewList;

    ifstream iFile("occupierReview.txt");
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
            string hostReviewer;
            string commentOccupier;
            string reviewOccupierName;
            string reviewRate_str;
            string file_string;
            getline(iFile, file_string);
            stringstream ss(file_string);
            getline(ss, hostReviewer, ',');
            getline(ss, commentOccupier, ',');
            getline(ss, reviewOccupierName, ',');
            
            double reviewRate;
            getline(ss, reviewRate_str, ',');
            reviewRate = stod(reviewRate_str);

            occupierReview occupierReview1(hostReviewer, commentOccupier, reviewOccupierName, reviewRate);
            occupierReviewList.push_back(occupierReview1);
        }
    }
    iFile.close();
    return occupierReviewList;
}

//View All Review
void viewAllOccupierReview() 
{
    vector<occupierReview> occupierReviewList = tempOccupierReview();

    for (int i = 0; i < occupierReviewList.size(); i++) {
        occupierReviewList[i].showOccupierReview();
    }
}

//Show Occupier Review According to Occupier Name
vector<occupierReview>viewOccupierReview() {
    vector<occupierReview> occupierReviewList = tempOccupierReview();
    vector<occupierReview> occupierNameList;
    string reviewOccupierName;

    if (is_empty_file("occupierReview.txt") == true) {
        cout << "There's no review available at the moment!" << endl;
    } else {
            
        cout << "Please enter occupier name you want to view review: ";
        cin.ignore();
        getline(cin, reviewOccupierName);

        for (int i = 0; i < occupierReviewList.size(); i++)
        {
            if (reviewOccupierName == occupierReviewList[i].getReviewOccupierName())
            {
                occupierNameList.push_back(occupierReviewList[i]);
            }
        }

        for (int i = 0; i < occupierNameList.size(); i++)
        {
            occupierNameList[i].showOccupierReview();
        }
    }    
    return occupierNameList;
}

//Get occupier review rate according to occupier name
vector<occupierReview>getOccupierRate(string reviewOccupierName) {
    vector<occupierReview> occupierReviewList = tempOccupierReview();
    vector<occupierReview> occupierNameList;

    for (int i = 0; i < occupierReviewList.size(); i++)
    {
        if (reviewOccupierName == occupierReviewList[i].getReviewOccupierName())
        {
            occupierNameList.push_back(occupierReviewList[i]);
        }
    }
    
    return occupierNameList;
}

//calculate new house rating base on review
double calOccupierRating(string reviewOccupierName)
{
    double occupierRate_avg = 0;
    double sum_of_occupierRate = 0;
    vector<double> occupierRate;
    vector<occupierReview> occupierNameList = getOccupierRate(reviewOccupierName);

    for (int i = 0; i < occupierNameList.size(); i++)
    {
        occupierRate.push_back(occupierNameList[i].getReviewRate());
    }

    sum_of_occupierRate = accumulate(occupierRate.begin(), occupierRate.end(),decltype(occupierRate)::value_type(0));

    occupierRate_avg = round(sum_of_occupierRate/occupierNameList.size() * 10) / 10;

    return occupierRate_avg;
}

//Update occupier rating 
void updateOccupierRating(Member current_occupied_house_user){
    vector<Member> currentMemberList = tempMemory();

    double ave = calOccupierRating(current_occupied_house_user.getUsername());
    for(int i = 0; i < currentMemberList.size(); i++)
    {
        if(current_occupied_house_user.getUsername() == currentMemberList[i].getUsername())
        {
            currentMemberList[i].setRatingScore(ave);
        }
    }

    ofstream memFile("member.txt", std::ofstream::trunc);
    for (int i = 0; i < currentMemberList.size(); i++) {
        string username = currentMemberList[i].getUsername();
        string password = currentMemberList[i].getPwd();
        string name = currentMemberList[i].getNameUser();
        string phone = currentMemberList[i].getPhoneUser();
        int creditPoints = currentMemberList[i].getCreditPoints();
        double ratingScore = currentMemberList[i].getRatingScore();

        if (i != currentMemberList.size() - 1) {
            memFile << username << ","
            << password << ","
            << name << ","
            << phone << ","
            << creditPoints << ","
            << ratingScore << endl;
        } else {
            memFile << username << ","
            << password << ","
            << name << ","
            << phone << ","
            << creditPoints << ","
            << ratingScore;
        }
    }
    memFile.close();
}

void addOccupierReview(Member review_member) {
    vector<occupierReview> reviews = tempOccupierReview();
    House houseOwner = viewHousePossess(review_member.getUsername());

    string review_input;
    double rating_input;
    occupierReview newReview;

    cout << "\nShare your review: ";
    cin.ignore();
    getline(cin, review_input);

    cout << "\nRating this occupier from -10 to 10: ";
    cin >> rating_input;
    while (rating_input < -10 || rating_input > 10) {
        cout <<"\nInvalid input!"
             <<"Please rating again from -10 to 10: ";
        cin >> rating_input;
    }

    newReview.setHostReviewer(houseOwner.getOwner());
    newReview.setCommentOccupier(review_input);
    newReview.setReviewOccupierName(houseOwner.getOccupier());
    newReview.setReviewRate(rating_input);

    reviews.push_back(newReview);

    ofstream oFile("occupierReview.txt", std::ofstream::trunc);
    for(int i = 0; i < reviews.size(); i++)
    {
        string occupierReviewer = reviews[i].getHostReviewer();
        string commentHouse = reviews[i].getCommentOccupier();
        string reviewHouseName = reviews[i].getReviewOccupierName();
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

Member getOccupierInfo(string owner_username) {
    vector<House> houseList = tempHouseMemory();
    vector<Member> membersList = tempMemory();
    Member occupier_name;

    for (int i = 0; i < houseList.size(); i++) {
        if (houseList[i].getOwner() == owner_username) {
            occupier_name.setUsername(houseList[i].getOccupier());
        }
    }

    for (int i = 0; i < membersList.size(); i++) {
        if (membersList[i].getUsername() == occupier_name.getUsername()) {
            occupier_name.setUsername(membersList[i].getUsername());
            occupier_name.setPwd(membersList[i].getPwd());
            occupier_name.setNameuser(membersList[i].getNameUser());
            occupier_name.setPhone(membersList[i].getPhoneUser());
            occupier_name.setCreditpoints(membersList[i].getCreditPoints());
            occupier_name.setRatingScore(membersList[i].getRatingScore());
        }
    }
    return occupier_name;
}

