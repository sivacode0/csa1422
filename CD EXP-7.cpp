#include <stdio.h>
#include <string.h>

#define MAX_RULES 10
#define MAX_LEN 50

// Structure to store a production rule
typedef struct {
    char lhs[MAX_LEN];  // Left hand side of the production
    char rhs[MAX_LEN];  // Right hand side of the production
} Production;

// Function to find the longest common prefix
int longestCommonPrefix(char* str1, char* str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i]) {
        i++;
    }
    return i;
}

// Function to eliminate left factoring
void eliminateLeftFactoring(Production grammar[], int ruleCount) {
    for (int i = 0; i < ruleCount; i++) {
        // Check each production rule to see if there is left factoring
        for (int j = i + 1; j < ruleCount; j++) {
            if (grammar[i].lhs[0] == grammar[j].lhs[0]) {
                // Find the longest common prefix of the two rules
                int prefixLength = longestCommonPrefix(grammar[i].rhs, grammar[j].rhs);
                
                if (prefixLength > 0) {
                    char newNonTerminal[MAX_LEN];
                    snprintf(newNonTerminal, sizeof(newNonTerminal), "%s'", grammar[i].lhs); // A'
                    
                    printf("Left factoring detected in rules: %s → %s and %s → %s\n", grammar[i].lhs, grammar[i].rhs, grammar[j].lhs, grammar[j].rhs);
                    
                    // Create the new non-recursive production
                    printf("%s → ", grammar[i].lhs);
                    for (int k = 0; k < prefixLength; k++) {
                        printf("%c", grammar[i].rhs[k]);
                    }
                    printf("%s\n", newNonTerminal); // A' production
                    
                    // Create the new A' productions
                    printf("%s → ", newNonTerminal);
                    for (int k = prefixLength; grammar[i].rhs[k] != '\0'; k++) {
                        printf("%c", grammar[i].rhs[k]);
                    }
                    printf(" | ");
                    for (int k = prefixLength; grammar[j].rhs[k] != '\0'; k++) {
                        printf("%c", grammar[j].rhs[k]);
                    }
                    printf("\n");
                }
            }
        }
    }
}

// Main function
int main() {
    Production grammar[MAX_RULES];
    int ruleCount;
    
    // Reading the number of rules
    printf("Enter number of production rules: ");
    scanf("%d", &ruleCount);

    // Reading the rules
    for (int i = 0; i < ruleCount; i++) {
        printf("Enter production rule %d (e.g., A → αβ | αγ):\n", i+1);
        printf("LHS: ");
        scanf("%s", grammar[i].lhs);
        printf("RHS: ");
        scanf("%s", grammar[i].rhs);
    }

    // Call function to eliminate left factoring
    eliminateLeftFactoring(grammar, ruleCount);
    
    return 0;
}
