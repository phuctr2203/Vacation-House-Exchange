#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>
#include "..\header\member.h"
#include "..\header\admin.h"
#include "..\header\house.h"
#include "..\header\non_member.h"
#include "..\header\editHouse.h"
#include "..\header\request.h"
#include "..\header\houseReview.h"
#include "..\header\occupierReview.h"
#include "..\header\data.h"

using namespace std;

void saveData() {
    vector<Member> member = tempMemory();
    vector<House> house = tempHouseMemory();
    vector<Request> request = tempRequestMemory();
    vector<houseReview> houseReview = tempHouseReview();
    vector<occupierReview> occupierReview = tempOccupierReview();
    
    ofstream oFile("data.txt");
    // Write Member file
    for(int i = 0; i < member.size(); i++)
    {
        string username =member[i].getUsername();
        string password = member[i].getPwd();
        string name =member[i].getNameUser();
        string phone =member[i].getPhoneUser();
        int creditPoints =member[i].getCreditPoints();
        double RatingScore = member[i].getRatingScore();

            oFile << username << "," 
                    << password << "," 
                    << name << "," 
                    << phone << "," 
                    << creditPoints <<","
                    << RatingScore << endl;
    }
    // Write house file
    for (int i = 0; i < house.size(); i++) {
        string owner = house[i].getOwner();
        string occupier = house[i].getOccupier();
        string houseName = house[i].getHouseName();
        string location = house[i].getLocation();
        int creditPrice = house[i].getCreditPrice();
        double houseRating = house[i].getHouseRating();
        double requiredRating = house[i].getRequiredRating();

            oFile << owner << ","
            << occupier << ","
            << houseName << ","
            << location << ","
            << creditPrice << ","
            << houseRating << ","
            << requiredRating << endl;
    }
    
    // Write house review file
    for(int i = 0; i < houseReview.size(); i++)
    {
        string occupierReviewer =houseReview[i].getOccupierReviewer();
        string commentHouse = houseReview[i].getCommentHouse();
        string reviewHouseName =houseReview[i].getReviewHouseName();
        double reviewRating = houseReview[i].getReviewRate();

            oFile << occupierReviewer << "," 
                    << commentHouse << "," 
                    << reviewHouseName << "," 
                    << reviewRating << endl;
    }

    // Write request file
    for (int i = 0; i < request.size(); i++) {
        string owner_req = request[i].getOwnerRequest();
        string occupier_req =request[i].getOccupierRequest();
        string house_req = request[i].getHouseReq();
        string isRequest = request[i].getIsRequest();


            oFile << owner_req << ","
            << occupier_req << "," 
            << house_req << ","
            << isRequest << endl;
    }    

    // Write occupier review file
    for(int i = 0; i < occupierReview.size(); i++)
    {
        string occupierReviewer = occupierReview[i].getHostReviewer();
        string commentHouse = occupierReview[i].getCommentOccupier();
        string reviewHouseName = occupierReview[i].getReviewOccupierName();
        double reviewRating = occupierReview[i].getReviewRate();

            oFile << occupierReviewer << "," 
            << commentHouse << "," 
            << reviewHouseName << "," 
            << reviewRating << endl;
    }
}

