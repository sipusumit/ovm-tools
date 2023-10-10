#include "utils.h"

std::vector<unsigned char> readFile(std::string path){
  std::ifstream input(path, std::ios::binary);

  return std::vector<unsigned char>(std::istreambuf_iterator<char>(input), {});
}