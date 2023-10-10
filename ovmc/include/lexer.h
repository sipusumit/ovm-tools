#pragma once

#include<string>
#include<iostream>
#include<regex>

#include"fifo_map.hpp"

enum TokenType{
  T_MOV,
  T_ADD,
  T_AND,
  T_JMP,
  T_JMPp,
  T_JMPz,
  T_JMPn,
  T_JSR,
  T_LD,
  T_LDR,
  T_LEA,
  T_NOT,
  T_RET,
  T_STRINGZ,
  T_SYSCALL,
  T_HALT,
  T_IDENT,
  T_STRING,
  T_NUMBER,
  T_COMMA,
  T_EOF,
  T_WS,
};

using namespace nlohmann;

extern fifo_map<std::string, TokenType> PATTERNS;

struct Token{
  TokenType type;
  std::string value;
};

class Lexer{
private:
  std::string_view src;
  int at;
public:
  Lexer(std::string_view src): src(src), at(0){};
  Token getNextToken();
};