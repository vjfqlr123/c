#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

void error_handling(char *message);

int main(int argc, char *argv[])
{
	int serv_sock;
	int clnt_sock;
	
	serv_sock=socket(PF_INET, SOCK_STREAM, 0);				// 50p
	
	if(serv_sock==-1)
		error_handling("socket() error");
	
	struct sockaddr_in serv_addr;							// 68p
	struct sockaddr_in clnt_addr;
	
	if(argc!=2){
		printf("Usage : %s <port>\n", argv[0]);
		exit(1);
	}
	
	memset(&serv_addr, 0, sizeof(serv_addr));				// 81p
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);
	serv_addr.sin_port = htons(atoi(argv[1]));
	
	if(bind(serv_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)		// 83p
		error_handling("bind() error");
	
	if(listen(serv_sock, 5) == -1)
		error_handling("listen() error");								// 100p
	
	socklen_t clnt_addr_size;
	clnt_addr_size = sizeof(clnt_addr);
	
	if(accept(serv_sock, (struct sockaddr *)&clnt_addr, &clnt_addr_size) == -1)		//102p
		error_handling("accept() error");
	
	char message[] = "Hello World";
	
	write(clnt_sock, message, sizeof(message));
	close(serv_sock);
	close(clnt_sock);
	
	return 0;
	
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
