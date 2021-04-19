#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

void error_handling(char *message);

int main(int argc, char *argv[])
{
	int clt_sock;
	
	clt_sock = socket(PF_INET, SOCK_STREAM, 0);
	
	if(clt_sock==-1)
		error_handling("socket() error");
	
	if(argc!=3){
		printf("Usage : %s <IP> <port\n>", argv[0]);
		exit(1);
	}
	
	struct sockaddr_in clt_addr;
	
	memset(&clt_addr, 0, sizeof(clt_addr));
	clt_addr.sin_family = AF_INET;
	clt_addr.sin_addr.s_addr = inet_addr(argv[1]);
	clt_addr.sin_port = htons(atoi(argv[2]));
	
	if(connect(clt_sock, (struct sockaddr*)&clt_addr, sizeof(clt_addr))==-1)
		error_handling("connet() error");
	
	char message[30];
	
	if(read(clt_sock, message, sizeof(message)-1)==-1)
		error_handling("read() error");
	
	printf("message form server : %s\n", message);
	close(clt_sock);
	return 0;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
