#include <iostream>
#include "member.h"
#include "admin.h"
#include "house.h"
#include "non_member.h"
 
using namespace std;

int main() {
    int choose;
    cout << "EEET2482/COSC2082 ASSIGNMENT"
            "\nVACATION HOUSE EXCHANGE APPLICATION"
            "\n \nInstructor: Mr. Linh Tran "
            "\nGroup: Group 18 "
            "\ns3911244, Tran Hoang Phuc "
            "\ns3883631, Nguyen Huy Binh "
            "\ns3883630, Nguyen Tri Dung "
            "\ns3927089, Trinh Thanh Thanh Truc " << endl;
    cout << "Use the app as 1. Guest   2. Member   3. Admin" 
            "\nEnter your choice: " << endl;

    cin >> choose;
    switch (choose) {
        case 1: 
        {
            //nonMember nonmem;
            cout << "This is your menu as a guest:"
                    "\n1. View Houses"
                    "\n2. Sign Up"
                    "\nEnter your choice: " <<endl;
            int choice;
            cin >> choice;
            if (choice == 1) 
            {
                viewAllHouses(); break;
            } else {
                signUp(); break;
            }
        }
        case 2: 
        {
            cout << "Member Sign in!" << endl;
            signIn(); 
            break; 
        }
        case 3: 
        {
            cout << "Admin Sign in!" << endl;
            adminSignIn(); 
            break;
        }
        default: cout << "Cut" << endl; break;
    }

    return 0;
}
