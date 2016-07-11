#pragma once

/*
William Zschoche
Data Structures Project #1
undo/redo
*/

#include "Event.h"

/*
Backspace class
  constructor:  Constructs teh Backspace event object and Copies the character
                to be removed by the "Backspace" action from the buffer string.

          do_:  Removes last character from the "buffer" string and returns the
                resulting string.

         undo:  Replaces character removed by Backspace Event to the end of the
                buffer string and returns resulting string.        
*/
class Backspace : public Event
{
public:
  Backspace( std::string buffer ) : _c(buffer.back()) { }

  virtual std::string do_(std::string buffer) { return stringPopBack(buffer); }
  virtual std::string undo(std::string buffer) { return stringPushBack(buffer); }

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
