#include <stdio.h>

int main()
{

int arr[5];
int size = sizeof(arr)/sizeof(arr[0]);
printf("Enter the array values:");
for(int i=0; i<size; i++){
    scanf("%d",&arr[i]);
}

for(int j=0; j<size; j++){
    printf("The index %d: The value %d:\n",j, arr[j]);
    
}

}