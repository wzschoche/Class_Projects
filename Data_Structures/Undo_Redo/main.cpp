/*
William Zschoche
Data Structures Project #1
Undo/Redo

Event-driven text editor using a stack data structure and OOP polymorphism
to simulate undo/redo feature.
*/

#include <iostream>
#include <string>
#include <limits>

#include "Event.h"
#include "Input.h"
#include "Toggle.h"
#include "Backspace.h"
#include "LinkedStack.h"

//Avoid Intellisense warning of "max" macro on Visual Studio for Windows.
#undef max

std::string getInput();
void processText( std::string &str );
void print(LinkedStack<Event> &u, LinkedStack<Event> &r, std::string &s);

int main() {

  do {
    std::cout << "Enter input: ";
    processText(getInput());

    std::cout << "again? (Y/N) ";

  } while (tolower(getInput().front()) == 'y');

  return 0;
}


//Convert user input into Events and build resulting text buffer.
void processText( std::string &str ) {
  LinkedStack<Event> undo, redo;
  std::string buffer;

  for (std::string::iterator i = str.begin(); i != str.end(); ++i) {
    switch (*i) {
    case 'Z':
      if (!undo.empty()) {
        buffer = undo.peek()->undo(buffer);
        redo.push(undo.peek());
        undo.pop();
      }
      break;

    case 'R':
      if (!redo.empty()) {
        buffer = redo.peek()->do_(buffer);
        undo.push(redo.peek());
        redo.pop();
      }
      break;

    default:
      Event *e;

      switch (*i) {
      case 'T':
        e = new Toggle();
        break;

      case 'B':
        e = new Backspace(buffer);
        break;

      default:
        e = new Input(*i);
      }
      
      undo.push(e);
      buffer = e->do_(buffer);
      redo.clear();
      break;
    }
    print(undo, redo, buffer);
  }
  undo.clear();
  redo.clear();
}

//Retrieve user input and validate.
std::string getInput() {
  std::string input = "";

  while (true) {
    if (std::getline(std::cin, input) && input.compare("") != 0) {
      break;
    }
    else {
      std::cout << "Please enter a valid input." << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }

  return input;
}


//Print Event stacks and buffer status.
void print( LinkedStack<Event> &u, LinkedStack<Event> &r,
                std::string &s) {
std::cout << "undo=" << u.size() << " redo=" << r.size() << " buffer=" << s << std::endl;
}
