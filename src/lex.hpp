#pragma once

#include <iostream>
#include <vector>

enum TokenType {
  TOKEN_NUMBER,
  TOKEN_OPERAND
};

enum LexerState {
  LEXERSTATE_MATCH,
  LEXERSTATE_SEEK
};

struct Token {
  std::string value;
  TokenType type;
};

std::vector<Token> lex(std::string text);
void dump_tokens(std::vector<Token> tokens);
