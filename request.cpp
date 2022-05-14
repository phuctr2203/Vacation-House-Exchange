#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>
#include "house.h"
#include "member.h"
#include "request.h"

using namespace std;

Request::Request() {}
Request::Request(string owner_req, string occupier_req, string isRequest) {
    this->owner_req = owner_req;
    this->occupier_req = occupier_req;
    this->isRequest = isRequest;
}

string Request::getOwnerRequest() {
    return owner_req;
}

string Request::getOccupierRequest() {
    return occupier_req;
}

string Request::getIsRequest() {
    return isRequest;
}

void Request::setOwnerRequest(string a) {
    owner_req = a;
}

void Request::setOccupierRequest(string a) {
    occupier_req = a;
}

void Request::setIsRequest(string a) {
    isRequest = a;
};

// show info of request
void Request::requestInformation() {
    cout << "\nOwner: " << owner_req <<
            "\nOccupier Request: " << occupier_req <<
            "\nRequest Status: " << isRequest << endl;
}

// create a vector of Request list
vector<Request>tempRequestMemory(){
    vector<Request> requestList;

    ifstream iFile("request.txt");
    if (iFile.fail())
    {
        cout << "Fail to open file";
    }

    while (!iFile.eof())
    {
        string owner;
        string occupier;
        string isRequest;

        string file_string;
        getline(iFile, file_string);
        stringstream ss(file_string);
        getline(ss, owner, ',');
        getline(ss, occupier, ',');
        getline(ss, isRequest, ',');

        Request request1(owner, occupier, isRequest);
        requestList.push_back(request1);
    }
    iFile.close();
    return requestList;
}

//Menu for request house
void requestMenu(vector<House> house_list, Member a) {
    int choose;

    chooseOption:
    cout << "\nChoose an options: "
            "\n1. View Review"
            "\n2. Request occupy"
            "\n3. Reject current request"
            "\n\nEnter your choice: ";
    cin >> choose;
    switch (choose) {
        case 1:
        {
            cout << "Please enter house name you want to see review: ";
            break;
        }
        case 2:
        {
            if (Occupy_House_Condition(a.getUsername())) {
                requestSearchHouse(house_list, a);
            } else {
                cout << "cut" << endl;
            }
            break;
        }
        case 3:
        {
            break;
        }
        default:
        {
            cout << "Please enter a valid choice" << endl;
            goto chooseOption;
        }
    }
}

// Request searched house
void requestSearchHouse(vector<House> houseList, Member currentMem) {
    vector<Request> requestList = tempRequestMemory();
    House house_choose;
    Request request_pick;
    string house_name_input;

    cout << "Please enter house name you want to occupy: ";
    cin.ignore();
    getline(cin, house_name_input);

    house_choose = housePick(house_name_input);

    request_pick.setOwnerRequest(house_choose.getOwner());
    request_pick.setOccupierRequest(currentMem.getUsername());
    request_pick.setIsRequest("no");

    requestList.push_back(request_pick);

    ofstream oFile("request.txt", std::ofstream::trunc);
    for (int i = 0; i < requestList.size(); i++) {
        string owner_req = requestList[i].getOwnerRequest();
        string occupier_req = requestList[i].getOccupierRequest();
        string isRequest = requestList[i].getIsRequest();

        if (i != requestList.size() - 1) {
            oFile << owner_req << ","
            << occupier_req << ","
            << isRequest << endl;
        } else {
            oFile << owner_req << ","
            << occupier_req << ","
            << isRequest;         
        }
    }

    cout << "Request house successfully" << endl;
}





