#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>

void error(char* message);

int main(int argc, char* argv[])
{
	int ser_sk, clt_sk;
	struct sockaddr_in ser_adr, clt_adr;
	socklen_t clt_adr_sz;
	
	char message[] = "hello world";
	
	ser_sk=socket(PF_INET, SOCK_STREAM, 0);
	if(ser_sk==-1)
		error("socket error");
		
	memset(&ser_adr, 0, sizeof(ser_adr));
	ser_adr.sin_family = AF_INET;
	ser_adr.sin_addr.s_addr = htonl(INADDR_ANY);
	ser_adr.sin_port = htons(atoi(argv[1]));
		
	if(bind(ser_sk, (struct sockaddr*)&ser_adr, sizeof(ser_adr))==-1)
		error("bind error");
	
	if(listen(ser_sk, 5)==-1)
		error("listen error");
	
	clt_adr_sz = sizeof(clt_adr);
	clt_sk=accept(ser_sk, (struct sockaddr*)&clt_adr, &clt_adr_sz);
	if(clt_sk==-1)
		error("accept error");
	
	
	write(clt_sk, message, sizeof(message));
	
	
	close(clt_sk);
	close(ser_sk);
	return 0;
}

void error(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
