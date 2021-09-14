#ifndef LEXER_H
#define LEXER_H

#include <stdbool.h>

#include "token.h"

typedef struct {
    char *input;
    int position;
    int readPosition;
    char ch;
} Lexer;

Lexer *lexer_new();
Token lexer_next_token(Lexer *l);

void lexer_read_char(Lexer *l);
char *lexer_read_ident(Lexer *l);
char *lexer_read_num(Lexer *l);

char lexer_peek_char(Lexer *l);
void lexer_skip_whitespace(Lexer *l);

bool is_letter(char ch);
bool is_digit(char ch);

void set_token(Token *token, TokenType type, char ch);

#endif