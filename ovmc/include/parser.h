#pragma once

#include<vector>

#include "lexer.h"
#include "utils.h"

enum class OP: uint8_t{
  OP_MOV = 0x69,
  OP_ADD = 0x70,
};

enum class REG : uint8_t{
  R_R0 = 0x01,
  R_R1 = 0x02,
  R_R2 = 0x03,
  R_R3 = 0x04,
};


class Parser{
private:
  std::string outFile;
  Lexer lexer;
  std::vector<Token> tokens;
  size_t at;
  void parseAdd();
  void parseMov();
public:
  Parser(std::string_view src, std::string outFile): lexer(src), outFile(outFile),at(0){
    Token t = lexer.getNextToken();
    while(t.type != T_EOF){
      tokens.push_back(t);
      std::cout << t.type << " " << t.value << "\n";
      t = lexer.getNextToken();
    }
    tokens.push_back({.type = T_EOF});
  };
  int parse();
};