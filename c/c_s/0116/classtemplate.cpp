#ifndef CLASSTEMPLATE_H
#define CLASSTEMPLATE_H
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

template <typename T1, typename T2>
class myClass{
public:
    T1 a;
    T2 b;
    //myClass(T1 a, T2 b);
    T1 show(T1 a, T2 b);
};
#endif
//template <typename T1, typename T2>
//myClass<T1,T2>::myClass(T1 a, T2 b):I(a),J(b){}
template <typename T1, typename T2>
T1 myClass<T1,T2>::show(T1 I,T2 J){
    return I;
//cout<<"I="<<I<<",J"<<J<<endl;
}


