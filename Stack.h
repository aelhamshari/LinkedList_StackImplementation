/* -------------------------------------------------
 *
 * File Name: ListInterface.h
 * Author: Afnan Elhamshari
 * Description: Declaration of the ListInterface
 * Date: 11/16/2022
 *
 ------------------------------------------------ */
#ifndef STACK_H
#define STACK_H
#include "StackInterface.h"
#include "LinkedList.h"
#include <stdexcept>

template <typename T>
class Stack: public StackInterface<T>
{
  private:
    LinkedList<T> m_list;

  public:
    /*
    * @pre none
    * @post creates a Stack object
    */
    Stack();
    /*
    * @pre a Stack object
    * @post creates a copy of the Stack object
    * @param a Stack object passed by reference
    */
    Stack(const Stack<T>& original);
    /*
    * @pre a Stack object
    * @post creates a copy of the Stack object
    * @param a Stack object passed by reference
    * @return returns a copy of the Stack object
    */
    Stack<T>& operator=(const Stack<T>& original);
    /*
    * @pre an existing Stack object
    * @post destructs the LinkedList object used to create the stack
    */
    ~Stack();
    /*
    * @pre a stack is constructed and have at least one value on it
    * @post The value of the top of the stack is returned
    * @throw std::runtime_error if the stack is empty
    */
    T peek() const;
    /*
    * @pre a stack is constructed and have at least one value on it
    * @post the top of the stack is removed
    * @throw std::runtime_error if the stack is empty
    */
    void pop();
    /*
    * @pre The position is length+1
    * @post The entry is inserted at the given position
    * @param entry: An entry to put in the stack
    * @throw std::runtime_error if the position is invalid.
    */
    void push(T entry);
    /*
    * @pre none
    * @post checks if the list is empty or not
    * @return returns if the list is empty
    */
    bool isEmpty() const;
    /*
    * @pre a stack length member variable exists
    * @post the length of the stack is returned
    * @return the length of the stack
    */
    int getstackLength() const;
};
#include "Stack.cpp"
#endif
