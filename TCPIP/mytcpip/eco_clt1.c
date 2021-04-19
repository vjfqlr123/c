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
	int sk;
	struct sockaddr_in ser;
	int i, str_len, rev_len, cnt;
	char message[BUF];
	
	sk = socket(PF_INET, SOCK_STREAM, 0);
	if(sk==-1)
		error("socket error");
		
	memset(&ser, 0, sizeof(ser));
	ser.sin_family = AF_INET;
	ser.sin_addr.s_addr = inet_addr(argv[1]);
	ser.sin_port = htonl(atoi(argv[2]));	
	
	if(connect(sk, (struct sockaddr*)&ser, sizeof(ser))==-1)
		error("con error");
	else
		printf("connected....");
	
	
	while(1){
			
		fputs("input message(Q to q) : ", stdout);
		fgets(message, BUF, stdin);
		
		if(!strcmp(message, "Q\n") || !strcmp(message, "q\n"))
			break;	
		
		str_len = write(sk, message, strlen(message));
		
		rev_len = 0;
			while(str_len > rev_len){
				cnt = read(sk, message, BUF-1);
				if(cnt==-1)
					error("read error");
				rev_len += cnt;
			}
		message[rev_len] = 0;
		printf("message from server : %s", message);	
		
		
	}
	
	close(sk);
	return 0;
}

void error(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
