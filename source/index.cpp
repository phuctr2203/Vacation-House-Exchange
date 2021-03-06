#include <iostream>
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
