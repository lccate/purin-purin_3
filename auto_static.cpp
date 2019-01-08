//文件名：auto_static
//作  者：ccate
//时  间：2019.1
//描  述：自动变量

#include<stdio.h>

void test()
{
	int a = 0;
	a++;
	printf("a=%d\n",a);
}

int main001()
{
	int i;
	for (i = 0;i<10;i++)
	{
		test();
	}
	return 0;
}

/*结果
a=1
a=1
a=1
a=1
a=1
a=1
a=1
a=1
a=1
a=1
*/