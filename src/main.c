#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 2048

int is_zero(const char *str)
{
    for (; *str != '\0'; ++str)
        if (*str != '0')
            return 0;

    return 1;
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "Need at least one argument.\n");
        exit(0);
    }

    char buffer[MAX_LINE_LENGTH];
    FILE *file = stdin;
    char *search = argv[1];
    int search_len = strlen(search);

    if (argc == 3) {
        file = fopen(argv[2], "r");

        if (!file) {
            fprintf(stderr, "Error opening file.\n");
            exit(0);
        }
    }

    while (fgets(buffer, MAX_LINE_LENGTH, file)) {
        for (size_t i = 0; i < MAX_LINE_LENGTH - search_len; ++i) {
            char candidate_str[search_len + 1];
            memcpy(candidate_str, buffer + i, search_len);
            candidate_str[search_len] = '\0';

            if (!is_zero(candidate_str) && strcmp(search, candidate_str) == 0) {
                printf("%s", buffer);
                break;
            }
        }

        memset(buffer, 0, MAX_LINE_LENGTH);
    }

    if (file) {
        fclose(file);
    }

    return 0;
}
