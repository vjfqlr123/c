#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 30

void error_handling(char *message);

int main(int argc, char *argv[])
{
	int ser_sock, clt_sock;
	int read_cnt;
	char buf[BUF_SIZE];
	FILE *fp;
	
	struct sockaddr_in ser_adr, clt_adr;
	socklen_t clt_adr_size;
	
	if(argc!=2) {
		printf("Usage: %s <port>\n", argv[0]);
		exit(1);
	}
	
	fp=fopen("mavic.jpeg", "rb");
	
	ser_sock = socket(PF_INET, SOCK_STREAM, 0);   
	
	memset(&ser_adr, 0, sizeof(ser_adr));
	ser_adr.sin_family=AF_INET;
	ser_adr.sin_addr.s_addr=htonl(INADDR_ANY);
	ser_adr.sin_port=htons(atoi(argv[1]));
	
	bind(ser_sock, (struct sockaddr*)&ser_adr, sizeof(ser_adr));
	listen(ser_sock, 5);
	
	clt_adr_size = sizeof(clt_adr);    
	clt_sock = accept(ser_sock, (struct sockaddr*)&clt_adr, &clt_adr_size);
	
	while(1){
		read_cnt = fread((void*)buf, 1, BUF_SIZE, fp);
		if(read_cnt<BUF_SIZE){
			write(clt_sock, buf, read_cnt);
			break;
		}
		write(clt_sock, buf, BUF_SIZE);
	}
	
	shutdown(clt_sock, SHUT_WR);
	read(clt_sock, buf, BUF_SIZE);
	printf("Message from client : %s\n", buf);
	
	fclose(fp);
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
