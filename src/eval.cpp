#include <iostream>
#include <vector>
#include "eval.hpp"

void tok_eval(std::vector<Token> tokens, std::vector<int> &stack) {
  int a, b;

  for (Token &tok : tokens) {
    switch (tok.type) {
      case TOKEN_NUMBER:
        stack.push_back(std::atoi(tok.value.c_str()));
        break;

      case TOKEN_OPERAND:
        if (tok.value == "+") {
            if (stack.size() < 2) {
              std::cout << "Stack underflow!" << '\n';
              return;
            }

            a = stack.back();
            stack.pop_back();

            b = stack.back();
            stack.pop_back();

            stack.push_back(a + b);

        } else if (tok.value == "-") {
          if (stack.size() < 2) {
            std::cout << "Stack underflow!" << '\n';
            return;
          }

          a = stack.back();
          stack.pop_back();

          b = stack.back();
          stack.pop_back();

          stack.push_back(a - b);

        } else if (tok.value == "#") {
          if (stack.size() < 1) {
            std::cout << "Stack underflow!" << '\n';
            return;
          }

          a = stack.back();
          stack.pop_back();

          std::cout << a << '\n';
        } else if (tok.value == ".") {
          std::exit(0);
        }

        break;
    }
  }
}

