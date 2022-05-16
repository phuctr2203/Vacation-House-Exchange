#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>
#include "house.h"
#include "member.h"
#include "request.h"
#include "houseReview.h"

using namespace std;

Request::Request() {}

// new update
Request::Request(string owner_req, string occupier_req, string house_req, string isRequest) {
    this->owner_req = owner_req;
    this->occupier_req = occupier_req;
    this->house_req = house_req;
    this->isRequest = isRequest;
}

string Request::getOwnerRequest() {
    return owner_req;
}

string Request::getOccupierRequest() {
    return occupier_req;
}

//new update
string Request::getHouseReq() {
    return house_req;
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

// new update
void Request::setHouseReq(string a) {
    house_req = a;
}

void Request::setIsRequest(string a) {
    isRequest = a;
};

// show info of request
void Request::requestInformation() {
    cout << "\nOwner: " << owner_req <<
            "\nOccupier Request: " << occupier_req <<
            "\nHouse Request: " << house_req << // new update
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
        string house_request; // new update
        string isRequest;

        string file_string;
        getline(iFile, file_string);
        stringstream ss(file_string);
        getline(ss, owner, ',');
        getline(ss, occupier, ',');
        getline(ss, house_request, ','); // new update
        getline(ss, isRequest, ',');

        Request request1(owner, occupier, house_request, isRequest); // house update
        requestList.push_back(request1);
    }
    iFile.close();
    return requestList;
}

