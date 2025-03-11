#include <stdio.h>

void removeComments(FILE *input) {
    char ch, prev = '\0';
    int singleLine = 0, multiLine = 0;
    int inString = 0;

    while ((ch = fgetc(input)) != EOF) {
        // Handle string literals
        if (ch == '"' && !singleLine && !multiLine) {
            inString = !inString;
            putchar(ch);
            prev = ch;
            continue;
        }

        if (inString) {
            putchar(ch);
            prev = ch;
            continue;
        }

        if (singleLine) {
            if (ch == '\n') {
                singleLine = 0;
                putchar(ch);
            }
            continue;
        }

        if (multiLine) {
            if (prev == '*' && ch == '/') {
                multiLine = 0;
                prev = '\0';
            } else {
                prev = ch;
            }
            continue;
        }

        if (ch == '/' && prev == '/') {
            singleLine = 1;
            if (prev != '\0') {
                putchar('\b');  // Remove the previous '/'
            }
            prev = '\0';
        } else if (ch == '*' && prev == '/') {
            multiLine = 1;
            if (prev != '\0') {
                putchar('\b');  // Remove the previous '/'
            }
            prev = '\0';
        } else {
            if (prev != '\0') {
                putchar(prev);
            }
            prev = ch;
        }
    }

    if (!multiLine && !singleLine && prev != '/' && prev != '\0') {
        putchar(prev);
    }
}

int main() {
    FILE *input = fopen("C:/Users/kumar/OneDrive/Pictures/Documents/Projects/DSA practise/pointers/input.c", "r");
    if (input == NULL) {
        printf("Error opening input file!\n");
        return 1;
    }

    removeComments(input);
    fclose(input);
    return 0;
}