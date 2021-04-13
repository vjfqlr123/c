#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

void error_handling(char *message);

int main(int argc, char *argv[])
{
	
	int sscok;
	struct sockaddr_in saddr;
	
	if(argc != 3){
		printf("Usage : %s <IP> <port> \n", argv[0]);
		exit(1);
	}
	
	//socket
	ssock = socket(PF_INET, SOCK_STREAM, 0);
	if(ssock == -1)
		error_handling(socket() error);
	
	memset(&saddr, 0, sizeof(saddr));
	saddr.sin_famliy = AF_INET;
	saddr.sin_port = htonl(atoi(argv[2]));	
	saddr.sin_addr.s_addr = inet_addr(argv[1]);
	
	
	if(connect(sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr))==-1)
		error_handling("connect() error!");
	else
		puts("Connected...........");
		puts("start game");
	
	
	
	close(sscok);
	return 0;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
