#ifndef SUS_EXPR_H
#define SUS_EXPR_H

#include "token.h"

typedef enum {
    EXPR_IDENT
} expr_type_t;

typedef struct expr expr_t;
typedef struct expr_ident expr_ident_t;

struct expr_ident {
    token_t *token;
    char *name;
};

struct expr {
    expr_type_t type;
    union {
        expr_ident_t ident;
    } expr;
};

expr_t *expr_ident_create(token_t *t, char *name);

#endif