//文件名：dui
//作  者：ccate
//时  间：2019.1
//描  述：通过堆空间实现动态大小变化的字符数组

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	char a[] = "21874628764284781358341";
	char b[] = "1dhiufhilaesbcaierhnoidbv";
	char *s = malloc(strlen(a)+strlen(b)+1);
	strcpy(s,a);
	strcpy(s,b);
	printf("%s\n",s);
	free(s);
	return 0;
}