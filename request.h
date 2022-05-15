#ifndef _REQUEST_H_
#define _REQUEST_H_
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>
#include "house.h"
#include "member.h"

using namespace std;

class Request {
private:
    string owner_req;
    string occupier_req;
    string house_req; // add house info in request
    string isRequest;

public:
    //Constructor
    Request();
    Request(string owner_req, string occupier_req, string house_req, string isRequest); // new update
    
    string getOwnerRequest();

    string getOccupierRequest();

    string getHouseReq(); // new update

    string getIsRequest();

    void setOwnerRequest(string a);

    void setOccupierRequest(string a);

    void setHouseReq(string a); // new update

    void setIsRequest(string a);

    void requestInformation();
};

void requestMenu(vector<House> house_list, Member a);

void requestSearchHouse(vector<House> houseList, Member currentMem);

vector<Request>tempRequestMemory();

bool house_request_condition(string signedInUser, string house_req_option); // new update

void currentOwnerRequestList(string owner_house); //New function for house owner

void currentOccupierRequestList(string house_request); //New function for occupier

bool house_req_input_check(string house_req_option); //New check if input correct name or not

void deleteRequest(string occupier_name); //New delete request function

void acceptRequest(string owner_name); //New accept request function

void acceptNoti(string user); //New notification function
#endif