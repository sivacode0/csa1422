#include <stdio.h>
#include <string.h>

// Function to check if the string follows the grammar S ? aSb | e
int checkGrammar(char *str) {
    int countA = 0, countB = 0;

    // Traverse the string
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == 'a') {
            countA++;
        } else if (str[i] == 'b') {
            countB++;
        } else {
            // Invalid character, not part of the grammar
            return 0;
        }
    }

    // If the count of 'a' and 'b' are equal and 'a' comes before 'b', grammar is satisfied
    if (countA == countB) {
        return 1;
    }

    return 0;
}

// Main function
int main() {
    char str[100];
    
    printf("Enter a string: ");
    scanf("%s", str);
    
    // Check if the string satisfies the grammar
    if (checkGrammar(str)) {
        printf("The string satisfies the grammar.\n");
    } else {
        printf("The string does not satisfy the grammar.\n");
    }

    return 0;
}
