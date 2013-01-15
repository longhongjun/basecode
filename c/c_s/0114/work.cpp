#include <stdio.h>
#include <stdarg.h>


#define FSIZE 4
#define SIZE 2
int main(void){
    int SIZES=7;
    int i,j;
    int mylist[FSIZE][SIZE] = {{1,2},{3,4},{5,6},{7,8}};
    for(i=0;i<FSIZE;i++){
        printf("list i %d  %p\r\n", mylist[i], &mylist[i]);
        
        for(j=0;j<SIZE;j++){
            printf("list %d  %p\r\n", mylist[i][j], &mylist[i][j]);
        }
    }
}







/*

void interchange(int *u, int *v);
int main(void){
    int x=5,y=10;
    interchange(&x, &y);
    printf("x %d y %d \r\n", x, y);
    return 0;
}
    
void interchange(int *u, int *v){
    int temp;
    temp = *u;
    *u = *v;
    *v = temp;
}

//


int up_down(int);
//long rfact(int);
void to_binary( long n);

int main(void){
    long number;
    number = 22;
    printf("%p", &number);
    

    while (scanf("%d", &number) == 1){
        to_binary(number);
    }
    printf("end\r\n");
    return 0;

    //up_down(1); 
    //rfact(12);
    //to_binary(9);
}

void to_binary( long n){
    int r;
    r=n%2;
    if(n>=2){
        to_binary(n/2);
    }
    putchar('0'+r);
    return;
}

int up_down(int num){
    int re;
    printf("num %d location %p \r\n", num, &num);
    if(num < 4){
        re = up_down(num+1);
    }
    printf("re %1d \r\n", re);
    return num;
}
/*
long rfact(int n){
    long re;
    if(n>0){
        re = rfact(n-1)*n;
    }else{
        re = 1;
    }
    printf("re -- %1d\r\n", re);
    return re;
}



/*
#define SIZE 50
#define WIDTH 40
void starbar(char ch,int num);

int main(void){
    float list[SIZE];
    starbar('c', 30);
    printf("123 %d\r\n", SIZE);
    starbar('d', 40);
    return 0;
};

void starbar(char ch, int num){
    int count;
    for(count = 1;count <= num; count++){
        putchar(ch);
    }
    putchar('\r\n');
}

*/
