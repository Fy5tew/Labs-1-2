#pragma once
#include <string>
#include "Stack.h"


void writeStackToFile(Stack<int>& stack, std::string filename);


void readStackFromFile(Stack<int>& stack, std::string filename);
