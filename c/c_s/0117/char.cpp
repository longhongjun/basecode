#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char *argv[]){
    //cout<<argv[1]<<endl;
    //cout<<argv[2]<<endl;
    //cout<<"begin "<<endl;
    char e[10];
    //cout<<"strlen "<<strlen(e)<<endl;
    //cout<<"strlen "<<sizeof(e)<<endl;
    memset(e,'\0',10);
    //cout<<&e<<endl;
    //e={'a','b','c','d'};
    char d[20] = {"1\0abcd\0\0efgh\0"};
    //cout<<"str "<<strlen(d)<<endl;
    //cout<<"str "<<strlen(d)<<endl;
    int j;
    char f[3][6];
    int temp=0;
    for(temp=0;temp<3;temp++){
        memset(f[temp],'s',6);
    }
    
    int y=0;
    char *start;
    start=d;
    //cout<<"start "<<&start<< " " <<endl;
    int count=0;
   for(j=0;j<20;j++){
   cout<<"dj "<<j<< " " <<&d[j]<<endl;
        if(d[j]=='\0'){
            if(count){
                cout<<"count "<< count << " " << endl;
                memcpy(f[y],start,count);
                count = 0;
                y++;
            }
            start=&d[j+1];
            
            //cout<<"d "<<j<< " " <<d[j]<<endl;
        }else{
            count++;
        }
        
    }
    
    int g;
    int temp2;
    for(g=0;g<3;g++){
        for(temp2=0;temp2<6;temp2++){
            cout<<"f "<<f[g][temp2]<<endl;
        }
        cout<<"end "<<endl;
    } 
    memcpy(e,argv[1],4);
    memcpy(&e[5],argv[2],3);
    
    int i;
    for(i=0;i<10;i++){
       // cout<<"i "<<e[i]<<endl;
    }
    
    

}


/*
0108
指针的数量


*/
