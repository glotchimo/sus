#include "stdlib.h"

#include "stmt.h"
#include "token.h"

stmt_t *stmt_vote_create(token_t *t, expr_t *name, expr_t *value) {
    stmt_t *stmt = (stmt_t *)malloc(sizeof(stmt_t));
    stmt->type = STMT_VOTE;
    stmt->stmt.vote = (stmt_vote_t){
        .token = t,
        .name = name,
        .value = value};

    return stmt;
}

void stmt_vote_destroy(stmt_t *s) {
    token_destroy(s->stmt.vote.token);
}