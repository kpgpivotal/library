
#ifndef UTILS_H
#define UTILS_H

#define pragma
#include <iostream>
#include <string>
#include <stdlib.h>
#include <cctype>
#include <algorithm>

#include <boost/log/trivial.hpp>



using namespace std;

char get_input(string prompt);
char getCharValidInput(string prompt, char validValue1, char validValue2);

void showError(string errorMessage);
void info(string infoMessage);
void info(string infoMessage, int num);
void message(string message);
string capitalizeFirstLetter(string text);
int case_insensitive_match(string s1, string s2);
void print_line();
int read_numeric_input();
int read_numeric_input(string mesage);
void log_info(string info);


#endif