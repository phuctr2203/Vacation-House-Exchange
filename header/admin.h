#ifndef _ADMIN_H_
#define _ADMIN_H_
#include <iostream>
#include "member.h"
#include "house.h"

using namespace std;

class Admin {
private:
    string username = "admin";
    string password = "admin";
public:
    Admin();
    Admin(string username, string password);

};

void adminSignIn();

#endif