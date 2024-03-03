/// grepCore houses all the primary functions required for the project

#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void grepMain(int argc, char *argv[]);

bool foundInString(const std::string &mainString, const std::string &keyString, const bool reversed = false);

std::string stripOptions(std::string options);

bool checkLines(std::string keyString, std::vector<std::string> *lines, std::string options = "");