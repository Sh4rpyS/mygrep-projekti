#pragma once
#include <vector>
#include <string>

/// grepCore houses all the primary functions required for the project

void grepMain(int argc, char *argv[]);
std::vector<std::string> *validateArguments(int argc, char *argv[]);