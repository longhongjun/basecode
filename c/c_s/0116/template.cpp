#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
using std::cout;
using std::endl;

template <typename A, typename B, typename C>
C min(A x, B y){
    return x+y;
}

int main(){
    int n1=2,n2=10;
    double d1=1.5,d2=5.6;
    int n3;
    n3 = min<int,int,int>(n1,n2);
    //min<int>(n1,n2); 正常的写
    cout<<"混合"<<min<int,double,double>(n1,d1)<<endl;
    cout<<"较小的整数"<<n3<<endl;
    cout<<"较小的实数"<<min<double,double,double>(d1,d2)<<endl;
    //std::cin>>n1;
    //exit(0);
    //return 0;
}

/*
编译器,操作系统是否支持
3种后缀 hpp cc cpp

编译 -x "c++"
window ole com

g++ -E -P aa.cpp 展示所有代码
.a 静态链接库
.so 动态链接库,含有索引
代码块的打包,中间态的文件 源码与二进制文件之间

了解编译的过程
-fpic -c a.cpp 生成.so文件
-shared -o test.so test.o
nm / mm  test.so 查看so文件和o文件



g++ -o test test.so main.o
lib***.so

去哪里找,系统path,/etc/ld.so.conf/
或者使用设置so的查找路径
export LD_LIBRARY_PATH=/data1
set | grep LD_LIBRARY_PATH

ldd 查链接 查so文件,或者可执行文件

0117 字符串的操作
显示调用
隐shi调用

问题:
模板的so使用如何做, 使用dopen(so), dsym() 来做,按照索引做
虚函数 的转化
mpl








*/



















