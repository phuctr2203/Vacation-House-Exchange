#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "non_member.h"
#include "member.h"
#include "house.h"

using namespace std;

void signUp() {
    
    //check input
    int condition_true = 0;
    int count = 0;
    vector<Member> mem = tempMemory();
    Member newMember;
    cout << "----- Register Account -----" << endl;
    do {
        string username_input;
        if(count == 0)
        {
            cout << "Please enter username: ";
            cin >> username_input;
        }
        else{
            cout << "Username is not available, please use other username." << endl;
            cout << "\nPlease enter username: ";
            cin >> username_input;
        }

        for(int i = 0; i < mem.size(); i++)
        {
            if(username_input == mem[i].getUsername())
            {
                condition_true = 0;
                break;
            }
            else
            {
                condition_true = 1;
            }
        }
        newMember.setUsername(username_input);
        count++;
    }while(condition_true == 0 && mem.size() != 0);
    
    string pwd_input;
    string name_input;
    string phone_input;
    
    cout << "Please enter password: ";
    cin >> pwd_input;
    newMember.setPwd(pwd_input);

    cout << "Please enter you full name: ";
    cin.ignore();
    getline(cin, name_input);
    newMember.setNameuser(name_input);


    cout << "Please enter phone number: ";
    cin >> phone_input;
    newMember.setPhone(phone_input);

    newMember.setCreditpoints(500);
    newMember.setRatingScore(0);

    mem.push_back(newMember);

    ofstream memberFile("member.txt", std::ofstream::trunc);
    for(int i = 0; i < mem.size(); i++)
    {
        string username =mem[i].getUsername();
        string password = mem[i].getPwd();
        string name =mem[i].getNameUser();
        string phone =mem[i].getPhoneUser();
        int creditPoints =mem[i].getCreditPoints();
        double RatingScore = mem[i].getRatingScore();

        if(i != mem.size() - 1){
            memberFile << username << "," 
                << password << "," 
                << name << "," 
                << phone << "," 
                << creditPoints << ","
                << RatingScore << endl;
        } else {
            memberFile << username << "," 
                    << password << "," 
                    << name << "," 
                    << phone << "," 
                    << creditPoints <<","
                    << RatingScore;
        }
    }

    memberFile.close();

    cout << "Registration complete" << endl;
}

void nonMemberMenu() {
    menu:
    cout << "\nThis is your menu as a guest:"
            "\n1. View Houses"
            "\n2. Sign Up"
            "\n3. Exit"
            "\nEnter your choice: " <<endl;
    int choice;
    cin >> choice;
    switch (choice) {
        case 1: 
        {
            viewAllHouses(1); goto menu;
        }
        case 2: 
        {
            signUp(); 
            exit(0);
        }
        case 3:
            exit(0);
        default:
        {
            cout << "Please enter a valid choice"<< endl;
            goto menu;
        }
    }
}