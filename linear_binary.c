/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int linearsearch(int arr[], int len, int key);
int binarysearch(int arr[], int len ,int key);

int linearsearch(int arr[],int len,int key){
   
    for (int i=0; i<=len; i++){
        if (arr[i]==key){
            return i;
        }
    
    }
    return -1;
}


int binarysearch(int arr[], int len , int key){
    int low = 0 , high = len -1;
    while ( low <=high ){
        int mid = low + ( high - low)/2;
        if ( arr[mid]==key)
    {
        return mid;
        
    }
    else if{
        if( arr[mid]<key){
            low = mid +1;
            
        }
    }
    else{
         if (arr[mid]>key){
             low = mid -1;
         }
     }
     
     return -1;
    }
    
}

int main()
{
int arr[]={ 3,4,5,7};

int key;
int len = sizeof(arr)/sizeof(arr[0]);
int result;

printf("Enter the number");
scanf("%d",&key);

result = linearsearch(arr, len, key);
result = binarysearch(arr, len, key);
if (result != -1)

{
    printf("The value is at %d", result);
}
else{
     printf("hey i am not able not to see the result");
}

}
