#ifndef SUS_PARSER_H
#define SUS_PARSER_H

#include "ast.h"
#include "lexer.h"
#include "token.h"

typedef struct {
    lexer_t *l;
    token_t current_token;
    token_t peek_token;
    char **errors;
    int num_errors;
} parser_t;

parser_t *parser_new(lexer_t *l);
void parser_destroy(parser_t *p);
program_t *parser_parse_program(parser_t *p);
char **parser_errors(parser_t *p);

void parser_next_token(parser_t *p);
bool parser_current_token_is(parser_t *p, token_type_t t);
bool parser_peek_token_is(parser_t *p, token_type_t t);
bool parser_expect_peek(parser_t *p, token_type_t t);
void parser_peek_error(parser_t *p, token_type_t t);

stmt_t *parser_parse_stmt(parser_t *p);
stmt_t *parser_parse_stmt_vote(parser_t *p);

#endif