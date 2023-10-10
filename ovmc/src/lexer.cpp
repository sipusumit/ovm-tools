#include "lexer.h"
#include "utils.h"

fifo_map<std::string,TokenType> PATTERNS = {
  {R"(^\r?\n)", T_WS},
  {R"(^ )", T_WS},
  {R"(^MOV(?=[^a-zAZ0-9_]))", T_MOV},
  {R"(^ADD(?=[^a-zAZ0-9_]))", T_ADD},
  {R"(^AND(?=[^a-zAZ0-9_]))", T_AND},
  {R"(^JMP(?=[^a-zAZ0-9_]))", T_JMP},
  {R"(^JMPp(?=[^a-zAZ0-9_]))", T_JMPp},
  {R"(^JMPz(?=[^a-zAZ0-9_]))", T_JMPz},
  {R"(^JMPn(?=[^a-zAZ0-9_]))", T_JMPn},
  {R"(^JSR(?=[^a-zAZ0-9_]))", T_JSR},
  {R"(^LD(?=[^a-zAZ0-9_]))", T_LD},
  {R"(^LDR(?=[^a-zAZ0-9_]))", T_LDR},
  {R"(^LEA(?=[^a-zAZ0-9_]))", T_LEA},
  {R"(^NOT(?=[^a-zAZ0-9_]))", T_NOT},
  {R"(^RET(?=[^a-zAZ0-9_]))", T_RET},
  {R"(^STRINGZ(?=[^a-zAZ0-9_]))", T_STRINGZ},
  {R"(^SYSCALL(?=[^a-zAZ0-9_]))", T_SYSCALL},
  {R"(^HALT(?=[^a-zAZ0-9_]))", T_HALT},
  {R"(^[a-zA-Z_]+[a-zA-Z0-9_]*)", T_IDENT},
  {R"(^\"(?:\\.|[^\"])*\")", T_STRING},
  {R"(^[0-9]+)", T_NUMBER},
  {R"(^\,)", T_COMMA},

};


Token Lexer::getNextToken(){
  if(at >= src.size()) return {.type = T_EOF};
  std::string str = std::string(src).substr(at);
  for(fifo_map<std::string, TokenType>::iterator it = PATTERNS.begin(); it != PATTERNS.end(); it++){
    std::regex r(it->first);
    std::smatch m;
    std::regex_search(str, m, r);
    if(!m.empty()){
      at += m[0].length();
      Token t;
      if(it->second == T_WS){
        return getNextToken();
      }
      if(it->second == T_STRING){
        t = Token{.type = it->second, .value = parseString(m[0].str())};
      }
      else{
        t = Token{.type = it->second, .value = m[0]};
      }
      return t;
    }
  }
  exit(-1);
}