#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_ID_LEN 31 // Restrict identifier length

// Function to check if a character is an operator
int isOperator(char ch) {
    char operators[] = "+-*/=<>!&|";
    for (int i = 0; i < strlen(operators); i++) {
        if (ch == operators[i])
            return 1;
    }
    return 0;
}

// Function to analyze lexical tokens
void lexicalAnalyzer(char *input) {
    int i = 0;
    while (input[i] != '\0') {
        // Ignore spaces, tabs, and new lines
        if (isspace(input[i])) {
            i++;
            continue;
        }
        
        // Ignore comments
        if (input[i] == '/' && input[i + 1] == '/') { // Single-line comment
            while (input[i] != '\n' && input[i] != '\0') i++;
            continue;
        } else if (input[i] == '/' && input[i + 1] == '*') { // Multi-line comment
            i += 2;
            while (!(input[i] == '*' && input[i + 1] == '/') && input[i] != '\0') i++;
            if (input[i] != '\0') i += 2;
            continue;
        }
        
        // Identifiers
        if (isalpha(input[i]) || input[i] == '_') {
            char identifier[MAX_ID_LEN + 1];
            int j = 0;
            while (isalnum(input[i]) || input[i] == '_') {
                if (j < MAX_ID_LEN)
                    identifier[j++] = input[i];
                i++;
            }
            identifier[j] = '\0';
            printf("Identifier: %s\n", identifier);
            continue;
        }
        
        // Constants
        if (isdigit(input[i])) {
            char constant[20];
            int j = 0;
            while (isdigit(input[i])) {
                constant[j++] = input[i];
                i++;
            }
            constant[j] = '\0';
            printf("Constant: %s\n", constant);
            continue;
        }
        
        // Operators
        if (isOperator(input[i])) {
            printf("Operator: %c\n", input[i]);
            i++;
            continue;
        }
        
        // Unrecognized character
        printf("Unrecognized character: %c\n", input[i]);
        i++;
    }
}

int main() {
    char input[] = "  int x = 100; // This is a comment\n  x = x + 20;  /* Multi-line \n comment */ \n  return x;";
    printf("Lexical Analysis:\n");
    lexicalAnalyzer(input);
    return 0;
}
