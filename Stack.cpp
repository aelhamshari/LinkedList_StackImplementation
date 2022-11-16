/* -------------------------------------------------
 *
 * File Name: Stack.cpp
 * Author: Afnan Elhamshari
 * Description: Implementation of the Stack class
 * Date: 11/16/2022
 *
 ------------------------------------------------ */
#include "Stack.h"
#include "LinkedList.h"
#include <iostream>
using namespace std;

template <typename T>
Stack<T>::Stack()
{
  
}

template <typename T>
Stack<T>::~Stack()
{
  while (!(isEmpty()))
  {
    pop();
  }
}

template <typename T>
Stack<T>::Stack(const Stack<T>& original)
{
  if(!(original.m_list.isEmpty()))
  {
    m_list = original.m_list;
  }
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& original)
{
  if(!(original.m_list.isEmpty()))
  {
    this->m_list = original.m_list;
  }
  return ((*this));
}

template <typename T>
T Stack<T>:: peek() const
{
  if (m_list.isEmpty())
  {
    throw(std::runtime_error ("Nothing to peek at.\n"));
  }
  return (m_list.getEntry(m_list.getLength()));
}

template <typename T>
void Stack<T>::pop() 
{
    if (m_list.isEmpty())
    {
      throw (std::runtime_error("Your Stack is Empty.\n"));
    }
    else
    {
      try
      {
        m_list.remove(m_list.getLength());
      }
      catch (std::runtime_error& e)
      {
        cout <<e.what();
      }
    }
}

template <typename T>
void Stack<T>::push(T entry)
{
  if (m_list.getLength()+1<=0)
  {
    throw(std::runtime_error("Can't Push here!\n"));
  }
  else
  {
    try
    {
      m_list.insert(m_list.getLength()+1, entry);
    }
    catch (std::runtime_error& e)
    {
      cout <<e.what();
    }
  }
}

template <typename T>
bool Stack<T>::isEmpty() const
{
  return (m_list.isEmpty());
}

template <typename T>
int Stack<T>::getstackLength() const
{
  return (m_list.getLength());
}
