#include <stdio.h>

void removeExtraSpaces(FILE *input, FILE *output) {
    char ch, prev = '\0';
    int newline_count = 0;
    int space_count = 0;

    while ((ch = fgetc(input)) != EOF) {
        // Handle string literals
        if (ch == '"') {
            if (prev != '\\') {
                fputc(ch, output);
                while ((ch = fgetc(input)) != EOF && (ch != '"' || prev == '\\')) {
                    fputc(ch, output);
                    prev = ch;
                }
                if (ch == '"') fputc(ch, output);
                continue;
            }
        }

        // Handle newlines
        if (ch == '\n') {
            newline_count++;
            if (newline_count <= 1) {
                if (prev != ' ' && prev != '\n') {
                    fputc(ch, output);
                }
            }
            space_count = 0;
            prev = ch;
            continue;
        }

        // Handle spaces and tabs
        if (ch == ' ' || ch == '\t') {
            space_count++;
            if (space_count <= 1 && prev != '\n') {
                fputc(' ', output);
            }
            prev = ' ';
            continue;
        }

        // Reset counters for non-space characters
        if (ch != ' ' && ch != '\n' && ch != '\t') {
            newline_count = 0;
            space_count = 0;
            fputc(ch, output);
            prev = ch;
        }
    }
}

int main() {
    FILE *input = fopen("input.c", "r");
    FILE *output = fopen("output.c", "w");
    
    if (input == NULL || output == NULL) {
        printf("Error opening files!\n");
        return 1;
    }

    removeExtraSpaces(input, output);
    
    fclose(input);
    fclose(output);
    printf("File processed successfully. Check output.c for results.\n");
    return 0;
}