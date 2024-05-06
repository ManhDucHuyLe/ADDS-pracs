#include "Reverser.h"

#include <cmath>
#include <iostream>

Reverser::Reverser() {}

int Reverser::reverseDigit(int value) {
  string strNum = to_string(value);
  int l = strNum.length();
  if (value < 10) {
    return value;
  } else if (value < 0) {
        return -1;
  } else {
    int a = value % 10;
    a *= pow(10, l - 1);
    a += reverseDigit(value / 10);
    return a;
  }
}

string Reverser::reverseString(string characters) {
  int l = characters.length();
  if (l < 0) {
    return "ERROR";
  } else if (l == 1) {
    return characters;
  } else {
    char a = characters[l - 1];
    string reversedSubstring = reverseString(characters.substr(0, l - 1));
    return a + reversedSubstring;
  }
}
