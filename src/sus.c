#include "stdio.h"
#include "stdlib.h"

#include "lexer.h"
#include "parser.h"
#include "token.h"

void loop();
char *read_line();

int main(int argc, char *argv[]) {
    fprintf(stdout, "--- sus - v0.0.0 - test shell ---\n");
    loop();
}

void loop() {
    char *line;

    do {
        printf("ඞ ");
        line = read_line();

        lexer_t *l = lexer_new(line);
        parser_t *p = parser_new(l);
        parser_parse_program(p);
        for (int i = 0; i < 256; i++) {
            fprintf(stdout, "%s", p->errors[i]);
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