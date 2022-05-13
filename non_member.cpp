#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "non_member.h"
#include "member.h"

using namespace std;


    //Constructor
   /* nonMember::nonMember(){}
    nonMember::nonMember(string username, string password, string name, string phone)
    {
        this->username = username;
        this->password = password;
        this->name = name;
        this->phone = phone;
    }

    string nonMember::getUsername(){
        return username;
    }


    void nonMember::signUp() {
        cout << "Hello" << endl;
        
        //check input
        int condition_true = 0;
        int count = 0;
        vector<Member> mem = tempMemory();
        Member newMember;
        cout << "----- Register Account -----" << endl;
        do{
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
        }while(condition_true == 0);
     
        string pwd_input;
        string name_input;
        string phone_input;
        
        cout << "Please enter password: ";
        cin >> pwd_input;
        newMember.setPwd(pwd_input);

        cout << "Please enter you full name: ";
        cin >> name_input;
        newMember.setNameuser(name_input);


        cout << "Please enter phone numbera: ";
        cin >> phone_input;
        newMember.setPhone(phone_input);

        newMember.setCreditpoints(500);
        newMember.setRatingScore(0);

        mem.push_back(newMember);

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
        cout << "Registration complete" << endl;
    } */
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
        /*
          
        //Store into the system
        ofstream oFile("member.txt", std::ofstream::trunc);
        for(int i = 0; i < mem.size(); i++)
        {
            oFile << newMember.username << ", " << newMember.password << ", " << newMember.name << ", " << newMember.phone << ", " << newMember.creditPoints << "," << newMember.rating << endl;
            oFile.close();
        }
        cout << "Registration complete" << endl;
        }*/
    //void viewAllHouses();

void signUp() {
        cout << "Hello" << endl;
        
        //check input
        int condition_true = 0;
        int count = 0;
        vector<Member> mem = tempMemory();
        Member newMember;
        cout << "----- Register Account -----" << endl;
        do{
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
        }while(condition_true == 0);
     
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

        ofstream oFile("C:/Users/ASUS STRIX/Documents/MYSELF/best_programming/c++ practice class/test_final/sed-group-asm-main/data/member.txt", std::ofstream::trunc);
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
        cout << "Registration complete" << endl;
}