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
using std::cout;
using std::cin;

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

//New: function output info of occupiers
void Member::viewInfoOccupier() {
    cout << "\nUsername: " << username 
    << "\nName: "<< name 
    << "\nPhone: "<< phone 
    << "\nRating Score: " << RatingScore << endl;
}

// check if enter correct username and pwd
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

// list all of members
vector<Member>tempMemory(){
    vector<Member> memList;

    ifstream iFile("member.txt");
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
    }
    iFile.close();

    return memList;
}

// return a class of signed in member
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

// show all member info
void viewAllMembers() {
    vector<Member> mem_lists = tempMemory();

    if (mem_lists.size() == 0) {
        cout << "Please sign up to be the first user! :((" << endl;
    } else {
        for (int i = 0; i < mem_lists.size(); i++) {
            mem_lists[i].viewInformation();
        }
    }
}

// search house apropriate with signed in member
void searchHouses(Member x) {
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
            cityList = viewHouseLocation(location, x);
            if(cityList.size() == 0)
            {
                cout << "Cannot find house suitable with your status! :<" << endl;
            }
            else
            {
                requestMenu(cityList, x);
            }
            break;
        }
        case 2: 
        {
            location = "Saigon";
            cityList = viewHouseLocation(location, x);
            if(cityList.size() == 0)
            {
                cout << "Cannot find house suitable with your status! :<" << endl;
            }
            else
            {
                requestMenu(cityList, x);
            }
            break;
        }
        case 3: 
        {
            location = "Danang";
            cityList = viewHouseLocation(location, x);
            
            if(cityList.size() == 0)
            {
                cout << "Cannot find house suitable with your status! :<" << endl;
            }
            else
            {
                requestMenu(cityList, x);
            }
            break;
        }
        case 0:
        {
            saveData();
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

// function when member sign in
void memberSignIn() {
    string username_input, username_password;
    int index;
    
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
        acceptNoti(username_input);
        cout << "\nThis is your menu as a member:"
            "\n1. View Personal Information"
            "\n2. View House Information"
            "\n3. Search House Location"
            "\n4. House Current Occupied" //new
            "\n5. List of Request of House for Occupy" //new
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
                cout << "\nThis is your house information:"
                        "\n1. List house"
                        "\n2. Unlist house"
                        "\n3. Review Current Occupier"
                        "\n4. Check My House Occupy Request"
                        "\n5. Back to Menu"
                        "\n0. Exit" << endl;
                cout << "Enter your choice: ";
                houseEdit:
                cin >> index;
                switch (index) {
                    case 1: 
                    {
                        listHouse(username_input);
                        goto menu;
                    }
                    case 2:
                    {
                        unListHouse(username_input);
                        goto menu;
                    }
                    case 3:
                    {
                        cout << "\n---- Review Occupier ----" << endl;
                        Member occupier;
                        occupier = getOccupierInfo(username_input);
                        addOccupierReview(currentMember);
                        updateOccupierRating(occupier);
                        goto menu;
                    }
                    case 4:
                    {
                        cout << "----- Your Occupy Request List -----" << endl;
                        currentOwnerRequestList(username_input);
                        int choice_owner;
                        choice_owner:
                        cout << "Choose an options: " 
                                "\n1. Accept a request" 
                                "\n2. Back to menu" << endl;
                        cin >> choice_owner;
                        switch(choice_owner) {
                            case 1:
                            {   
                                acceptRequest(username_input);
                                break;
                            }
                            case 2:
                            {
                                goto menu;
                            }
                            default:
                            {
                                cout << "Please choose a choice: " << endl;
                                goto choice_owner;
                            }
                        goto menu;
                        }
                    }
                    case 5:
                    {
                        goto menu;
                    }
                    case 0:
                    {
                        saveData();
                        exit(0);
                        break;
                    }
                    default:
                    {
                        cout << "Please enter valid options" << endl;
                        goto houseEdit;
                    }
                    
                }
                goto menu;
            }
            case 3:
            {
                searchHouses(currentMember);
                goto menu;
            }
            case 4: // new
            {
                int choice1;
                if(!Occupy_House_Condition(username_input))
                {
                    House house_occupied;
                    cout << "\n--- Current Occupied House ---" << endl;
                    house_occupied = viewHouseOccupied(username_input);

                    cout << "\n1. Review House"
                            "\n2. Back to menu" << endl;
                    cin >> choice1;
                    if (choice1 == 1) {
                        cout << "\n---- Review Current Occupied House ----" << endl;
                        addReview(house_occupied);
                        updateRating(house_occupied);
                    } else {
                        goto menu;
                    }                
                }
                else
                {
                    cout << "You are not occupying any houses currently. Please rent a house and come back to review!" << endl;
                }
                goto menu;
            }
            case 5: //new
            {
                if(!Occupy_House_Condition(username_input))
                {
                    cout << "Seem you are occupying a house. Cannot request any house now! Come back later" << endl;
                }
                else
                {
                    cout << "----- Current Request List -----" << endl;
                    currentOccupierRequestList(username_input);
                    int choice;
                    choice:
                    cout << "Choose an options: " 
                            "\n1. Cancel a request" 
                            "\n2. Back to menu" << endl;
                    cin >> choice;
                    switch(choice) {
                        case 1:
                        {   
                            deleteRequest(username_input);
                            break;
                        }
                        case 2:
                        {
                            goto menu;
                        }
                        default:
                        {
                            cout << "Please choose a choice: " << endl;
                            goto choice;
                        }
                    }
                }
                goto menu;
            }
            case 0:
                saveData();
                exit(0);
            default:
            {
                cout << "Please enter a valid choice"<< endl;
                goto menu;
            }
        } 
    }
}

// check occupy house condition of signed in member
bool Occupy_House_Condition(string input_house_occupier)
{
    vector<House> house_listed = tempHouseMemory();
    for(int i = 0; i < house_listed.size(); i++)
    {
        if(input_house_occupier == house_listed[i].getOccupier())
        {
            return false; // already occupying
        }
    }
    return true; // not occupying
}

bool is_empty_file(string file_name)
{
    ifstream iFile(file_name);
    if(iFile.peek() == ifstream::traits_type::eof())
    {
        return true; // == 1 -> file empty
    }
    return false; // == 0 -> file not empty
}