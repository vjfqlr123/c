#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

void error_handling(char *message);

int main()
{
	int clt_sock;
	char message[30];
	struct sockaddr_in clt_addr;
	
	
	close(clt_sock);
	return 0;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
