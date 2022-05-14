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
    string isRequest;

public:
    //Constructor
    Request();
    Request(string owner_req, string occupier_req, string isRequest);
    
    string getOwnerRequest();

    string getOccupierRequest();

    string getIsRequest();

    void setOwnerRequest(string a);

    void setOccupierRequest(string a);

    void setIsRequest(string a);

    void requestInformation();
};

void requestMenu(vector<House> house_list, Member a);

void requestSearchHouse(vector<House> houseList, Member currentMem);

vector<Request>tempRequestMemory();

#endif