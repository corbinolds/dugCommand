/* #include "includes.h"


#define MAXBUF 1024*1024

void echo( int sd ) {
    int len,n;
    char bufin[MAXBUF];
    struct sockaddr_in remote;

    /* need to know how big address struct is, len must be set before the
       call to recvfrom!!! */

   /* len = sizeof(remote);

    while (1) {
      /* read a datagram from the socket (put result in bufin) */
      //n=recvfrom(sd,bufin,MAXBUF,0,(struct sockaddr *)&remote,&len);

      /* print out the address of the sender */
//      printf("Got a datagram from %s port %d\n",
  //           inet_ntoa(remote.sin_addr), ntohs(remote.sin_port));

//      if (n<0) {
//        perror("Error receiving data");
 //     } else {
//        printf("GOT %d BYTES\n",n);
        /* Got something, just send it back */
//        sendto(sd,bufin,n,0,(struct sockaddr *)&remote,len);
//      }
//    }
//}


//command to write to a socket
/*void writeCommand(int sockfd, string message) {
	int size = message.length();
	write(sockfd, message.c_str(), size);
	
	return;*/
//}


/*void connectToServer(string address, string nameServerIP) {	
	//handles opening the socket
	int sockfd, portno, n;
	struct sockaddr_in serv_addr;
	struct hostent *server;

	char buffer[256];

	portno = 53;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) {
    	cout << "ERROR opening socket" << endl;
    } */
    //string hostname = getTheHost(nameServerIP);
    
    //if(hostname.c_str() == "ERROR"){
    //	return "Error with recipient's host name";
    //}
    //else{
    //	server = gethostbyname(hostname.c_str());
    //}
   /* server = gethostbyname(nameServerIP.c_str());
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

    return sendMail(sockfd,recipient, sender, message, domain);
} */

// ***************************************************************************
// * Main
// ***************************************************************************
/*int main(int argc, char **argv) {

	connectToServer("imagine.mines.edu", "138.67.1.2");

}
*/

#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<arpa/inet.h>
#include<string.h>
#include<arpa/inet.h>
#include<stdio.h>
#define MAXLINE 1024
int main(int argc,char* argv[]) {
	int sockfd;
	int n;
	socklen_t len;
	char sendline[1024],recvline[1024];
	struct sockaddr_in servaddr;
	
	strcpy(sendline,"");
	printf("\n Enter the message : ");
	scanf("%s",sendline);
	sockfd=socket(AF_INET,SOCK_DGRAM,0);
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	servaddr.sin_port=htons(53);
	connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
	len=sizeof(servaddr);
	sendto(sockfd,sendline,MAXLINE,0,(struct sockaddr*)&servaddr,len);
	n=recvfrom(sockfd,recvline,MAXLINE,0,NULL,NULL);
	recvline[n]=0;
	printf("\n Server's Echo : %s\n\n",recvline);
	return 0;
}
