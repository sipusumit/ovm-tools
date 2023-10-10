#include "parser.h"
/*
  MOV - 0x69
*/

uint8_t parseReg(std::string_view r){
  if(r == "R0") return static_cast<uint8_t>(REG::R_R0);
  if(r == "R1") return static_cast<uint8_t>(REG::R_R1);
  if(r == "R2") return static_cast<uint8_t>(REG::R_R2);
  if(r == "R3") return static_cast<uint8_t>(REG::R_R3);
  exit(-1);
}

void Parser::parseAdd()
{
  // writeFile(outFile,)
}

void Parser::parseMov()
{
  uint8_t m[1] = {0x69};
  writeFile(outFile, m, sizeof(m));
  at++;
  uint8_t reg[1] = {parseReg(tokens[at].value)};
  writeFile(outFile, reg, sizeof(reg));
  at++;
  at++;
  // std::cout << tokens[0].value << "\n";
  uint8_t v[1] = {(uint8_t)std::stoi(tokens[at].value)};
  writeFile(outFile, v, sizeof(v));
}

int Parser::parse()
{
  switch (tokens[0].type){
    case T_MOV:
      std::cout << "MOV";
      parseMov();
      break;
    case T_ADD:
      parseAdd();
      break;
    case T_AND:
      break;
    case T_JMP:
      break;
    case T_JMPp:
      break;
    case T_JMPz:
      break;
    case T_JMPn:
      break;
    case T_JSR:
      break;
    case T_LD:
      break;
    case T_LDR:
      break;
    case T_LEA:
      break;
    case T_NOT:
      break;
    case T_RET:
      break;
    case T_STRINGZ:
      break;
    case T_SYSCALL:
      break;
    case T_HALT:
      break;
    case T_IDENT:
      break;
    default:
      return -1;
      break;
  }
  return 0;
}