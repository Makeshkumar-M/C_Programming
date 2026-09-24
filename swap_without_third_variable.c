#include<stdio.h>


int main(){
    int a=4;
    int b=5;
	
    printf("The value before the swap %d %d\n",a,b);
	
    a=a+b;
    b=a-b;
    a=a-b;
	
    printf("The value after the swap %d %d\n",a,b);
}