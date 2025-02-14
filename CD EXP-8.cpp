#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SYMBOLS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int value;
} Symbol;

typedef struct {
    Symbol symbols[MAX_SYMBOLS];
    int count;
} SymbolTable;

void initSymbolTable(SymbolTable *table) {
    table->count = 0;
}

int addSymbol(SymbolTable *table, const char *name, int value) {
    if (table->count >= MAX_SYMBOLS) {
        return -1; // Table is full
    }
    strcpy(table->symbols[table->count].name, name);
    table->symbols[table->count].value = value;
    table->count++;
    return 0; // Success
}

int getSymbolValue(SymbolTable *table, const char *name) {
    for (int i = 0; i < table->count; i++) {
        if (strcmp(table->symbols[i].name, name) == 0) {
            return table->symbols[i].value;
        }
    }
    return -1; // Symbol not found
}

void printSymbolTable(SymbolTable *table) {
    printf("Symbol Table:\n");
    for (int i = 0; i < table->count; i++) {
        printf("Name: %s, Value: %d\n", table->symbols[i].name, table->symbols[i].value);
    }
}

int main() {
    SymbolTable table;
    initSymbolTable(&table);

    addSymbol(&table, "x", 10);
    addSymbol(&table, "y", 20);
    addSymbol(&table, "z", 30);

    printSymbolTable(&table);

    printf("Value of x: %d\n", getSymbolValue(&table, "x"));
    printf("Value of y: %d\n", getSymbolValue(&table, "y"));
    printf("Value of z: %d\n", getSymbolValue(&table, "z"));
    printf("Value of a: %d\n", getSymbolValue(&table, "a")); // Not found

    return 0;
}
