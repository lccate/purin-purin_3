//文件名：jingtaiqu
//作  者：ccate
//时  间：2019.1
//描  述：静态变量和全局变量都存放在静态区

#include<stdio.h>

int a = 10;//全局
static int b =2;//全局静态
int main()
{
	static int c = 0;//静态
	int d = 100;//局部
	printf("%p,%p,%p,%p\n",&a,&b,&c,&d);//结果：00888000,00888004,00888144,010FFB0C
	return 0;
}
