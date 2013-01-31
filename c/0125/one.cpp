/*
 * one.cpp
 *
 *  Created on: 2013-1-25
 *      Author: long
 */
#include "one.h"

int print_test(test *point){
	cout<<point->a<<" "<<point->b<<endl;
}
int print_test2(test point){
	cout<<point.a<<" "<<point.b<<endl;
}
int main(){
	test test1;
	test test2;
	test1.a = 1;
	test1.b = 2;
	cout<<test1.a<<" "<<test1.b<<endl;

	test *point;
	point = &test1;

	cout<<point->a<<" "<<point->b<<endl;
	test a[2]={{1,2},{3,4}};
	int i;
	for(i=0;i<2;i++){
		print_test(&a[i]);
		print_test2(a[i]);
	}



}

