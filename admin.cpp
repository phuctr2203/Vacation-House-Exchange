#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>
#include "member.h"
#include "admin.h"
#include "house.h"

using namespace std;

    Admin::Admin() {}
    Admin::Admin(string username, string password) {
        this->username = username;
        this->password = password;
    }

    string username = "admin";
    string password = "admin";

void adminSignIn() {
    int choose;

    start:
    cout << "Enter admin username: " << endl;
    cin >> username;
    cout << "Enter admin password: " << endl;
    cin >> password;
    
    if (username != "admin" && password != "admin") {
        cout << "Incorrect admin username or password!";
        goto start;
    } else {
        cout << "This is your menu as an admin: "
                "\n1. View all members"
                "\n2. View all houses" << endl;
        cin >> choose;
        choose:
        switch (choose) {
            case 1: viewAllMembers(); break;
            case 2: viewAllHouses(); break;

            default: cout << "Please choose 1 or 2" << endl;
                    goto choose;
        }
    }
}