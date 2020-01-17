#include <iostream>
#include <string>

#include "TcpServer.h"

using namespace std;

void MessageReceived(CTcpListener* listener, int client, string msg);

void main()
{
	CTcpListener server("192.168.2.64", 51515, MessageReceived);

	if (server.init())
	{
		server.run();
	}
}


// callback upon message received
void MessageReceived(CTcpListener* listener, int client, string msg)
{
	listener->sendMsg(client, msg);
}