#ifndef SUS_LEXER_H
#define SUS_LEXER_H

#include "stdbool.h"

#include "token.h"

typedef struct {
    char *input;
    int position;
    int readPosition;
    char ch;
} lexer_t;

lexer_t *lexer_new();
void lexer_destroy(lexer_t *l);
token_t lexer_next_token(lexer_t *l);

void lexer_read_char(lexer_t *l);
char *lexer_read_ident(lexer_t *l);
char *lexer_read_num(lexer_t *l);

char lexer_peek_char(lexer_t *l);
void lexer_skip_whitespace(lexer_t *l);

bool is_letter(char ch);
bool is_digit(char ch);

void set_token(token_t *token, token_type_t type, char ch);

#endif