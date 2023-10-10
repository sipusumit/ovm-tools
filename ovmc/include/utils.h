#pragma once

#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#include<stdint.h>

std::string readFile(std::string path);
void writeFile(std::string path, uint8_t* data, size_t len);
void help();
char escape(char s);

std::string parseString(std::string str);