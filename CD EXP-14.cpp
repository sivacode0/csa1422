#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to represent an expression
typedef struct Expr {
    char expr[50];   // Expression as a string (e.g., "b + c * d")
    int result;      // Result of the expression
    int computed;    // Flag to check if it has been computed
} Expr;

// Function to check if two expressions are the same
int areExpressionsEqual(char *expr1, char *expr2) {
    return (strcmp(expr1, expr2) == 0);
}

// Function to eliminate common subexpressions
void eliminateCommonSubexpressions(char *expr, Expr *exprTable, int *exprCount) {
    for (int i = 0; i < *exprCount; i++) {
        // Check if the current expression matches any of the previously computed expressions
        if (areExpressionsEqual(exprTable[i].expr, expr)) {
            printf("Common subexpression detected: %s\n", expr);
            printf("Reusing the result %d\n", exprTable[i].result);
            return;  // Reuse the result and stop further computation
        }
    }

    // If the expression is new, compute and store it
    Expr newExpr;
    strcpy(newExpr.expr, expr);   // Store the expression
    newExpr.result = rand() % 100; // Simulate a computed result
    newExpr.computed = 1;          // Mark it as computed

    exprTable[*exprCount] = newExpr;  // Store the new expression in the table
    (*exprCount)++;

    printf("New computation for expression: %s\n", expr);
    printf("Computed result: %d\n", newExpr.result);
}

int main() {
    Expr exprTable[50];  // Table to store previously computed expressions
    int exprCount = 0;   // Counter for the number of stored expressions

    char expr[50];

    // Read expressions until end of input (Ctrl+D or Ctrl+Z)
    while (1) {
        printf("Enter an expression (or 'exit' to quit): ");
        fgets(expr, sizeof(expr), stdin);

        // Remove newline character from input
        expr[strcspn(expr, "\n")] = '\0';

        if (strcmp(expr, "exit") == 0) {
            break;
        }

        // Eliminate common subexpressions
        eliminateCommonSubexpressions(expr, exprTable, &exprCount);
    }

    return 0;
}
