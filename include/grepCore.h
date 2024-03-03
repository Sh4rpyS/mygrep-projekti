/// grepCore houses all the primary functions required for the project

#pragma once
#include <iostream>
#include <vector>
#include <string>

void grepMain(int argc, char *argv[]);

void printVector(std::vector<std::string> &vector);

bool foundInString(std::string &mainString, std::string &keyString);
int findStringPos(std::string &mainString, std::string &keyString);

std::vector<std::string> *findFromLines(std::string keyString, std::vector<std::string> *lines);