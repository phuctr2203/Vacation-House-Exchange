#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class nonMember {
private:
    string username;
    string password;
    string name;
    string phone;
    int creditPoints = 500;
    double rating = 0;

public:
    void signUp() {
        int locationPick;

        // Registration
        nonMember newMember;

        fstream file;
        string path = "D:/Code/C++ RMIT/EEET2824/data/member.txt";

        cout << "----- Register Account -----" << endl;
        cout << "Please enter username: " << endl;
        cin >> newMember.username;

        cout << "Please enter password: " << endl;
        cin >> newMember.password;

        cout << "Please enter you full name: " << endl;
        cin >> newMember.name;

        cout << "Please enter phone numbera: " << endl;
        cin >> newMember.phone;
        
        /*
        cout << "Choose house location (1 to 3): " << endl;
        cout << "Our app is only available for current cities below: " << endl;
        cout << " 0. None\n 1. Hanoi\n 2. Saigon\n 3. Da Nang" << endl;
        cin >> locationPick;
        switch (locationPick) {
            case 1: newMember->houseLocation = "Hanoi";
                    break;
            case 2: newMember->houseLocation = "Saigon";
                    break;
            case 3: newMember->houseLocation = "Da Nang";
                    break;
            default: cout << "Please comeback soon!" << endl; exit(0);
        }
        
        descriptionPick:
        cout << "Please enter house description (rating from -10 to 10): " << endl;
        cin >> newMember->houseDescription;
        if (newMember->houseDescription < -10 || newMember->houseDescription > 10) {
            goto descriptionPick;
        }
        */

        newMember.creditPoints = 500;
          
        //Store into the system
        file.open(path, ios::app);
        if (file.is_open()) {
            file << newMember.username << "," << newMember.password << "," << newMember.name << "," << newMember.phone << "," << newMember.creditPoints << newMember.name << "," << newMember.rating << endl;
            file.close();
        }
        cout << "Registration complete" << endl;
        }
    
    void viewAllHouses();
};

int main() {
    nonMember *newMember = new nonMember();
    newMember->signUp();

    return 0;
}
