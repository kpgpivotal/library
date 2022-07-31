
#ifndef UTILS_H
#define UTILS_H

#define pragma
#include <iostream>
#include <string>
#include <stdlib.h>
#include <cctype>
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <string_view>
#include <bits/stdc++.h>



using namespace std;
using namespace std::literals;

const int INPUT_RETRY_COUNT = 3;

char get_input_char(string prompt);
string get_input_string(string prompt);
string get_input_email(string prompt);
long get_input_long(string prompt);
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
bool is_starts_with(string theString,string prefix);
bool isDigit(const char c);
bool is_valid_email(string email);


#endif