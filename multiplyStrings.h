#ifndef _MULTIPLYSTRINGS_H_
#define _MULTIPLYSTRINGS_H_
#include <string>
#include <iostream>

std::string multiply(std::string num1, std::string num2)
{
	int str1 = stoi(num1);
	int str2 = stoi(num2);
	int retNum = str1 * str2;
	return std::to_string(retNum); 
}

#endif
