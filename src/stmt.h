#ifndef SUS_STMT_H
#define SUS_STMT_H

#include "ast.h"
#include "expr.h"
#include "token.h"

typedef enum {
    STMT_VOTE,
    STMT_MEDSCAN,
    STMT_EXPR,
    STMT_BLOCK
} stmt_type_t;

typedef struct stmt stmt_t;
typedef struct stmt_vote stmt_vote_t;
typedef struct stmt_medscan stmt_medscan_t;
typedef struct stmt_vent stmt_vent_t;
typedef struct stmt_expr stmt_expr_t;
typedef struct stmt_block stmt_block_t;

struct stmt_vote {
    token_t *token;
    expr_t *name;
    expr_t *value;
};

struct stmt_medscan {
    token_t *token;
    expr_t *value;
};

struct stmt_vent {
    token_t *token;
    stmt_t **body;
};

struct stmt_expr {
    token_t *token;
    expr_t *expr;
};

struct stmt_block {
    token_t *token;
    stmt_t **body;
};

struct stmt {
    stmt_type_t type;
    union {
        stmt_vote_t vote;
        stmt_medscan_t medscan;
        stmt_expr_t expr;
        stmt_block_t block;
    } stmt;
};

stmt_t *stmt_vote_create(token_t *t, expr_t *name, expr_t *value);
void stmt_vote_free(stmt_t *s);

stmt_t *stmt_medscan_create(token_t *t, expr_t *value);
void stmt_medscan_free(stmt_t *s);

stmt_t *stmt_vent_create(token_t *t, expr_t **body);
void stmt_vent_free(stmt_t *s);

stmt_t *stmt_expr_create(token_t *t, expr_t *expr);
void stmt_expr_free(stmt_t *s);

stmt_t *stmt_block_create(token_t *t, stmt_t **body);
void stmt_block_free(stmt_t *s);

#endif