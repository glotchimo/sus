#include "stdio.h"
#include "stdlib.h"

#include "ast.h"
#include "expr.h"
#include "lexer.h"
#include "parser.h"
#include "stmt.h"

#define MAX_ERROR_AMOUNT 256
#define MAX_ERROR_SIZE 32

parser_t *parser_new(lexer_t *l) {
    parser_t *p = (parser_t *)malloc(sizeof(parser_t));
    p->l = l;
    parser_next_token(p);
    parser_next_token(p);

    p->errors = (char **)malloc(MAX_ERROR_AMOUNT);
    for (int i = 0; i < MAX_ERROR_AMOUNT; i++) {
        p->errors[i] = (char *)malloc(MAX_ERROR_SIZE + 1);
    }

    return p;
}

void parser_destroy(parser_t *p) {
    for (int i = 0; i < MAX_ERROR_AMOUNT; i++) {
        free(p->errors[i]);
    }
    free(p->errors);
    free(p->l);
}

program_t *parser_parse_program(parser_t *p) {
    program_t *program = (program_t *)malloc(sizeof(program_t));

    while (p->current_token.type != EoF) {
        stmt_t *stmt = parser_parse_stmt(p);
        program_add_stmt(program, stmt);
        parser_next_token(p);
    }

    return program;
}

char **parser_errors(parser_t *p) {
    return p->errors;
}

void parser_next_token(parser_t *p) {
    p->current_token = p->peek_token;
    p->peek_token = lexer_next_token(p->l);
}

bool parser_current_token_is(parser_t *p, token_type_t t) {
    return p->current_token.type == t;
}

bool parser_peek_token_is(parser_t *p, token_type_t t) {
    return p->peek_token.type == t;
}

bool parser_expect_peek(parser_t *p, token_type_t t) {
    if (parser_peek_token_is(p, t)) {
        parser_next_token(p);
        return true;
    } else {
        parser_peek_error(p, t);
        return false;
    }
}

void parser_peek_error(parser_t *p, token_type_t t) {
    char *msg = (char *)malloc(MAX_ERROR_SIZE);
    sprintf(msg, "expected %d, got %d", t, p->peek_token.type);
    p->errors[++p->num_errors] = msg;
}

stmt_t *parser_parse_stmt(parser_t *p) {
    switch (p->current_token.type) {
    case VOTE:
        return parser_parse_stmt_vote(p);
        break;

    default:
        return NULL;
        break;
    }
}

stmt_t *parser_parse_stmt_vote(parser_t *p) {
    token_t t = p->current_token;
    if (!parser_expect_peek(p, IDENT)) {
        return NULL;
    }

    expr_t *i = expr_ident_create(&t, p->current_token.literal);
    if (!parser_expect_peek(p, ASSIGN)) {
        return NULL;
    }

    while (!parser_current_token_is(p, SEMICOLON)) {
        parser_next_token(p);
    }

    stmt_t *s = stmt_vote_create(&t, i, NULL);

    return s;
}