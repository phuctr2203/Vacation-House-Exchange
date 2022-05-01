#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "data.cpp"

using namespace std;

class nonMember {
private:
    string username;
    string password;
public:
    void signUp() {
        // Registration
        fstream file;
        string path = "D:/Code/C++ RMIT/EEET2824/data/member.txt";

        cout << "----- Register Account -----" << endl;
        cout << "Please enter username: " << endl;
        cin >> username;
        cout << "Please enter password: " << endl;
        cin >> password;
        //Store into the system
        
        file.open(path, ios::app);
        if (file.is_open()) {
            file << username << "," << password << endl;
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

