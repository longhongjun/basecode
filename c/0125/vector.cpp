/*
 * vector.cpp
 *
 *  Created on: 2013-1-29
 *      Author: long
 */

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
//vector 的find必须用 algorithm
using namespace std;
int main(){
	vector <int> v;
	cout<<v.size()<<endl;
	cout<<v.capacity()<<endl;
	int i;
	for(i=0;i<10;i++){
		v.push_back(i);
	}

	for(i=0;i<v.size();i++){
		cout<<v[i]<<endl;
	}
	vector <int>::iterator iter;
	for(iter=v.begin();iter!=v.end();iter++){
		cout<<*iter<<" "<<endl;;
	}
	vector <int>::iterator it;
	it = find(v.begin(), v.end(),5);
	++it;
	cout<<*it<<endl;
	cout<<endl;
	//二维
	vector <vector <int> > Array(10, vector<int>(0));
	int j=0;
	for(j=0;j<10;j++){
		for(i=0;i<10;i++){
			Array[j].push_back(i);
		}
	}

	for(j=0;j<10;j++){
		for(i=0;i<Array[j].size();i++){
			//cout<<Array[j][i]<<" ";
		}
	}
	cout<<endl;


}
