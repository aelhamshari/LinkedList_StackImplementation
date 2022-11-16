/* -------------------------------------------------
 *
 * File Name: LinkedList.cpp
 * Author: Afnan Elhamshari
 * Description: Implementation of the LinkedList class
 * Date: 11/16/2022
 *
 ------------------------------------------------ */
#include "LinkedList.h"
#include <iostream>
using namespace std;

template <typename T>
LinkedList<T>::LinkedList()
{
  m_front = nullptr;
  m_length = 0;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList& original)
{
  m_length = original.m_length;
  //current_nodeOrig a pointer represents the original linkedlist node we are at
  Node<T>* current_nodeOrig = original.m_front;
  if (current_nodeOrig == nullptr)
  {
    m_front = nullptr;
  }
  else
  {
    m_front = new Node<T>(current_nodeOrig->getValue());
    //current_nodeCopy a pointer represents the copy linkedlist node we are at
    Node<T>* current_nodeCopy = m_front;
    for (int i = 1; i < m_length; i++)
    {
      //moving the pointer on the next node in the original linked list
      current_nodeOrig =current_nodeOrig ->getNext();
      //creating a new node
      Node<T>* NextNodeCopy = new Node<T>(current_nodeOrig ->getValue());
      //linking the new node to the copy linked list
      current_nodeCopy->setNext(NextNodeCopy);
      //moving the pointer on the next node in the copy list
      current_nodeCopy = current_nodeCopy->getNext();
    }
    //setting the last pointer to null.
    current_nodeCopy->setNext(nullptr);
  }
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& original)
{
  if (this!= &original)
  {
    this->m_length = original.m_length;
    //current_nodeOrig a pointer represents the original linkedlist node we are at
    Node<T>* current_nodeOrig = original.m_front;
    if (current_nodeOrig == nullptr)
    {
      this->m_front = nullptr;
    }
    else
    {
      this->m_front = new Node<T>(current_nodeOrig->getValue());
      //current_nodeCopy a pointer represents the copy linkedlist node we are at
      Node<T>* current_nodeCopy = this->m_front;
      for (int i = 1; i < m_length; i++)
      {
        //moving the pointer on the next node in the original linked list
        current_nodeOrig =current_nodeOrig ->getNext();
        //creating a new node
        Node<T>* NextNodeCopy = new Node<T>(current_nodeOrig ->getValue());
        //linking the new node to the copy linked list
        current_nodeCopy->setNext(NextNodeCopy);
        //moving the pointer on the next node in the copy list
        current_nodeCopy = current_nodeCopy->getNext();
      }
      //setting the last pointer to null.
      current_nodeCopy->setNext(nullptr);
    }
  }
  return(*(this));
}

template <typename T>
LinkedList<T>::~LinkedList()
{
  clear();
  delete m_front;
}


template <typename T>
bool LinkedList <T>::isEmpty()const
{
  if (m_length==0)
  {
    return(true);
  }
  return (false);
}

template <typename T>
int LinkedList<T>::getLength()const
{
  return (m_length);
}

template <typename T>
void LinkedList<T>::insert(int position, T entry) 
{
  if (position >= 1 && position <= m_length+1)
  {
    if (isEmpty())
    {
      m_front = new Node <T> (entry);
    }
    else
    {
      Node<T>* temp = m_front;
      if (position == (m_length+1))
      {
        while(temp->getNext()!=nullptr)
        {
          temp=temp->getNext();
        }
        Node<T>* temp2 = new Node<T> (entry);
        temp -> setNext(temp2);
      }
      else if (position == 1)
      {
        Node<T>* temp2 = new Node <T>(entry);
        temp2 -> setNext(m_front);
        m_front = temp2;
      }
      else
      {
        for (int i = 1; i< (position-1); i++)
        {
            temp = temp ->getNext();
        }
          Node<T>* temp2 = new Node <T>(entry);
          temp2 -> setNext(temp->getNext());
          temp -> setNext(temp2);
      }
    }
    m_length ++;
  }
  else
  {
    throw (std::runtime_error ("Invalid Position Index given.\n"));
  }
}

template <typename T>
void LinkedList <T>::remove(int position) 
{
  if ((position >= 1) && (position <= m_length))
  {
    Node<T>* temp = m_front;
    Node <T>* temp2 = nullptr;
    if (position == (m_length))
    {
      for(int i = 1; i< (m_length-1);i++)
      {
        temp=temp->getNext();
      }
      delete temp -> getNext();
      temp->setNext(nullptr);
    }
    else if (position == 1)
    {
      temp = m_front ->getNext();
      delete m_front;
      m_front = temp;
    }
    else
    {
      for (int i = 1; i< (position-1); i++)
      {
        temp = temp ->getNext();
      }
      temp2 = temp ->getNext();
      temp->setNext(temp2->getNext());
      temp2->setNext(nullptr);
      delete temp2;
      temp2 = nullptr;
    }
    m_length --;
  }
  else
  {
    throw (std::runtime_error ("Invalid Position Index given.\n"));
  }
}

template <typename T>
void LinkedList<T>::clear()
{
  while(!isEmpty())
  {
    remove(m_length);
  }
}

template <typename T>
T* LinkedList<T>::getEntryptr(int position) const
{
  if (position >=1 && position<=m_length)
  {
    Node <T>* temp = m_front;
    for (int i = 1; i < (m_length); i++)
    {
      if (i == position)
      {
        return(temp -> getValueptr());
      }
      temp = temp -> getNext();
    }
    return(temp -> getValueptr());
  }
  else
  {
    throw (std::runtime_error ("Invalid Position Index given.\n"));
  }
}

template <typename T>
T LinkedList<T>::getEntry(int position) const 
{
  if (position >=1 && position<=m_length)
  {
    Node <T>* temp = m_front;
    for (int i = 1; i < (m_length); i++)
    {
      if (i == position)
      {
        return(temp -> getValue());
      }
      temp = temp -> getNext();
    }
    return(temp -> getValue());
  }
  else
  {
    throw (std::runtime_error ("Invalid Position Index given.\n"));
  }
}

template <typename T>
void LinkedList<T>::replace(int position, T newEntry)
{
  if (position >=1 && position <= m_length)
  {
    remove(position);
    insert(position,newEntry);
  }
  else
  {
    throw (std::runtime_error ("Invalid Position Index given.\n"));
  }
}
