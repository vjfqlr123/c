#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>

void error_handling(char *message);

int main(int argc, char *argv[])
{
	if(argc!=2){
		printf("Usage : %s <port>\n", argv[0]);
		exit(1);
	}
	
	int ser_sock;
	ser_sock = socket(PF_INET, SOCK_STREAM, 0);
	
	if(ser_sock==-1)
		error_handling("socket() error");
	
	struct sockaddr_in ser_addr;
	
	memset(&ser_addr, 0, sizeof(ser_addr));
	ser_addr.sin_family = AF_INET;
	ser_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	ser_addr.sin_port = htons(atoi(argv[1]));
	
	if(bind(ser_sock, (struct sockaddr*)&ser_addr, sizeof(ser_addr))==-1)
		error_handling("bind() error");
	
	if(listen(ser_sock, 5)==-1)
		error_handling("bind() error");
		
	int clt_sock;
	struct sockaddr clt_addr;	
	socklen_t clt_addr_size = sizeof(clt_addr);
	
	if(accept(ser_sock, (struct sockaddr*)&clt_addr, &clt_addr_size)==-1)
		error_handling("accept() error");
	
	char message[] = "Hello World3\n";
	
	write(clt_sock, message, sizeof(message));
	
	close(ser_sock);
	close(clt_sock);
	return 0;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
