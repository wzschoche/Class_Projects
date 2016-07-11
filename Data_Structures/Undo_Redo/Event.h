#pragma once

/*
William Zschoche
Data Structures Project #1
undo/redo
*/

#include <string>

//Given base class for the undo/redo project.
class Event
{
public:
  virtual std::string do_  (std::string buffer) = 0;
  virtual std::string undo (std::string buffer) = 0;
};


/*
Input Class
  constructor:  Creates Input Event object and saves character from user input.
          do_:  Places character at the end of the buffer string.
         undo:  Removes last character from buffer string.
*/

class Input : public Event
{
public:
  Input(char c) : _c(c) { }

  virtual std::string do_(std::string buffer) { return stringPushBack(buffer); }
  virtual std::string undo(std::string buffer) { return stringPopBack(buffer); }

private:
  char _c;

  std::string stringPushBack(std::string s) {
    s.push_back(_c);
    return s;
  }

  std::string stringPopBack(std::string s) {
    s.pop_back();
    return s;
  }
};
