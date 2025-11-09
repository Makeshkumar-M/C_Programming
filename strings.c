#include <stdio.h>

int main() {
    char str[100];
    int i, count;
    
    printf("Enter a string: ");
    scanf("%[^\n]", str);  // Read string with spaces
    
    count = 0;
    i = 0;
    
    // Loop through each character until end of string
    while (str[i] != '\0') {
        // Check if character is a letter (A-Z or a-z)
        if ((str[i] >= 'A' && str[i] <= 'Z') || 
            (str[i] >= 'a' && str[i] <= 'z')) {
            count++;
        }
        i++;
    }
    
    printf("Number of letters: %d\n", count);
    
    return 0;
}