#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>
#include "member.h"

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

    void signIn() {
        vector<Member> mem = tempMemory();

        for(int i = 0; i < mem.size(); i++)
        {
            mem[i].viewInformation();
        }

        //check input
        int condition_true = 0;
        int count = 0;
        do{
            string username_input;
            string username_password;
            if(count == 0)
            {
                cout << "\nEnter username: ";
                cin >> username_input;
                cout << "Enter password: ";
                cin >> username_password;
            }
            else{
                cout << "Wrong username or password. Enter again! " << endl;
                cout << "\nEnter username: ";
                cin >> username_input;
                cout << "Enter password: ";
                cin >> username_password;
            }


            for(int i = 0; i < mem.size(); i++)
            {
                if(mem[i].getUsername() == username_input && mem[i].getPwd() == username_password)
                {
                    mem[i].viewInformation();
                    //mem[i].addPoint(5);
                    //mem[i].addRatingScore(10);
                    condition_true++;
                }
            }
            count++;
        }while(condition_true == 0);

        ofstream oFile("member.txt", std::ofstream::trunc);
        for(int i = 0; i < mem.size(); i++)
        {
            string username =mem[i].getUsername();
            string password = mem[i].getPwd();
            string name =mem[i].getNameUser();
            string phone =mem[i].getPhoneUser();
            int creditPoints =mem[i].getCreditPoints();
            double RatingScore = mem[i].getRatingScore();
            if(i != mem.size() - 1){
                oFile << username << ", " 
                    << password << ", " 
                    << name << ", " 
                    << phone << ", " 
                    << creditPoints << ", "
                    << RatingScore << endl;
            }
            else{
                oFile << username << ", " 
                        << password << ", " 
                        << name << ", " 
                        << phone << ", " 
                        << creditPoints <<", "
                        << RatingScore;
            }
        }
        oFile.close();
    }

    vector<Member> tempMemory(){
        vector<Member> memList;

        ifstream iFile("C:/Users/ASUS STRIX/Documents/MYSELF/best_programming/c++ practice class/test_final/sed-group-asm-main/data/member.txt");
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
