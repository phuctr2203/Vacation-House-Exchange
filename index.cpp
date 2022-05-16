#include <iostream>
#include "member.h"
#include "admin.h"
#include "house.h"
#include "non_member.h"
#include "editHouse.h"
#include "request.h"
#include "houseReview.h"
 
using namespace std;

int main() {
    int choose;
    mainMenu:
    cout << "\nEEET2482/COSC2082 ASSIGNMENT"
            "\nVACATION HOUSE EXCHANGE APPLICATION"
            "\n \nInstructor: Mr. Linh Tran "
            "\nGroup: Group 18 "
            "\ns3911244, Tran Hoang Phuc "
            "\ns3883631, Nguyen Huy Binh "
            "\ns3883630, Nguyen Tri Dung "
            "\ns3927089, Trinh Thanh Thanh Truc " << endl;
    cout << "\nUse the app as 1. Guest   2. Member   3. Admin" 
            "\nEnter your choice: ";

    cin >> choose;
    switch (choose) {
        case 1: 
        {
            nonMemberMenu();
            break;
        }
        case 2: 
        {
            memberSignIn();
            break;
        }
        case 3: 
        {
            adminSignIn(); 
            break;
        }
        default:
        {
            cout << "Please choose 1 to 3!" << endl;
            goto mainMenu;
            break;
        }
    }

    return 0;
}
