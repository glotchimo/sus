#ifndef SUS_AST_H
#define SUS_AST_H

#include "stmt.h"

typedef struct {
    void *stmt;
    void *next;
} node_t;

typedef struct {
    node_t *head;
} program_t;

void program_add_stmt(program_t *p, void *stmt);

#endif