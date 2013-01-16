#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include "classtemplate.cpp"
using std::cout;
using std::endl;

int main(){
    myClass<int,int> class1;
    int i;
    i = class1.show(1, 2);
    cout<<"test"<<i<<endl;
    myClass<float,float> class2;
    float j;
    j = class2.show(1.2, 2.2);
    cout<<"test"<<j<<endl;
}
/*








*/

