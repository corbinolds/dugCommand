#include "includes.h"


void connectToServer(string address, string nameServerIP) {	
	//handles opening the socket
	int sockfd, portno, n;
	struct sockaddr_in serv_addr;
	struct hostent *server;

	char buffer[256];

	portno = 53;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) {
    	cout << "ERROR opening socket" << endl;
    }
    //string hostname = getTheHost(nameServerIP);
    
    //if(hostname.c_str() == "ERROR"){
    //	return "Error with recipient's host name";
    //}
    //else{
    //	server = gethostbyname(hostname.c_str());
    //}
    server = gethostbyname(nameServerIP.c_str());
	if (server == NULL) {
	    fprintf(stderr,"ERROR, no such host\n");
	    exit(0);
	}
	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	bcopy((char *)server->h_addr, 
	     (char *)&serv_addr.sin_addr.s_addr,
	     server->h_length);
	serv_addr.sin_port = htons(portno);
	if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
	    cout << "ERROR connecting" << endl;
	bzero(buffer,256);

    //return sendMail(sockfd,recipient, sender, message, domain);
}

// ***************************************************************************
// * Main
// ***************************************************************************
int main(int argc, char **argv) {

	connectToServer("imagine.mines.edu", "138.67.1.2");

}
