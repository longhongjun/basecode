//int &class::add(int,int);
/*
int (*p) add(int, int)
int (test::*p)(int,int)
p=&class::add

test b
b.add()

(b.*p)(1,2)

b=new test
b->add()

(b->*p)(1,2)


new class a
a.add()

__stdcall 普通方法执行
__thiscall 类执行

*/

#include "test.h"

int test::add(int a, int b){
    return a+b;
}

// new  +=*/  操作符重载
