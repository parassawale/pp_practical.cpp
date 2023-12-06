#include <iostream>
#include <string>

class MyString {
public:
  // Constructor
  MyString(const std::string& str) : str_(str) {}

  // Equality comparison operator
  bool operator==(const MyString& other) const {
    return str_ == other.str_;
  }

  // String copy
  MyString& operator=(const MyString& other) {
    str_ = other.str_;
    return *this;
  }

  // Concatenation
  MyString operator+(const MyString& other) const {
    return MyString(str_ + other.str_);
  }

  // String display
  friend std::ostream& operator<<(std::ostream& os, const MyString& str) {
    os << str.str_;
    return os;
  }

  // String reversal
  MyString operator~() const {
    MyString reversed;
    for (int i = str_.length() - 1; i >= 0; --i) {
      reversed.str_ += str_[i];
    }
    return reversed;
  }

  // Palindrome check
  bool isPalindrome() const {
    for (int i = 0; i < str_.length() / 2; ++i) {
      if (str_[i] != str_[str_.length() - 1 - i]) {
        return false;
      }
    }
    return true;
  }

  // Substring occurrence
  int countSubString(const std::string& sub_str) const {
    int count = 0;
    int pos = str_.find(sub_str);
    while (pos != std::string::npos) {
      ++count;
      pos = str_.find(sub_str, pos + 1);
    }
    return count;
  }

private:
  std::string str_;
};

int main() {
  MyString str1("Hello");
  MyString str2("World");

  // Equality
  if (str1 == str2) {
    std::cout << "Strings are equal" << std::endl;
  } else {
    std::cout << "Strings are not equal" << std::endl;
  }

  // String copy
  str1 = str2;
  std::cout << "str1 after copy: " << str1 << std::endl;

  // Concatenation
  MyString str3 = str1 + str2;
  std::cout << "str3: " << str3 << std::endl;

  // String display
  std::cout << "str2: " << str2 << std::endl;

  // String reversal
  MyString reversedStr = ~str2;
  std::cout << "Reversed str2: " << reversedStr << std::endl;

  // Palindrome check
  if (str2.isPalindrome()) {
    std::cout << "str2 is a palindrome" << std::endl;
  } else {
    std::cout << "str2 is not a palindrome" << std::endl;
  }

  // Substring occurrence
  int count = str3.countSubString("llo");
  std::cout << "Number of occurrences of 'llo': " << count << std::endl;

  return 0;
}
