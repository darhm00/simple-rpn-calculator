#include <iostream>
#include <vector>
#include "lex.hpp"
#include "eval.hpp"

int main() {
  std::vector<Token> tokens;
  std::vector<int> stack;
  std::string text;

  std::cout << "Welcome to the Simple RPN Calculator v1" << '\n'
            << "Copyright (C) 2023 Dar. H. M." << '\n';

  while (true) {
    std::cout << ">>";
    std::getline(std::cin, text);

    tokens = lex(text);
    tok_eval(tokens, stack);
  }

  return 0;
}
