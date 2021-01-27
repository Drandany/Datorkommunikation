#include "tcp_client.h"

Client::Client()
    :sockFileDesc(0)
{
}

bool Client::sockCreate(int32_t domain, int32_t type, int32_t protocol)
{
    bool sockCreated = true;

    this->sockFileDesc = socket(domain, type, protocol);
    if (this->sockFileDesc == -1)
    {
        sockCreated = false;
    }

    return sockCreated;
}

bool Client::sockHint(string ip, uint32_t port)
{
    bool sockPacked = true;

    this->hint.sin_family = AF_INET;
    this->hint.sin_port = htons(port);
    if (inet_pton(AF_INET, ip.c_str(), &hint.sin_addr) == -1)
    {
        sockPacked = false;
    }

    return sockPacked;
}

bool Client::sockConnect()
{
    bool sockConnected = true;

    this->sockFileDesc = connect(this->sockFileDesc, (sockaddr*)&this->hint, sizeof(hint));
    if (this->sockFileDesc == -1)
    {
        sockConnected = false;
    }

    return sockConnected;
}

void Client::communicate()
{
do {
    cout << "> ";
    getline(cin, userInput);
    
    int sendRes = send(this->sockFileDesc, userInput.c_str(), userInput.size() + 1, 0);
    if (sendRes == -1)
    {
    	cout << "Could not send to server \r\n";
    	continue;
    }
    
    memset(this->buf, 0, 4096);
    int bytesReceived = recv(this->sockFileDesc, buf, 4096, 0);
    
    cout << "SERVER> " << string(buf, bytesReceived) << "\r\n";
    
    } while(true);
}

void Client::sockClose()
{
    close(this->sockFileDesc);
}