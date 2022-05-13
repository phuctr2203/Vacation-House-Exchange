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
    vector<houseReview> housereview;

    ifstream iFile ("D:/Code/C++ RMIT/EEET2824/data/review.txt");

    if (iFile.fail())
    {
        cout << "Fail to open file!";
    }

    while (!iFile.eof())
    {
        string name;
        double score;
        string comment;
        char ch;
        stringstream ss;
        string file_string;
        getline(iFile, file_string);
        ss << file_string;
        ss >> name >> score >> ch >> comment;

        if (!name.empty()) 
        {
            name.pop_back();
        }

        if (!score.empty())
        {
            score.pop_back();
        }

        if (!comment.empty())
        {
            comment.pop_back();
        }

        houseReview housereview1 (name, score, comment);
        housereview.push_back(housereview1);
    }
    iFile.close();

    for (int i = 0; i < housereview.size(), i++) 
    {
        housereview[i].showHouseReview();
    }

    ofstream oFile ("D:/Code/C++ RMIT/EEET2824/data/review.txt");
    for (int i = 0; i < housereview.size(), i++) 
    {
        string name = housereview[i].getName();
        double score = housereview[i].getScore();
        string comment = housereview[i].getCmt();

        if (i != housereview.size())
        {
            oFile
            << name << ", "
            << score << ", "
            << comment << endl;
        }
        else
        {
            oFile
            << name << ", "
            << score << ", "
            << comment;
        }
    }
    oFile.close();
}

int main() {
    cout << "\n\n---- HOUSE REVIEW ----"
            "\nThese are reviews for " << name << " house"
            "\nDo you want to: "
            "\n1. Rating the house"
            "\n2. Comment the house" 
            "\n3. View the reviews"<<endl;
    int choice;
    cin >> choice;
    if (choice == 1)
    {
        addHouseScore();
        break;
    } else if (choice == 2)
    {
        addHouseCmmt();
        break;
    }else if (choice == 3)
    {
        viewAllHouseReview();
        break;
    }

    return 0;
}
