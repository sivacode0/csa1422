#include <stdio.h>
#include <ctype.h>

int main() {
    char ch;
    int charCount = 0, wordCount = 0, lineCount = 0;
    int inWord = 0;  // Flag to track if we are inside a word

    // Prompt the user to input text
    printf("Enter text (Ctrl+D or Ctrl+Z to end input):\n");

    // Read input until End Of File (EOF) or Ctrl+D (Unix) / Ctrl+Z (Windows)
    while ((ch = getchar()) != EOF) {
        charCount++;  // Count every character

        // Count newlines for line count
        if (ch == '\n') {
            lineCount++;
        }

        // Word count: Detect transitions from non-whitespace to whitespace
        if (isspace(ch)) {
            if (inWord) {
                wordCount++;  // End of a word
                inWord = 0;   // Reset the flag
            }
        } else {
            inWord = 1;  // We are inside a word
        }
    }

    // If the last word doesn't end with a space/newline, count it
    if (inWord) {
        wordCount++;
    }

    // Output the results
    printf("\nResults:\n");
    printf("Total Characters: %d\n", charCount);
    printf("Total Words: %d\n", wordCount);
    printf("Total Lines: %d\n", lineCount);

    return 0;
}
