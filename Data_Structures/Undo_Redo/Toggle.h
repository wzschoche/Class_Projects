#pragma once
/*
William Zschoche
Data Structures Project #1
undo/redo
*/

#include "Event.h"

/*
Toggle Class
  constructor:  Creates Toggle Event object.

          do_:  Removes last character in buffer string, verifies that it is an
                alphabetic character, and replaces that character with the opposite
                case character.

         undo:  See do_ member function--functionally the same.
*/
class Toggle : public Event
{
public:
  Toggle() { }

  virtual std::string do_(std::string buffer) { return stringToggleCase(buffer); }
  virtual std::string undo(std::string buffer) { return stringToggleCase(buffer); }

private:
  std::string stringToggleCase(std::string s) {
    int i = s.length() - 1;
    char c = s.back();
    
    if (isalpha(c)) {

      if (isupper(c))
        c = tolower(c);
      else
        c = toupper(c);

      s.back() = c;
    }
    return s;
  }
};
