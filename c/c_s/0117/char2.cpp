#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
using std::cout;
using std::endl;
int main()
{
    char list[30]={"\0abc\0sabcsdf\0asdf3123\0\0\0sdf"};
    //memset memcpy dzero
    int list_len;
    list_len=sizeof(list);
    int i;
    int count;
    char *start;
    start=&list[0];
    count=0;
    for(i=0;i<list_len;i++)
    {
        if(list[i]=='\0')
        {
            if(count)
            {
                char re_list[20];
                cout<<"len "<<start<<endl;
                printf("len2 %p\r\n", start);
                count=0;
            }
            start=&list[i+1];
        }
        else
        {
            count++;
        }
    }
}