//Menu for request house
void requestMenu(vector<House> house_list, Member a) {
    int choose;
    vector<houseReview> house_review;
    chooseOption:
    cout << "\nChoose an options: "
            "\n1. View Review"
            "\n2. Request occupy"
            "\n3. Back to menu"
            "\n\nEnter your choice: ";
    cin >> choose;
    switch (choose) {
        case 1:
        {
            house_review = viewHouseReview();
            break;
        }
        case 2:
        {
            if (Occupy_House_Condition(a.getUsername())) {
                requestSearchHouse(house_list, a);
            } else {
                cout << "Cannot request" << endl;
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
    // new update with check condition
    while((!house_request_condition(currentMem.getUsername(), house_name_input)) || (!house_req_input_check(house_name_input)) )
    {
        if(!house_request_condition(currentMem.getUsername(), house_name_input))
        {
            cout << "\nYou already requested this house. Please choose another house" << endl;
            cout << "Please enter house name you want to occupy: ";
            getline(cin, house_name_input);
        }

        if(!house_req_input_check(house_name_input))
        {
            cout << "\nThe name of house you input is not correct. Try again" << endl;
            cout << "Please enter house name you want to occupy: ";
            getline(cin, house_name_input);
        }
    }
    house_choose = housePick(house_name_input);
    
    request_pick.setOwnerRequest(house_choose.getOwner());
    request_pick.setOccupierRequest(currentMem.getUsername());
    
    // new update
    request_pick.setHouseReq(house_choose.getHouseName());

    request_pick.setIsRequest("none"); // fix from "no" to "none"

    requestList.push_back(request_pick);

    ofstream oFile("request.txt", std::ofstream::trunc);
    for (int i = 0; i < requestList.size(); i++) {
        string owner_req = requestList[i].getOwnerRequest();
        string occupier_req = requestList[i].getOccupierRequest();

        // new update
        string houseName_req = requestList[i].getHouseReq();

        string isRequest = requestList[i].getIsRequest();

        if (i != requestList.size() - 1) {
            oFile << owner_req << ","
            << occupier_req << ","
            << houseName_req << "," // new update
            << isRequest << endl;
        } else {
            oFile << owner_req << ","
            << occupier_req << ","
            << houseName_req << "," // new update
            << isRequest;         
        }
    }
    oFile.close();

    cout << "Request house successfully" << endl;
    
}

// NEW: check if signed in member already request the house
bool house_request_condition(string signedInUser, string house_req_option){
    vector<Request> requestList = tempRequestMemory();
    for(int i = 0; i < requestList.size(); i++)
    {
        if(signedInUser == requestList[i].getOccupierRequest() && 
            house_req_option == requestList[i].getHouseReq())
        {
            return false; // cannot use request
        }
    }
    return true; // can request
}


//NEW: current request list for house owner
void currentOwnerRequestList(string owner_house) {
    vector<Request> currentRequest;
    vector<Member> currentRequestMember;
    vector<Member> memberList = tempMemory();
    vector<Request> requestList = tempRequestMemory();

    for (int i = 0; i < requestList.size(); i++) {
        if (owner_house == requestList[i].getOwnerRequest()) {
            currentRequest.push_back(requestList[i]);
        }
    }

    for (int i = 0; i < currentRequest.size(); i++) {
        for (int j = 0; j < memberList.size(); j++) {
            if (memberList[j].getUsername() == currentRequest[i].getOccupierRequest()) {
            currentRequestMember.push_back(memberList[j]);
            }
        }
    }

    for (int i = 0; i < currentRequestMember.size(); i++) {
        currentRequestMember[i].viewInfoOccupier();
    }
}

//New: current occupier request list
void currentOccupierRequestList(string house_request) {
    vector<Request> currentRequest;

    vector<Request> requestList = tempRequestMemory();

    for (int i = 0; i < requestList.size(); i++) {
        if (house_request == requestList[i].getOccupierRequest()) {
            currentRequest.push_back(requestList[i]);
        }
    }

    for (int i = 0; i < currentRequest.size(); i++) {
        currentRequest[i].requestInformation();
    }
}

// New: check if input correct name or not
bool house_req_input_check(string house_req_option)
{
    vector<House> houselist = tempHouseMemory();
    for(int i = 0; i < houselist.size(); i++)
    {
        if(house_req_option == houselist[i].getHouseName())
        {
            return true; // input correct name
        }
    }
    return false; // input incorrect name
}

//NEW: delete current request
void deleteRequest(string occupier_name) {
    string deleteHouseName;
    vector<Request> currentReq = tempRequestMemory();
    int condition_true = 0;
    int count = 0;
    
    do {
        if(count == 0) {
            cout << "Please enter house name you want to cancel request: ";
            cin.ignore();
            getline(cin, deleteHouseName);
        } else {
            cout << "House name is not true, please use other house name" << endl;
            cout << "\nPlease enter house name: ";
            getline(cin, deleteHouseName);
        }

        for (int i = 0; i < currentReq.size(); i++) {
            if (deleteHouseName == currentReq[i].getHouseReq()) {
                condition_true = 1;
                break;
            } else {
                condition_true = 0;
            }
        }
        count++;
    } while (condition_true == 0);

    for (int i = 0; i < currentReq.size(); i++) {
        if (deleteHouseName == currentReq[i].getHouseReq() && occupier_name == currentReq[i].getOccupierRequest()) {
            currentReq.erase(currentReq.begin() + i);
            break;
        }
    }

    ofstream oFile("request.txt", std::ofstream::trunc);
    for (int i = 0; i < currentReq.size(); i++) {
        string owner_req = currentReq[i].getOwnerRequest();
        string occupier_req =currentReq[i].getOccupierRequest();
        string house_req = currentReq[i].getHouseReq();
        string isRequest = currentReq[i].getIsRequest();
    

        if (i != currentReq.size() - 1) {
            oFile << owner_req << ","
            << occupier_req << "," 
            << house_req << ","
            << isRequest << endl;
        } else {
            oFile << owner_req << ","
            << occupier_req << "," 
            << house_req << ","
            << isRequest;
        }
    }    
    oFile.close();
    cout << "Request Deleted" << endl;
}

//New owner accepet request
void acceptRequest(string owner_name) {
    string acceptOccupy;
    vector<Request> currentReq = tempRequestMemory();
    vector<House> houseList = tempHouseMemory();
    int condition_true = 0;
    int count = 0;
    
    do {
        if(count == 0) {
            cout << "(You will reject others request if you accept a request!)" << endl;
            cout << "Please enter user you want to accept request: ";
            cin.ignore();
            getline(cin, acceptOccupy);
        } else {
            cout << "User name is not true, please use other user name" << endl;
            cout << "\nPlease enter user: ";
            getline(cin, acceptOccupy);
        }

        for (int i = 0; i < currentReq.size(); i++) {
            if (acceptOccupy == currentReq[i].getOccupierRequest()) {
                condition_true = 1;
                break;
            } else {
                condition_true = 0;
            }
        }
        count++;
    } while (condition_true == 0);

    vector<Request> updatedRequests;
    for (int i = 0; i < currentReq.size(); i++) {
        if (acceptOccupy != currentReq[i].getOccupierRequest() && owner_name != currentReq[i].getOwnerRequest()) {
            updatedRequests.push_back(currentReq[i]);
        }
    }

    ofstream oFile("request.txt", std::ofstream::trunc);
    for (int i = 0; i < updatedRequests.size(); i++) {
        string owner_req = updatedRequests[i].getOwnerRequest();
        string occupier_req =updatedRequests[i].getOccupierRequest();
        string house_req = updatedRequests[i].getHouseReq();
        string isRequest = updatedRequests[i].getIsRequest();
    

        if (i != updatedRequests.size() - 1) {
            oFile << owner_req << ","
            << occupier_req << "," 
            << house_req << ","
            << isRequest << endl;
        } else {
            oFile << owner_req << ","
            << occupier_req << "," 
            << house_req << ","
            << isRequest;
        }
    }
    oFile.close();

    for (int i = 0; i < houseList.size(); i++) {
        if (owner_name == houseList[i].getOwner()) {
            houseList[i].setOccupier(acceptOccupy);
        }
    }

    ofstream houseFile("houseList.txt", std::ofstream::trunc);
    for (int i = 0; i < houseList.size(); i++) {
        string owner = houseList[i].getOwner();
        string occupier = houseList[i].getOccupier();
        string houseName = houseList[i].getHouseName();
        string location = houseList[i].getLocation();
        int creditPrice = houseList[i].getCreditPrice();
        double houseRating = houseList[i].getHouseRating();
        double requiredRating = houseList[i].getRequiredRating();

        if (i != houseList.size() - 1) {
            houseFile << owner << ","
            << occupier << ","
            << houseName << ","
            << location << ","
            << creditPrice << ","
            << houseRating << ","
            << requiredRating << endl;
        } else {
            houseFile << owner << ","
            << occupier << ","
            << houseName << ","
            << location << ","
            << creditPrice << ","
            << houseRating << ","
            << requiredRating;
        }
    }
    houseFile.close();

    ofstream notiFile("noti.txt", std::ofstream::trunc);
    notiFile << owner_name << "," << acceptOccupy << "," << " "  << "," << " ";
    notiFile.close();

    cout << "\nAccept Occupy Successful" << endl;
}

//New notification when accept function
void acceptNoti(string user) {
    vector<Request> requestList = tempRequestMemory();
    vector<Request> temp;
    bool isNoti = false;

    ifstream iFile("noti.txt");
    if (iFile.fail())
    {
        cout << "Fail to open file" << endl;
    }
    while (!iFile.eof()) {
        string owner;
        string occupier;
        string house;
        string isReq;

        string file_string;
        getline(iFile, file_string);
        stringstream ss(file_string);
        getline(ss, owner, ',');
        getline(ss, occupier, ',');
        getline(ss, house, ',');
        getline(ss, isReq, ',');
    
        Request request1(owner, occupier, house, isReq);
        temp.push_back(request1);
    }
    iFile.close();

    for (int i = 0; i <temp.size(); i++) {
        if (user == temp[i].getOccupierRequest()) {
            cout << "\n\nNew Notification: Your house request has been accepted!\n\n" << endl;
            temp.erase(temp.begin() + i);
            isNoti = true;
            break;      
        }
    }
    if (isNoti == true) {
        ofstream oFile("noti.txt", std::ofstream::trunc);
        for (int i = 0; i < temp.size(); i++) {
            string owner_req = temp[i].getOwnerRequest();
            string occupier_req =temp[i].getOccupierRequest();
            string house_req = temp[i].getHouseReq();
            string isRequest = temp[i].getIsRequest();
        

            if (i != temp.size() - 1) {
                oFile << owner_req << ","
                << occupier_req << "," 
                << house_req << ","
                << isRequest << endl;
            } else {
                oFile << owner_req << ","
                << occupier_req << "," 
                << house_req << ","
                << isRequest;
            }
        }
        oFile.close();
    }    
}    
