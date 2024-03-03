/// grepCore houses all the primary functions required for the project

#pragma once
#include <iostream>
#include <vector>
#include <string>

void grepMain(int argc, char *argv[]);

void printVector(std::vector<std::string> &vector);

bool foundInString(const std::string &mainString, const std::string &keyString);
int findStringPos(const std::string &mainString, const std::string &keyString);

std::string stripOptions(std::string options);

bool checkLines(std::string keyString, std::vector<std::string> *lines, std::string options = "");