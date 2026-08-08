#include<stdio.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<netdb.h>


int main(int argc, char *argv[]){

    struct sockaddr_in serverAddr;
    struct hostent *server;
    char *hostname;
    int socketfd;

    if(argc < 3){
        fprintf(stderr,"use %s <hostname> <port>\n",argv[0]);
        exit(-1);

    }
    hostname =argv[1];
    int portno = atoi(argv[2]);

    socketfd = socket(AF_INET, SOCK_DGRAM,0);
    if(!socketfd){
        perror("error on opening socket ");
        exit(-1);
    }

    server = gethostbyname(hostname);
    if(server ==NULL){
        fprintf(stderr, "Can't resolve hostname\n");
        exit(2);
    }

    bzero((char *) &serverAddr, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    

}