#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
//string
//using namesapce std
// string
// 16日 模板,编译的尝试(静态库和动态库dll so)
#include "long_add.h"

int add(int,int);
int main(int argc, char *argv[]){
    int x,y,a,b,re;
    a=argv[1][0];
    b=argv[2][0];
    x=1;
    y=2;
    /*
    char s;
    char ss[5];
    bzero(&s,1);
    memset(s);
    bzero(ss,5);
    memcopy(ss, "sdfsd");
    */
    //strlen
    //sizeof
    
    
    
    
    //char ss[5]="12345";
    //re = add(1,2);
    long_add newb;
    
    printf("123\r\nmyadd\r\n%d", newb.myadd(x,y));
    
    long_add * new2 = new long_add;
    
    printf("123\r\nmyadd\r\n%d", new2->myadd(x,y));
    //printf("123\r\n%d", add(x,y));
}

int add(int x, int y){
  return x+y;
}


