/*
 * two.cpp
 *
 *  Created on: 2013-1-25
 *      Author: long
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
struct test{
	int a;
	int b;
};
void print_s1(test point){
	cout<<point.a<<"|"<<point.b<<endl;
}
test get_s1(){
	test point;
	cin>>point.a>>point.b;
	return point;
}
void print_s2(test *point){
	cout<<point->a<<"|"<<point->b<<endl;
}
void get_s2(test *point){
	cin>>point->a>>point->b;

}

struct person{
	char name[20];
	int count;

};

int main(){
	person list[3] = {{"a",0},{"b",0},{"c",0}};
	char b[20];
	string s1,s2;
	//cin>>s1;
	getline(cin,s2,'?');




	cout<<s1<<endl<<s2<<endl;
	/*
	person s={"a",2};
	person *point = &s;
	cout<<(*point).name<<" "<<(*point).count<<endl;


	int i,j;
	char lead_name[20];
	for(i=0;i<3;i++){
		cin>>lead_name;
		j=0;
		for(j=0;j<3;j++){
			cout<<lead_name<<" "<<list[j].name<<endl;
			if(strcmp(lead_name, list[j].name) == 0){
				list[j].count++;
			}
		}
	}

	for(j=0;j<3;j++){
		cout<<list[j].name<<list[j].count<<endl;
	}



	test s1;
	test s2;
	test *s3=&s2;
	test s4[]={{1,2},{3,5}};

	//s1 = get_s1();
	//print_s1(s1);


	get_s2(s3);
	print_s2(s3);
	*/
}
