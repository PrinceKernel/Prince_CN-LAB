#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024
 
void find_student(char *reg_no, char *response){
    FILE *fp = fopen("students.txt","r");
    if(fp == NULL){
        strcpy (response,"Error opening file");
        return ;
    }

    char file_reg[50],name[50],branch[50],college[100];
    int  fount =0;
    while (fscanf(fp,",%s, %s , %s , %s",file_reg,name,branch,college)!=EOF)
    {
        if(strcmp(file_reg,reg_no)==0){
            sprintf(response,"Name : %s,Branch : %s,College: %s",name,branch,college);
            fount = 1;
        break;
            
        }
    }
    if(! fount){
        strcpy(response , "Data_not_found ");
    }
    fclose(fp);
    
}

int main(){
    int server_fd , new_socket;
    struct sockaddr_in address;
    int addrlen =sizeof(address);

    char buffer [BUFFER_SIZE];
    char respose(BUFFER_SIZE);
    server_fd = socket (Af_INET ,SOCK_STREM,0);
//  




    while(1){

// 


memset(buffer ,0,BUFFER_SIZE);
memset(response,0,BUFFER_SIZE);

int bytes_read=read(new_socket,buffer,BUFFER_SIZE);
if(bytes_read<=)



        find_student(buffer , response);
        send(new_socket , response , strlen(response),0);

    }
    close(new_socket);
    close(server_fd);
    return 0;
}
