/* -------------------------------------------------
 *
 * File Name: LinkedList.h
 * Author: Afnan Elhamshari
 * Description: Declaration of the LinkedList class
 * Date: 11/16/2022
 *
 ------------------------------------------------ */
#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "Node.h"
#include "ListInterface.h"
#include <stdexcept>

template <typename T>
class LinkedList: public ListInterface <T>
{
    private:
     Node<T>* m_front;
     int m_length;

   public:
     /*
     * @pre none
     * @post creates a LinkedList object
     */
     LinkedList();
     /*
     * @pre a LinkedList object
     * @post creates a copy of the LinkedList object
     * @param a LinkedList object passed by reference
     */
     LinkedList(const LinkedList<T>& original);
     /*
     * @pre an existing LinkedList object
     * @post calls the function clear and deletes the LinkedList object
     */
     virtual ~LinkedList();
     /*
     * @pre a LinkedList object
     * @post creates a copy of the LinkedList object
     * @param a LinkedList object passed by reference
     * @return returns a copy of the LinkedList object
     */
     LinkedList& operator=(const LinkedList<T>& original);
     /*
     * @pre a length member variable
     * @post checks if the list is empty or not
     * @return returns if the list is empty
     */
     bool isEmpty() const;
     /*
     * @pre a length member variable
     * @post The length of the list is returned
     * @return returns the length of the list
     */
     int getLength() const;
     /*
     * @pre The position is between 1 and the list's length+1
     * @post The entry is inserted at the given position
     * @param position:  1<= position <= length+1
     * @param entry: An entry to put in the list
     * @throw std::runtime_error if the position is invalid.
     */
     void insert(int position, T entry);
     /*
     * @pre The position is between 1 and the list's length
     * @post The entry at the given position is removed
     * @param position:  1<= position <= length
     * @throw std::runtime_error if the position is invalid.
     */
     void remove(int position);
     /*
     * @pre a constructor is created
     * @post all the nodes in the object are deleted.
     */
     void clear();
     /*
     * @pre The position is between 1 and the list's length
     * @post The entry at the given position is read and returned
     * @param position:  1<= position <= length
     * @throw std::runtime_error if the position is invalid.
     * @return returns a pointer to the value of the entry at position.
     */
     T* getEntryptr(int position) const;
     /*
     * @pre The position is between 1 and the list's length
     * @post The entry at the given position is read and returned
     * @param position:  1<= position <= length
     * @throw std::runtime_error if the position is invalid.
     * @return returns a copy value of the entry at position.
     */
     T getEntry(int position) const;
     /*
     * @pre The position is between 1 and the list's length
     * @post The entry at the given position is replaced with the new entry
     * @param position:  1<= position <= length
     * @param newEntry: A new entry to put in the list
     * @throw std::runtime_error if the position is invalid.
     */
     void replace(int position, T newEntry);
};
#include "LinkedList.cpp"
#endif
