#include <iostream>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "houseReview.h"

using namespace std;

houseReview::houseReview(){};
houseReview(string name, double score, string comment)
{
    this->name = name;
    this->score = score;
    this->comment = comment;
}

string houseReview::getName()
{
    return name;
}

double houseReview::getScore()
{
    return score;
}

string houseReview::getCmt()
{
    return comment;
}

void houseReview::showHouseReview()
{
    cout << "\nHouse Name: " << name
         << "\nHouse Score: " << score
         << "\nHouse Comment: " << comment << endl; 
}

void houseReview::addHouseCmt() 
{

}

void houseReview::addHouseScore() 
{

}

void houseReview::updateReview()
{

}

void viewAllHouseReview() 
{ 

}

int main() {
    cout << "\n\n---- HOUSE REVIEW ----"
            "\nThese are reviews for " << name << " house"
            "\nDo you want to: "
            "\n1. Rating the house"
            "\n2. Comment the house" 
            "\n3. View the reviews for the house"<<endl;
    int choice;
    cin >> choice;
    // if (choice == 1)
    // {
    //     addHouseScore();
    //     break;
    // } else if (choice == 2)
    // {
    //     addHouseCmmt();
    //     break;
    // }else if (choice == 3)
    // {
    //     viewAllHouseReview();
    //     break;
    // }

    return 0;
}
