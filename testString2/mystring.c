#include "mystring.h"

int my_strlen(const char *str)
{
	int count = 0;
	
	while(*str++)
		++count;
		
	return count;	
}

void my_strcpy(char *des, const char *src)
{
	while(*src)
		*des++ = *src++;
		
	//while(*des++ = *src++)
		//;
		
	*des = '\0';
}

int my_strcmp(const char *s1, const char *s2)
{
	while(*s1 || *s2 || *s1 != *s2)
		++s1, ++s2;
		
	return *s1 - *s2;
}

/*void my_strcat(char *des, const char *src)
{
	int i;
	for(i=0; des[i]; ++i)
		;
	
	int j;
	for(j=0; src[j]; ++j)
		des[i+j] = src[j];
		
	des[i+j] = '\0';
		
}
*/
void my_strcat(char *des, const char *src)
{
	my_strcpy(des + my_strlen(des), src);
}
