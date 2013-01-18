#include "test.h"
int main(){
    int a,b;
    a=1;
    b=2;
    int (test::*p)(int,int);
    p = &test::add;
    
    
    test *c = new test();
    int re;
    re = (c->*p)(a,b);
    cout<<re<<endl;
}

/*



*/


