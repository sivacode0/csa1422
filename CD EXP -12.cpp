#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generateTAC(char *expr) {
    char *token = strtok(expr, " ");
    int tempCount = 0;

    while (token != NULL) {
        if (strcmp(token, "+") == 0 || strcmp(token, "-") == 0 || 
            strcmp(token, "*") == 0 || strcmp(token, "/") == 0) {
            printf("t%d = %s %s %s\n", tempCount++, token, strtok(NULL, " "), strtok(NULL, " "));
        } else {
            printf("%s\n", token);
        }
        token = strtok(NULL, " ");
    }
}

int main() {
    char expr[100];
    printf("Enter an expression: ");
    fgets(expr, sizeof(expr), stdin);
    generateTAC(expr);
    return 0;
}
