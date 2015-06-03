#include "Connexion.h"
using namespace std;

Connexion::Connexion(){
    //create a socket
    //socket(int domain, int type, int protocol)
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    int optval = 1;
    if (sockfd < 0){
        cout << "ERROR opening socket" << endl;
        exit(0);
    }

    //clear adresse structure
    bzero((char *)&serv_addr, sizeof(serv_addr));

    //num of port
    portno = 8080;

    //sertup the host_addr structure for use in bind call
    //server byte order
    serv_addr.sin_family = AF_INET;

    //automatically be filled with current host's IP adresse
    serv_addr.sin_port = htons(portno);
    
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (const void *)&optval , sizeof(int)) < 0){
	cout << "ERROR in setsockopt" << endl;
	exit(0);
    }
    /* bind(int fd, struct sockaddr *local_addr, socklen_t addr_length)
       bind() passes file descriptor, the address structure,
       and the length of the address structure
       This bind() call will bind  the socket to the current IP address on port, portno*/
    int e = bind(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));
    if (e<0){
        cout << "ERROR on binding" << endl;
        exit(0);
    }
    // This listen() call tells the socket to listen to the incoming connections.
    // The listen() function places all incoming connection into a backlog queue
    // until accept() call accepts the connection.
    // Here, we set the maximum size for the backlog queue to 5.
    listen(sockfd,5);

}
