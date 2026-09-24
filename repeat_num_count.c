#include<stdio.h>

int main(){
    int arr[10]={0}; //part 1
    int var= 234356;
    int rem;

    
    while(var!=0){                  // part 2
        rem= var%10;
        if(arr[rem]==1){
            break;
        }
        arr[rem]=1;
        var=var/10;
    }
    
    if(var>0)                   //part 3
        printf("Yes");
    else
        printf("No");
        
        
    return 0;
}