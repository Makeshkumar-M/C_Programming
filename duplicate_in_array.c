//code to find the duplicate element in the array

#include<stdio.h>

int main(){
int arr[5]={ 1,2,3,3,5};
int size= sizeof(arr)/sizeof(arr[0]);

for(int i=0;i<size;i++){
    for(int j=i+1;j<size;j++){
        if(arr[i]==arr[j])
        {
            printf("The duplicate value:%d\n",arr[i]);
        }
    }
}
return 0;
}