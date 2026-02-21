#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    
    scanf("%s", str);   // Input string (no spaces)
    
    int start = 0;
    int end = strlen(str) - 1;
    
    while(start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        
        start++;
        end--;
    }
    
    printf("%s", str);
    
    return 0;
}
