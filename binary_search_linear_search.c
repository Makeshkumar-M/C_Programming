/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int linearsearch(int arr[],int size, int key);
int binarysearch(int arr[],int size, int key);

int linearsearch(int arr[],int size,int key)
{
    for(int i=0;i<size;i++){
        if (arr[i]==key){
            return i;
        }
       
    }
    return -1;
}


/*Binary search best for sorted array*/
int binarysearch(int arr[],int size, int key){

    int low = 0;
    int high = size -1;
   
    while(low <= high){
        int mid = low + (high - low)/2;
        if (arr[mid]==key)
         return mid;
        else if (arr[mid]<key){
            low = mid +1;
        } 
        else
            low =mid -1;
    } 
    return -1;
}
int main()
{
int arr[]={3,5,7,8,9};
int size;
int key = 7;
int result,result2;

size = sizeof(arr)/sizeof(arr[0]);

result = linearsearch(arr,size,key);
result2 = binarysearch(arr,size,key);



if (result!= -1){
    printf("The value is present in the inde: %d\n", result);
    printf("The value is present in the inde: %d\n", result2);
    
}
else
{
    printf("The value is not there in the array");
}
    return 0;
}