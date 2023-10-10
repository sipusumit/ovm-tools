#include<iostream>
#include<string>
#include<stdint.h>

#include "utils.h"
#include "parser.h"

int main(int argc, char const *argv[]){
  if(argc < 2){
    help();
  }
  std::string src = readFile(argv[1]);
  uint8_t a[2] = {0x4f, 0x4d};

  Parser p(src, "./a.bin");
  p.parse();
  // writeFile("a.bin", a, sizeof(a));
  return 0;
}