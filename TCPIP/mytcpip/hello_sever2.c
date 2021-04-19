#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

void error_handling(char *message);

int main(int argc, char *argv[])
{
	int sev_sock;
	int clt_sock;
	
	sev_sock = socket(PF_INET, SOCK_STREAM, 0);
	
	if(sev_sock==-1)
		error_handling("socket() error");
	
	struct sockaddr_in sev_addr;
	struct sockaddr_in clt_addr;
	
	memset(&sev_addr, 0, sizeof(sev_addr));
	sev_addr.sin_family = AF_INET;
	sev_addr.sin_addr.s_addr =htonl(INADDR_ANY);
	sev_addr.sin_port = htons(atoi(argv[1]));
	
	if(bind(sev_sock, (struct sockaddr*)&sev_addr, sizeof(sev_addr))==-1)
		error_handling("bind() error");
	
	if(listen(sev_sock, 5)==-1)
		error_handling("listen() error");
	
	socklen_t clt_addr_size = sizeof(clt_addr);
	
	if(accept(sev_sock, (struct sockaddr*)&clt_addr, &clt_addr_size)==-1)
		error_handling("accept() error");
	
	char message[]="Hello, World2\n";
	
	if(argc!=2){
		printf("Usage : %s <port>\n", argv[0]);
		exit(1);
	}
	
	write(clt_sock, message, sizeof(message));
	close(sev_sock);
	close(clt_sock);
	return 0;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
