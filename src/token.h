#ifndef SUS_TOKEN_H
#define SUS_TOKEN_H

typedef enum {
    ILLEGAL = -2,
    EoF = -1,
    IDENT = 0,
    INT,
    ASSIGN,
    PLUS,
    MINUS,
    BANG,
    ASTERISK,
    SLASH,
    LT,
    GT,
    EQ,
    NOT_EQ,
    LEQ,
    GEQ,
    COMMA,
    SEMICOLON,
    LPAREN,
    RPAREN,
    LBRACE,
    RBRACE,
    LBRACKET,
    RBRACKET,
    TASK,
    VOTE,
    EJECT,
    CREWMATE,
    IMPOSTOR,
    CARDSWIPE,
    TOOFAST,
    VENT,
    MEDSCAN
} token_type_t;

typedef struct {
    char *ident;
    token_type_t type;
} keyword;

typedef struct {
    token_type_t type;
    char *literal;
} token_t;

token_type_t lookup_ident(char *ident);

token_t token_create(token_type_t type, char *literal);
token_t *token_duplicate(token_t *t);
void token_destroy(token_t *t);

#endif