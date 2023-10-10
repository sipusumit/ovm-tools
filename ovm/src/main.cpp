#include<iostream>

#include "utils.h"

void help(){
  std::cout << "Usage:\n" 
            << "      ovm <file>";
}

int main(int argc, char const *argv[]){
  if(argc < 2){
    help();
  }
  std::vector<unsigned char> buf = readFile(argv[1]);
  for(unsigned char c: buf){
    std::cout << c << "\n";
  }
  return 0;
}