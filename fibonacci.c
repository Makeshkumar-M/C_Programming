#include <stdio.h>

int main(){
    int num;
    
    printf("Enter the number to find fibonacci series length: ");
    scanf("%d", &num);
    
    if (num <= 0) {
        printf("Enter a positive number\n");
        return 1;
    }
    
    int prev = 0, curr = 1;
    
    printf("Fibonacci series: ");
    for (int i = 0; i < num; i++) {
        printf("%d ", prev);
        
        int next = prev + curr;  // Local, not static
        prev = curr;
        curr = next;
    }
    printf("\n");
    
    return 0;
}