#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF 1024

void error(char *message);

int main(int argc, char *argv[])
{
	int sk1, sk2;
	struct sockaddr_in ser, clt;
	socklen_t clt_sz;
	char message[BUF];
	int len;
	
	if(argc!=2){
		printf("Usage : %s <port>", argv[0]);
		exit(1);
	}
	
	sk1 = socket(PF_INET, SOCK_STREAM, 0);
	if(sk1==-1)
		error("socket error");
		
	memset(&ser, 0, sizeof(ser));
	ser.sin_family = AF_INET;
	ser.sin_addr.s_addr = htonl(INADDR_ANY);
	ser.sin_port = htons(atoi(argv[1]));
	
	if(bind(sk1, (struct sockaddr*)&ser, sizeof(ser))==-1)
		error("bind error");
		
	if(listen(sk1, 5)==-1)
		error("lit error");
	
	clt_sz = sizeof(clt);
	
	for(int i=0; i<5 ++i){
		sk2 = accept(sk1, (struct sockaddr*)&clt, &clt_sz);
		if(sk2==-1)
			error("accept error");
		else
			printf("conneted %d", i+1);
		
		while((len=read(sk2, message, BUF))!=0)
			write(sk2, message, len);
		
		close(sk2);
	}
	
	close(sk1);
	return 0;
}

void error(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
