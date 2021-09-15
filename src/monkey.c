#include <stdio.h>
#include <stdlib.h>

#include "lexer.h"
#include "token.h"

void loop();
char *read_line();

int main(int argc, char *argv[]) {
    fprintf(stdout, "--- libmonkey - v0.0.0 - test shell ---\n");
    loop();
}

void loop() {
    char *line;

    do {
        printf("🐒 ");
        line = read_line();

        Lexer *l = lexer_new(line);
        Token t = lexer_next_token(l);
        while (t.type != EoF) {
            fprintf(stdout, "%d ", t.type);
            t = lexer_next_token(l);
        }
        fprintf(stdout, "\n");

        free(line);
    } while (true);
}

char *read_line() {
    char *line = NULL;
    size_t bufsize = 0;

    if (getline(&line, &bufsize, stdin) == -1) {
        if (feof(stdin)) {
            exit(EXIT_SUCCESS);
        } else {
            perror("readline");
            exit(EXIT_FAILURE);
        }
    }

    return line;
}