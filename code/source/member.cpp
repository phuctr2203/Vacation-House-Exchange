#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>

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
    Member(){}
    Member(string username, string password, string name, string phone, int creditPoints, double RatingScore)
    {
        this->username = username;
        this->password = password;
        this->name = name;
        this->phone = phone;
        this->creditPoints = creditPoints;
        this->RatingScore = RatingScore;
    }

    string getUsername(){
        return username;
    }

    string getPwd(){
        return password;
    }

    string getNameUser(){
        return name;
    }

    string getPhoneUser(){
        return phone;
    }

    int getCreditPoints()
    {
        return creditPoints;
    }

    double getRatingScore()
    {
        return RatingScore;
    }

    void addPoint(int a)
    {
        creditPoints += a;
    }

    void addRatingScore(double a)
    {
        RatingScore += a;
    }

    void viewAllHouses(){

    }

    void viewInformation(){      
        cout << "\nUsername: " << username 
        << "\nPassword: " << password 
        << "\nName: "<< name 
        << "\nPhone: "<< phone 
        << "\nCredit Points: " << creditPoints 
        << "\nRating Score: " << RatingScore << endl;
    }

    void searchHouses();
    void requestOccupy();
};

void signIn() {
    vector<Member> mem;

    ifstream iFile("D:/Code/C++ RMIT/EEET2824/data/member.txt");
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
        int creditPoints;
        double RatingScore;
        char ch;
        stringstream ss;
        string file_string;
        getline(iFile, file_string);
        ss << file_string;
        ss >> username >> password >> name >> phone >> creditPoints >> ch >> RatingScore;
        if (!username.empty()){
            username.pop_back();
        }

        if (!password.empty()){
            password.pop_back();
        }

        if (!name.empty()){
            name.pop_back();
        }

        if (!phone.empty()){
            phone.pop_back();
        }

        Member member1(username, password, name, phone, creditPoints, RatingScore);
        mem.push_back(member1);
    }
    iFile.close();

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
