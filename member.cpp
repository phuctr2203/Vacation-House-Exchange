#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>
#include "member.h"
#include "house.h"

using namespace std;

Member::Member(){}
Member::Member(string username, string password, string name, string phone, int creditPoints, double RatingScore)
{
    this->username = username;
    this->password = password;
    this->name = name;
    this->phone = phone;
    this->creditPoints = creditPoints;
    this->RatingScore = RatingScore;
}

string Member::getUsername(){
    return username;
}

string Member::getPwd(){
    return password;
}

string Member::getNameUser(){
    return name;
}

string Member::getPhoneUser(){
    return phone;
}

int Member::getCreditPoints()
{
    return creditPoints;
}

double Member::getRatingScore()
{
    return RatingScore;
}

void Member::setUsername(string a){
    username = a;
}

void Member::setPwd(string a){
    password = a;
}

void Member::setNameuser(string a){
    name = a;
}

void Member::setPhone(string a){
    phone = a;
}

void Member::setCreditpoints(int a){
    creditPoints = a;
}

void Member::setRatingScore(double a){
    RatingScore = a;
}

void Member::addPoint(int a)
{
    creditPoints += a;
}

void Member::addRatingScore(double a)
{
    RatingScore += a;
}

void Member::viewAllHouses(){

}

void Member::viewInformation(){      
    cout << "\nUsername: " << username 
    << "\nPassword: " << password 
    << "\nName: "<< name 
    << "\nPhone: "<< phone 
    << "\nCredit Points: " << creditPoints 
    << "\nRating Score: " << RatingScore << endl;
}

void Member::searchHouses(){

}

void Member::requestOccupy(){

}

bool signIn(string u_intput, string u_pwd) {
    vector<Member> mem = tempMemory();
    //check input
    bool condition_true = false;
    for(int i = 0; i < mem.size(); i++)
    {
        if(mem[i].getUsername() == u_intput && mem[i].getPwd() == u_pwd)
        {
            condition_true = true;
            return condition_true;
        }
    }
    return condition_true;
}

vector<Member>tempMemory(){
    vector<Member> memList;

    ifstream iFile("member.txt");
    if (iFile.fail())
    {
        cout << "Fail to open file";
    }
    while (!iFile.eof())
    {
        string username;
        string password;
        string name;
        string phone;
        string creditPoints_str;
        string RatingScore_str;
        //char ch;
        string file_string;
        getline(iFile, file_string);
        stringstream ss(file_string);
        getline(ss, username, ',');
        getline(ss, password, ',');
        getline(ss, name, ',');
        getline(ss, phone, ',');

        int creditPoints;
        getline(ss, creditPoints_str, ',');
        creditPoints = stoi(creditPoints_str);

        double RatingScore;
        getline(ss, RatingScore_str, ',');
        RatingScore = stod(RatingScore_str);     

        
        Member member1(username, password, name, phone, creditPoints, RatingScore);
        memList.push_back(member1);
    }
    iFile.close();
    return memList;
}

Member inputUser(string username_int) {
    Member mem_choose;

    vector<Member> mem_total = tempMemory();
    for(int i = 0; i < mem_total.size(); i++)
    {
        if(username_int == mem_total[i].getUsername())
        {
            mem_choose.setUsername(mem_total[i].getUsername());
            mem_choose.setPwd(mem_total[i].getPwd());
            mem_choose.setNameuser(mem_total[i].getNameUser());
            mem_choose.setPhone(mem_total[i].getPhoneUser());
            mem_choose.setCreditpoints(mem_total[i].getCreditPoints());
            mem_choose.setRatingScore(mem_total[i].getRatingScore());
        }
    }
    return mem_choose;
}

void viewAllMembers() {
    vector<Member> mem_lists = tempMemory();

    for (int i = 0; i < mem_lists.size(); i++) {
        mem_lists[i].viewInformation();
    }
}

void searchHouses() {
    int index;
    string location;
    vector<House> cityList;
    
    searchHouse:
    cout << "\nChoose houses location:"
            "\n1. Hanoi"
            "\n2. Saigon"
            "\n3. Danang"
            "\n0. Exit"
            "\n\nEnter your choice: ";
    cin >> index;
    switch (index) {
        case 1: 
        {
            location = "Hanoi";
            cityList = viewHouseLocation(location);
            break;
        }
        case 2: 
        {
            location = "Saigon";
            cityList = viewHouseLocation(location);
            break;
        }
        case 3: 
        {
            location = "Danang";
            cityList = viewHouseLocation(location);
            break;
        }
        case 0:
        {
            exit(0);
            break;
        }
        default: 
        {
            cout <<"\nPlease enter valid choice!" << endl;
            goto searchHouse;
        }
    }
}


void memberSignIn() {
    string username_input, username_password;
    
    cout << "\nEnter username: ";
    cin >> username_input;
    cout << "Enter password: ";
    cin >> username_password;

    while(!signIn(username_input, username_password)) {
        cout << "Wrong username or password. Enter again! " << endl;
        cout << "\nEnter username: ";
        cin >> username_input;
        cout << "Enter password: ";
        cin >> username_password;
    }

    if (signIn(username_input, username_password)) {
        Member currentMember = inputUser(username_input);
        menu:
        cout << "\nThis is your menu as a member:"
            "\n1. View Personal Information"
            "\n2. View House Information"
            "\n3. Search House Location"
            "\n0. Exit"
            "\nEnter your choice: ";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1: 
            {
                currentMember.viewInformation();
                goto menu;
            }
            case 2: 
            {
                viewHousePossess(username_input);
                goto menu;
            }
            case 3:
            {
                searchHouses();
                goto menu;
            }
            case 0:
                exit(0);
            default:
            {
                cout << "Please enter a valid choice"<< endl;
                goto menu;
            }
        } 
    }
}
