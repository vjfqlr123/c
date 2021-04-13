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
	int ser_sock;
	int clt_sock;
	
	struct sockaddr_in ser_addr;
	struct sockaddr_in clt_addr;
	
	if(argc != 2){
		printf("Usage : %s <port>\n", argv[0]);
		exit(1);
	}
		
	//socket
	ser_sock = socket(PF_INET, SOCK_STREAM, 0);
	if(ser_sock == -1)
		error_handling(socket() error);
	
	memset(&ser_addr, 0, sizeof(ser_addr));
	ser_addr.sin_famliy = AF_INET;
	ser_addr.sin_port = htonl(INADDR_ANY);
	ser_addr.sin_addr.s_addr = htons(atoi(argv[1]));		
	
	//bind
	if(bind(ser_sock, (struct sockaddr*)&ser_addr, sizeof(ser_addr)) == -1)
		error_handling(bind() error);
	
	//listen
	if(listen(ser_sock, 10) == -1)
		error_handling(listen() error);
	
	//accept
	int clt_addr_size = sizeof(clt_addr);
	
	clt_sock = accept(ser_sock, (struct sockaddr*)&clt_addr, &clt_addr_size);
	if(clt_sock == -1)
		error_handling(accept() error);
	
	
	close(clt_sock);
	close(ser_sock);
	return 0;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
