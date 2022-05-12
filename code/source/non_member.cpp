#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "member.cpp"

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
    //Constructor
    nonMember() {};
    nonMember(string username, string password, string name, string phone)
    {
        this->username = username;
        this->password = password;
        this->name = name;
        this->phone = phone;
    }

    string getUsername(){
        return username;
    }

    void signUp() {
        int locationPick;

        // Registration
        nonMember newMember;
        vector<Member> mem;
  

        //check input
        int condition_true = 0;
        int count = 0;

        cout << "----- Register Account -----" << endl;

        do{
            string username_input;
            if(count == 0)
            {
                cout << "Please enter username: " << endl;
                cin >> username_input;
            }
            else{
                cout << "Username is not available, please use other username." << endl;
                cout << "\nPlease enter username: ";
                cin >> username_input;
            }

            for(int i = 0; i < mem.size(); i++)
            {
                if(mem[i].getUsername() != username_input)
                {
                    cin >> newMember.username;
                    condition_true++;
                }

            cout << "Please enter password: " << endl;
            cin >> newMember.password;

            cout << "Please enter you full name: " << endl;
            cin >> newMember.name;

            cout << "Please enter phone numbera: " << endl;
            cin >> newMember.phone;
            }
            count++;
        }while(condition_true == 0);
        
        
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
        ofstream oFile("member.txt", std::ofstream::trunc);
        for(int i = 0; i < mem.size(); i++)
        {
            oFile << newMember.username << ", " << newMember.password << ", " << newMember.name << ", " << newMember.phone << ", " << newMember.creditPoints << "," << newMember.rating << endl;
            oFile.close();
        }
        cout << "Registration complete" << endl;
        }
    
    void viewAllHouses();
};
