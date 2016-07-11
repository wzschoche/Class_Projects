#pragma once
/*
William Zschoche
Data Structures Project #1
undo/redo
*/

#include <cassert>

/*
The Node struct and template acts as a wrapper to allow LinkedStack to
accommodate any type.
*/
template <class T>
struct Node {
  Node(T* _contents, Node* _next) {
    contents = _contents;
    next = _next;
  }

  //Node memory deallocation will be handled by LinkedStack.

  T* contents;
  Node<T>* next;
};

/*
LinkedStack class
  Linked list implemented as a stack.
*/

template <class T>
class LinkedStack{
public:
  LinkedStack() {
    top = NULL;
    count = 0;
  }

  ~LinkedStack() { clear(); }

  int size() { return count; }
  bool empty() { return top == NULL; }

  T* peek() {
    assert(!empty());
    return top->contents;
  }

  void push(T* elt) {
    top = new Node<T>(elt, top);
    ++count;
  }

  //Pop() remove Node object from the stack.
  //NOTE: does not deallocate the memory of the Node contents.
  void pop() {
    assert(!empty());
    Node<T>* p = top;
    top = top->next;
    delete p;
    p = NULL;
    --count;
  }

  //Free the memory used by each Node and remove pop them from the stack
  //Clear() should be used at the end of program as it will delete
  //the contents of each node.
  void clear() {
    while (!empty()) {
      delete peek();
      pop();
    }
  }

private:
  Node<T>* top;
  int count;
};
