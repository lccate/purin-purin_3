# c语言：内存管理

## 作用域
一个c语言变量的作用域可以是代码块，函数，文件  
代码块是{}之间的一段代码  
```
#include <stdio.h>

int a=2;//文件作用域
int main()
{
  int a = 0;//函数作用域
    {
      int a = 1;//代码块作用域
    }
    return 0;
}
```
注意：同一个作用域不能有同名变量，但不同作用域变量名称可以相同  

### auto自动变量
一般情况下{}代码块内部定义的都是auto变量，自动出现在内存中  
int a=1;默认为auto int a=1  
```
#include <stdio.h>

int a=2;//非auto
int main()
{
  int a = 0;//auto
    {
      int a = 1;//auto
    }
    return 0;
}
```  

### register变量
通常变量都是放在内存中的，如果把变量放到cpu的寄存器里面，代码执行效率会更高  
register int a=1;  

### 代码块作用域的静态变量
静态变量是指内存位置在程序执行期间一直不变的量，一个代码块内部的静态变量只能被这个代码块内部访问  
注意：静态变量只初始化一次，与大括号无关，程序结束后才消失   
[自动变量](auto_static.cpp)与[静态变量](auto_static2.cpp)  

### 代码块作用域外的静态变量
在代码块外的变量是文件变量，也是全局变量，如果变量或函数在其他文件中定义了，需要声明  
```
extren int a;//声明一个变量a
external void test();//声明函数test（），这个函数在其他地方定义了，这里只是声明
```
静态全局变量/函数：只能在定义它的文件内部访问，对于文件外部是不能使用的  
因此上述程序如果在其他文件中定义成静态变量，声明会出错    
如果一个代码块之外的变量或函数，c语言默认是全局的，除非写了一个static就改变了他的类型了  

## 内存布局

### 代码区
程序被操作系统加载到内存的时候，所有可执行代码都被加载到代码区，这块内存在程序运行期间不可修改  

### 静态区
[静态变量和全局变量都存放在静态区](jingtaiqu.cpp)  

### 栈区  
栈：先进后出，所有的自动变量，函数的形参，函数的返回值都是由编译器自动放入栈中，当超出其作用域时，自动从栈中弹出   
不同系统栈大小不一样，windows程序在编译的时候就可以指定栈的大小，linux可以通过设置环境变量指定栈的大小  

### 堆区  
大容器，容量远大于栈，申请和释放需要通过手动书写代码来完成  

#### 堆的分配和释放  
##### malloc在堆中分配空间
用malloc在堆中分配的空间不会自动释放，需要用free来手动释放，配对使用
如果malloc分配的内存忘记free，那么叫内存泄漏，初学者容易犯（结果就是内存都被吃掉了）  
注意：malloc分配的空间的值是随机的，不会自动清0    
```
char *s = malloc(10);//在堆中分配了10个字节的空间
strcpy(s,"abcd");
printf("%s\n",s);
free(s);//释放堆中的内存

s = malloc(100);//s是自动变量，可以重新使用，这个时候又重新指向了一个新的堆空间
free(s);//free s不是把s释放掉了，而是释放了s指向的那块内存空间

return 0;
```
什么时候在栈stack/堆heap中使用一个数组？  
一个程序栈大小有限，如果一个数组特别大，会导致栈溢出，不要在栈里面定义太大的数组，此时需要放入堆  
如果一个数组定义的时候，大小不能确定，那么就适合用堆  
```
scanf("%d",&i);
int *p = malloc(i * sizeof(int));//可以根据用户的输入在堆中分配大小不同的数组

free(p);
```

[通过堆空间实现动态大小变化的字符数组](dui.cpp)   

代码区静态区堆栈  
![代码区静态区堆栈](https://github.com/cccccate/purin-purin_3/blob/master/1.png)  
堆和栈的大小是动态变化的，静态区大小是固定不变的   
![例子一](https://github.com/cccccate/purin-purin_3/blob/master/2.png)  
![例子二](https://github.com/cccccate/purin-purin_3/blob/master/3.png)  
```
int abc(int a,int b)//c语言的形参是从右到左入栈的，b先入栈，a后入栈
```
![入栈](https://github.com/cccccate/purin-purin_3/blob/master/4.png)

##### calloc与realloc的使用
malloc的参数是指定分配的大小，单位，字节  
calloc的第一个参数是指定单位的数量，第二个参数是指定一个单位的大小  
用malloc分配10个int  
```
int *p = malloc(10*sizeof(int));
```
用calloc分配10个int
```
int *p = calloc(10*sizeof(int));
```
以上两种写法分配堆内存一样，区别：malloc只负责分配，不负责清空，需要用memset清空；calloc内存自动初始化为0，不需要额外清空  
用malloc分配了内存，想扩大用realloc  
[calloc_realloc](calloc_realoc.cpp)   

## 操作系统分配内存的最小单位说明
windows下每次堆的变化是4k  
如果需要1k的空间，操作系统给4k  
如果需要5k，给8k  
4k是内存最小单位，优点是效率提升，缺点是浪费了一些内存  
太小内存节省了但是浪费了效率，太大了效率提高了但是浪费了内存（抽烟的长度为例举例）  
因此用malloc分配内存的时候不必在大小上过于纠结，除非处于4k的临界值  

