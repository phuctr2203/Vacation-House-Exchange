#ifndef _MEMBER_H_
#define _MEMBER_H_
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class Member {
private:
    string username;
    string password;
    string name;
    string phone;
    int creditPoints;
    double RatingScore;

public:
    Member();
    Member(string username, string password, string name, string phone, int creditPoints, double RatingScore);

    string getUsername();

    string getPwd();

    string getNameUser();

    string getPhoneUser();

    int getCreditPoints();

    double getRatingScore();

    void setUsername(string a);

    void setPwd(string a);

    void setNameuser(string a);

    void setPhone(string a);

    void setCreditpoints(int a);

    void setRatingScore(double a);

    void addPoint(int a);

    void addRatingScore(double a);

    void viewAllHouses();

    void viewInformation();

    void viewInfoOccupier();

};

bool signIn(string u_intput, string u_pwd);

vector<Member>tempMemory();

Member inputUser(string username_int);

void viewAllMembers();

void memberSignIn();

void searchHouses(Member x);

// check occupy house condition of signed in member
bool Occupy_House_Condition(string input_house_occupier);

bool is_empty_file(string file_name);

#endif
