#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char next_char(char c) {
    return (c == 'z') ? 'a' : c + 1;
}

void CreaStringRec(char** s, int k, int* len, int* capacity) {
    int current_len = *len;

    

    if (*len >= k) return;

    // Realloc se serve
    if (*len + current_len > *capacity) {
        *capacity *= 2;
        char* temp = realloc(*s, (*capacity) * sizeof(char));
        if (temp == NULL) {
            fprintf(stderr, "Errore realloc.\n");
            free(*s);
            exit(1);
        }
        *s = temp;
    }

    for (int i = 0; i < current_len && *len < k; i++) {
        (*s)[*len] = next_char((*s)[i]);
        (*len)++;
    }

    CreaStringRec(s, k, len, capacity);
}

int main(int argc, char** argv) {
    if (argc != 3 || strlen(argv[1]) == 0 || atoi(argv[2]) <= 0) {
        return 1;
    }

    char* input = argv[1];
    int k = atoi(argv[2]);

    int len = strlen(input);
    int capacity = len * 2;

    char* s = malloc(capacity * sizeof(char));
    if (s == NULL) {
        fprintf(stderr, "Errore allocazione.\n");
        return 1;
    }

    strcpy(s, input);

    CreaStringRec(&s, k, &len, &capacity);

    printf("%c", s[k - 1]);
    free(s);
    return 0;
}
