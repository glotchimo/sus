#include "stdlib.h"
#include "string.h"

#include "token.h"

keyword keywords[] = {
    {"task", TASK},           // function definition
    {"vote", VOTE},           // variable definition
    {"eject", EJECT},         // memory release
    {"crewmate", CREWMATE},   // true
    {"impostor", IMPOSTOR},   // false
    {"cardswipe", CARDSWIPE}, // if
    {"toofast", TOOFAST},     // else
    {"vent", VENT},           // goto
    {"medscan", MEDSCAN}};    // return

int lookup_ident(char *ident) {
    for (int i = 0; i < sizeof(keywords) / sizeof(keyword); i++)
        if (strcmp(keywords[i].ident, ident) == 0)
            return keywords[i].type;

    return IDENT;
}

token_t token_create(token_type_t type, char *literal) {
    token_t *token = (token_t *)malloc(sizeof(token_t));
    token->type = type;
    token->literal = literal;

    return *token;
}

token_t *token_duplicate(token_t *t) {
}

void token_destroy(token_t *t) {
    free(t->literal);
    free(t);
}