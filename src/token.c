#include "token.h"

#include <string.h>

keyword keywords[] = {
    {"fn", FUNCTION},
    {"let", LET},
    {"true", TRUE},
    {"false", FALSE},
    {"if", IF},
    {"else", ELSE},
    {"return", RETURN}};

TokenType lookup_ident(char *ident) {
    for (int i = 0; i < sizeof(keywords) / sizeof(keyword); i++)
        if (strcmp(keywords[i].ident, ident) == 0)
            return keywords[i].type;

    return IDENT;
}