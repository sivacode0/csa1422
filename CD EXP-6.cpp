#include <stdio.h>
#include <string.h>

#define MAX_RULES 10
#define MAX_LEN 50

// Structure to store a production rule
typedef struct {
    char lhs[MAX_LEN];  // Left hand side of the production
    char rhs[MAX_LEN];  // Right hand side of the production
} Production;

// Function to remove left recursion
void eliminateLeftRecursion(Production grammar[], int ruleCount) {
    for (int i = 0; i < ruleCount; i++) {
        // Check if the production is left-recursive
        if (grammar[i].rhs[0] == grammar[i].lhs[0]) {
            char newNonTerminal[MAX_LEN];
            snprintf(newNonTerminal, sizeof(newNonTerminal), "%s'", grammar[i].lhs); // A'
            
            printf("Left recursion detected in rule: %s → %s\n", grammar[i].lhs, grammar[i].rhs);
            
            // Create the new non-recursive production
            printf("%s → ", grammar[i].lhs);
            for (int j = 1; grammar[i].rhs[j] != '\0'; j++) {
                printf("%c", grammar[i].rhs[j]);
            }
            printf("%s\n", newNonTerminal); // A' production

            // Create the new A' production
            printf("%s → ", newNonTerminal);
            for (int j = 1; grammar[i].rhs[j] != '\0'; j++) {
                printf("%c", grammar[i].rhs[j]);
            }
            printf("%s | ε\n", newNonTerminal); // A' → αA' | ε
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
        printf("Enter production rule %d (e.g., A → Aα | β):\n", i+1);
        printf("LHS: ");
        scanf("%s", grammar[i].lhs);
        printf("RHS: ");
        scanf("%s", grammar[i].rhs);
    }

    // Call function to eliminate left recursion
    eliminateLeftRecursion(grammar, ruleCount);
    
    return 0;
}
