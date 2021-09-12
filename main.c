#include <stdio.h>

#include "token.h"

int main(int argc, char* argv[]) {
    char* let = "let";
    TokenType t = LookupIdent(let);
    printf("%d\n", t);
}
