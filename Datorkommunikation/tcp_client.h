#pragma once

#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include "sys/types.h"
#include "sys/socket.h"

using namespace std;

class Client
{
private:
    int16_t sockFileDesc;
    sockaddr_in hint;
    char buf[4096];
    string userInput;

public:
    Client();
    bool sockCreate(int32_t domain, int32_t type, int32_t protocol = 0);
    bool sockHint(string ip, uint32_t port);
    bool sockConnect();
    void communicate();
    void sockClose();
};