#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024
#define OPSZ 4

void error_handling(char *message);

int main(int argc, char *argv[])
{
	int clt_sock, num;
	char message[BUF_SIZE];
	char msg[OPSZ];
	int str_len;
	struct sockaddr_in clt_adr;

	if(argc!=3) {
		printf("Usage : %s <IP> <port>\n", argv[0]);
		exit(1);
	}
	
	clt_sock=socket(PF_INET, SOCK_STREAM, 0);   
	if(clt_sock==-1)
		error_handling("socket() error");
	
	memset(&clt_adr, 0, sizeof(clt_adr));
	clt_adr.sin_family=AF_INET;
	clt_adr.sin_addr.s_addr=inet_addr(argv[1]);
	clt_adr.sin_port=htons(atoi(argv[2]));
	
	if(connect(clt_sock, (struct sockaddr*)&clt_adr, sizeof(clt_adr))==-1)
		error_handling("connect() error!");
	else
		puts("Connected...........");
		
	fputs("input : ", stdout);		//printf("Operand count : ");	
	scanf("%d\n", &num);
	
	msg[0] = (char)num;
	write(clt_sock, msg, OPSZ);
	read(clt_sock, message, BUF_SIZE);
	
	printf("server message : %s\n", message);
	
	
		
	return 0;		
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
