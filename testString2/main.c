#include <stdio.h>
#include "mystring.h"

int main(void)
{
	char *str = "hello, world";
	
	int len = my_strlen(str);
	printf("len: %d\n", len);
	
	char str2[20];
	my_strcpy(str2, str);
	printf("str2: %s\n", str2);
	
	if(my_strcmp(str, str2)==0)
		printf("str str2 is equal\n");
	else
		printf("str str2 is not equal\n");
	
	my_strcat(str2, " ");
	my_strcat(str2, "Park");
	printf("str2 : %s\n", str2);
	
	return 0;
}
