#include "BigNumCalc.h"

BigNumCalc::BigNumCalc() {}

BigNumCalc::~BigNumCalc() {}

std::list<int> BigNumCalc::buildBigNum(std::string numString) {
  std::list<int> bigNum;
  for (char digit : numString) {
    if (isdigit(digit)) {
      bigNum.push_back(digit - '0');
    }
  }
  return bigNum;
}

std::list<int> BigNumCalc::add(std::list<int> num1, std::list<int> num2) {
  std::list<int> result;
  int carry = 0;

  while (!num1.empty() || !num2.empty() || carry) {
    int sum = carry;
    if (!num1.empty()) {
      sum += num1.back();
      num1.pop_back();
    }
    if (!num2.empty()) {
      sum += num2.back();
      num2.pop_back();
    }

    result.push_front(sum % 10);
    carry = sum / 10;
  }

  return result;
}

std::list<int> BigNumCalc::sub(std::list<int> num1, std::list<int> num2) {
  std::list<int> result;
  int borrow = 0;

  while (!num1.empty() || !num2.empty()) {
    int sum1 = 0, sum2 = 0;
    if (!num1.empty()) {
      sum1 = num1.back();
      num1.pop_back();
    }
    if (!num2.empty()) {
      sum2 = num2.back();
      num2.pop_back();
    }

    int difference = sum1 - sum2 - borrow;
    if (difference < 0) {
      difference += 10;
      borrow = 1;
    } else {
      borrow = 0;
    }
    result.push_front(difference);
  }

  while (!result.empty() && result.front() == 0) {
    result.pop_front();
  }

  if (result.empty()) {
    result.push_back(0);
  }

  return result;
}

std::list<int> BigNumCalc::mul(std::list<int> num1, std::list<int> num2) {
  int digit = num2.front();
  num2.pop_front();

  std::list<int> result = num1;
  int carry = 0;

  for (auto i = result.rbegin(); i != result.rend(); ++i) {
    int product = *i * digit + carry;
    *i = product % 10;
    carry = product / 10;
  }

  while (carry) {
    result.push_front(carry % 10);
    carry /= 10;
  }

  return result;
}
