/// Used in increment 1

/// Standalone is a program state that's run when no other arguments are given for the program.

#pragma once
#include <iostream>
#include <string>

void standaloneStringFinder(const std::string options = "");
int findStringPos(const std::string &mainString, const std::string &keyString);