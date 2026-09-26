#include <stdio.h>

int a=5;
void *ptr = &a;

int main(){

printf("The derefrenced pointer: %d\n",*(int*)ptr);
}