#include "stdlib.h"

#include "expr.h"

expr_t *expr_ident_create(token_t *t, char *name) {
    expr_t *expr = (expr_t *)malloc(sizeof(expr_t));
    expr->type = EXPR_IDENT;
    expr->expr.ident = (expr_ident_t){
        .token = t,
        .name = name};

    return expr;
}
