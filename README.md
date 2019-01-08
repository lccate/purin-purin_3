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
存储所有静态变量，全局变量  

