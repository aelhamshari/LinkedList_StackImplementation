/* -------------------------------------------------
 *
 * File Name: Node.cpp
 * Author: Afnan Elhamshari
 * Description: Implementation of the Node class
 * Date: 11/16/2022
 *
 ------------------------------------------------ */
 #include "Node.h"

 template <typename T>
 Node<T>::Node()
 {
   m_next = nullptr;
 }

template <typename T>
Node<T>::Node (T value)
{
  m_value = value;
  m_next= nullptr;
}

template <typename T>
Node<T>::Node (const Node& original)
{
  m_value = original.value;
  m_next= original.m_next;
}

template <typename T>
Node<T>::Node(const T& value, Node<T>* next)
{
  m_value = value;
  m_next = next;
}

template <typename T>
void Node<T>::setValue (const T& entry)
{
  m_value = entry;
}

template <typename T>
void Node<T>::setNext(Node<T>* next)
{
  m_next = next;
}

template <typename T>
T Node<T>::getValue()const
{
  return (m_value);
}

template <typename T>
T* Node<T>::getValueptr()
{
  return (&m_value);
}

template <typename T>
Node<T>* Node<T>::getNext()const
{
  return (m_next);
}
