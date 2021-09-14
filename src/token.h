#ifndef TOKEN_H
#define TOKEN_H

typedef int TokenType;

typedef struct {
    TokenType type;
    char *literal;
} Token;

enum {
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
    COMMA,
    SEMICOLON,
    LPAREN,
    RPAREN,
    LBRACE,
    RBRACE,
    FUNCTION,
    LET,
    TRUE,
    FALSE,
    IF,
    ELSE,
    RETURN
};

typedef struct {
    char *ident;
    TokenType type;
} keyword;

TokenType lookup_ident(char *ident);

#endif