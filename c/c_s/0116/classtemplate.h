#ifndef CLASSTEMPLATE_H
#define CLASSTEMPLATE_H

template <typename T1, typename T2>
class myClass{
private:
    T1 I;
    T2 J;
public:
    myClass(T1 a, T2 b);
    void show();
};
#endif

template <typename T1, typename T2>
myClass<T1,T2>::myClass(T1 a, T2 b):I(a),J(b){}

template <typename T1, typename T2>
void myClass<T1,T2>::show(){
cout<<"I="<<I<<",J"<<J<<endl;
}



