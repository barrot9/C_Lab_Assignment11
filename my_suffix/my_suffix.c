#include <stdio.h>
#include <string.h>

#define SIZE 128

/* Function prototypes */
int my_suffix(char str[], char c);

int main() {
    char str[SIZE]; 
    char c; 
    int numSuffixes; 
    
    printf("Enter a string: \n");
    scanf("%s", str);
    
    printf("Enter a character: \n");
    scanf(" %c", &c);
    
    numSuffixes = my_suffix(str, c);
    
    printf("Total substrings starting with '%c': %d\n", c, numSuffixes);
    
    return 0;
}

/* Function to print substrings starting with character c */
int my_suffix(char str[], char c) {
    int count = 0; 
    int len = strlen(str); 
    int i; 
    
    printf("Substrings starting with '%c':\n", c);
    
    for (i = 0; i < len; i++) { 
        if (str[i] == c) { 
            printf("%s\n", &str[i]); 
            count++; 
        }
    }
    
    return count; /* Return the total count of suffixes */
}

