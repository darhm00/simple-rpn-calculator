#include <iostream>
#include <vector>
#include "lex.hpp"

std::vector<Token> lex(std::string text) {
  std::vector<Token> tokens;
  LexerState state = LEXERSTATE_SEEK;
  Token tok;

  for (char &c : text) {
    switch (state) {
lexer_seek:
      case LEXERSTATE_SEEK:
        if (c >= '0' && c <= '9') {
          tok.value = c;
          tok.type = TOKEN_NUMBER;

          tokens.push_back(tok);

          state = LEXERSTATE_MATCH;
        } else if (c == '+' || c == '-' || c == '#' || c == '.') {
          tok.value = c;
          tok.type = TOKEN_OPERAND;

          tokens.push_back(tok);
        }

        break;

      case LEXERSTATE_MATCH:
        if (c >= '0' && c <= '9') {
          tok = tokens[tokens.size() - 1];

          tok.value.push_back(c);

          tokens[tokens.size() - 1] = tok;
        } else {
          state = LEXERSTATE_SEEK;
          goto lexer_seek;
        }

        break;
    }
  }

  return tokens;
}

void dump_tokens(std::vector<Token> tokens) {
  std::cout << "-- token dump --" << '\n';
  for (Token &tok : tokens) {
    std::cout << ((tok.type == TOKEN_NUMBER) ? "num" : "op") << ": " << tok.value << '\n';
  }
  std::cout << "-- end token dump --" << '\n';
}
