#include <stdio.h>
#include <stdlib.h>

#include "lexer.h"
#include "token.h"

int main(int argc, char *argv[]) {
    char *test = (char *)malloc(15);
    test = "let five = 5;\0";

    Lexer *l = lexer_new(test);

    Token t = lexer_next_token(l);
    while (t.type != EoF) {
        printf("%d ", t.type);
        t = lexer_next_token(l);
    }
}
