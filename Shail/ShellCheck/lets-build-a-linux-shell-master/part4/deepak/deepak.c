#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to check if a string is a palindrome
bool isPalindrome(const char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return false; // Characters at the corresponding positions don't match
        }
    }
    return true; // All characters matched, it's a palindrome
}

int main() {
    char input[100];
    
    // Input a string
    printf("Enter a string: ");
    scanf("%s", input);
    
    // Check if the input string is a palindrome
    if (isPalindrome(input)) {
        printf("%s is a palindrome.\n", input);
    } else {
        printf("%s is not a palindrome.\n", input);
    }
    
    return 0;
}
