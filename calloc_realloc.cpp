//文件名：calloc_realloc
//作  者：ccate
//时  间：2019.1
//描  述：calloc与realloc

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char *s1 = calloc(10,sizeof(char));//在堆中分配10个char
	char *s2 = calloc(10,sizeof(char));
	strcpy(s1,"123456789");
	strcpy(s2,"abcdefg");
	s1 = realloc(s1,strlen(s1)+strlen(s2)+1);//先根据s1和s2的长度对s1进行扩充
	strcat(s1,s2);
	printf("%s\n",s1);
	free(s1);
	free(s2);
	return 0;
}