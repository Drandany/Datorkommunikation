#include "tcp_client.h"

int main()
{
    Client client;

    client.sockCreate(AF_INET, SOCK_STREAM, 0);
    client.sockHint("13.53.76.30", 1700);
    client.sockConnect();
    client.communicate();
    client.sockClose();

    return 0;
}