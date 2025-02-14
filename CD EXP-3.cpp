#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_ID_LEN 31 // Restrict identifier length

// Function to check if a character is an arithmetic operator
int isArithmeticOperator(char ch) {
    char operators[] = "+-*/";
    for (int i = 0; i < strlen(operators); i++) {
        if (ch == operators[i])
            return 1;
    }
    return 0;
}

// Function to check if a line is a comment
int isComment(char *input, int i) {
    if (input[i] == '/' && input[i + 1] == '/') {
        printf("Single-line comment\n");
        return 1;
    } else if (input[i] == '/' && input[i + 1] == '*') {
        printf("Multi-line comment\n");
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
        
        // Check comments
        if (isComment(input, i)) {
            if (input[i] == '/' && input[i + 1] == '/') {
                while (input[i] != '\n' && input[i] != '\0') i++;
            } else if (input[i] == '/' && input[i + 1] == '*') {
                i += 2;
                while (!(input[i] == '*' && input[i + 1] == '/') && input[i] != '\0') i++;
                if (input[i] != '\0') i += 2;
            }
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
        
        // Arithmetic Operators
        if (isArithmeticOperator(input[i])) {
            printf("Arithmetic Operator: %c\n", input[i]);
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