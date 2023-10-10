#include "utils.h"

std::string readFile(std::string path){
  std::ifstream input(path, std::ios::binary);
  std::stringstream buffer;
  buffer << input.rdbuf();
  input.close();
  return buffer.str();
}

void writeFile(std::string path, uint8_t* data, size_t len){
  std::ofstream output(path, std::ios::out | std::ios::binary | std::ios::app);
  output.write((char *)data, len);
  output.close();
}

void help(){
  std::cout << "Usage:\n" 
            << "      ovmc <file>";
}

char escape(char s)
{
  switch (s)
  {
  case 'n':
    return '\n'; 
    break;
  case 't':
    return '\t'; 
    break;
  default:
    break;
  }
  return s;
}

std::string parseString(std::string str){
  if(str.size() > 2 && str[0] == '"' && str[str.size() -1 ] == '"'){
    str = str.substr(1, str.size()-2);
  }

  for(std::string::iterator it = str.begin(); it != str.end(); it++){
    *it.base() = escape(*it.base());
  }
  return str;
}