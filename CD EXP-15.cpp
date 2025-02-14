#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent an intermediate code instruction
typedef struct {
    char operation[10];   // Operation (e.g., ADD, SUB)
    char operand1[10];    // First operand
    char operand2[10];    // Second operand
    char result[10];      // Result of operation
} ThreeAddressCode;

// Function to generate the assembly-like code for intermediate code
void generateAssembly(ThreeAddressCode *icode, int size) {
    printf("Assembly Code Generation:\n");
    for (int i = 0; i < size; i++) {
        if (strcmp(icode[i].operation, "ADD") == 0) {
            printf("MOV %s, %s\n", icode[i].result, icode[i].operand1);
            printf("ADD %s, %s\n", icode[i].result, icode[i].operand2);
        } else if (strcmp(icode[i].operation, "SUB") == 0) {
            printf("MOV %s, %s\n", icode[i].result, icode[i].operand1);
            printf("SUB %s, %s\n", icode[i].result, icode[i].operand2);
        } else if (strcmp(icode[i].operation, "MUL") == 0) {
            printf("MOV %s, %s\n", icode[i].result, icode[i].operand1);
            printf("MUL %s, %s\n", icode[i].result, icode[i].operand2);
        } else if (strcmp(icode[i].operation, "DIV") == 0) {
            printf("MOV %s, %s\n", icode[i].result, icode[i].operand1);
            printf("DIV %s, %s\n", icode[i].result, icode[i].operand2);
        }
    }
}

// Function to generate three-address code from an arithmetic expression
void generateIntermediateCode(char *expression) {
    ThreeAddressCode icode[10]; // Temporary array for storing intermediate code
    int tempVarCount = 0;  // Temporary variable count

    // For simplicity, assume the expression contains only addition, subtraction, multiplication, and division
    // Example: a + b * c - d
    // The intermediate code will represent: t1 = b * c, t2 = a + t1, result = t2 - d

    // Here, we manually create intermediate code for the expression "a + b * c - d"
    strcpy(icode[0].operation, "MUL");
    strcpy(icode[0].operand1, "b");
    strcpy(icode[0].operand2, "c");
    sprintf(icode[0].result, "t%d", ++tempVarCount);

    strcpy(icode[1].operation, "ADD");
    strcpy(icode[1].operand1, "a");
    strcpy(icode[1].operand2, icode[0].result);
    sprintf(icode[1].result, "t%d", ++tempVarCount);

    strcpy(icode[2].operation, "SUB");
    strcpy(icode[2].operand1, icode[1].result);
    strcpy(icode[2].operand2, "d");
    strcpy(icode[2].result, "result");

    // Print intermediate code
    printf("Intermediate Code Generation:\n");
    for (int i = 0; i <= tempVarCount; i++) {
        printf("%s = %s %s %s\n", icode[i].result, icode[i].operand1, icode[i].operation, icode[i].operand2);
    }

    // Generate Assembly-like code from intermediate code
    generateAssembly(icode, tempVarCount + 1);
}

int main() {
    char expression[] = "a + b * c - d";  // Example arithmetic expression
    printf("Input Expression: %s\n\n", expression);

    // Generate intermediate code and then convert to assembly-like code
    generateIntermediateCode(expression);

    return 0;
}
