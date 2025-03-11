#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR 50

// List of keywords
const char *keywords[] = {"int", "for", "while", "if", "else", "return", "float", "char", "double", "void"};
#define NUM_KEYWORDS (sizeof(keywords) / sizeof(keywords[0]))

// Function to check if a string is a keyword
int isKeyword(const char *str) {
    for (int i = 0; i < NUM_KEYWORDS; i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    FILE *f1;
    char c, str[MAX_STR];
    int lineno = 1, num = 0, i = 0;

    printf("Enter your C program:\n");

    // Create and write input to a file
    f1 = fopen("input.txt", "w");
    while ((c = getchar()) != EOF) {
        putc(c, f1);
    }
    fclose(f1);

    // Read input file for lexical analysis
    f1 = fopen("input.txt", "r");

    while ((c = getc(f1)) != EOF) {
        // Handle numbers
        if (isdigit(c)) {
            num = c - '0';
            c = getc(f1);
            while (isdigit(c)) {
                num = num * 10 + (c - '0');
                c = getc(f1);
            }
            printf("%d is a number\n", num);
            ungetc(c, f1); // Put back the last character
        }

        // Handle identifiers and keywords
        else if (isalpha(c) || c == '_') { // Identifiers can start with letters or underscores
            i = 0;
            str[i++] = c;
            c = getc(f1);

            while (isalnum(c) || c == '_') { // Identifiers can contain letters, numbers, and underscores
                str[i++] = c;
                c = getc(f1);
            }
            str[i] = '\0'; // Null-terminate the string
            ungetc(c, f1); // Put back the last character

            if (isKeyword(str))
                printf("%s is a keyword\n", str);
            else
                printf("%s is an identifier\n", str);
        }

        // Ignore whitespace (spaces, tabs)
        else if (c == ' ' || c == '\t') {
            continue; // Skip unnecessary spaces and tabs
        }

        // Handle new lines
        else if (c == '\n') {
            lineno++;
        }

        // Handle special symbols
        else {
            printf("%c is a special symbol\n", c);
        }
    }

    printf("Total number of lines: %d\n", lineno);
    fclose(f1);
    return 0;
}

