/* -------------------------------------------------
 *
 * File Name: ListInterface.h
 * Author: Afnan Elhamshari
 * Assignment: EECS-268 Lab04
 * Description: Declaration of the ListInterface
 * Date: 02/26/2018
 *
 ------------------------------------------------ */
#ifndef LIST_INTERFACE_H
#define LIST_INTERFACE_H
#include <stdexcept>

template <typename T>
class ListInterface
{
     public:
     /**
     * @post All memory allocated by the implementing class should be freed.
     *       This, as with all virtual destrucors, is an empty definition since we
     *       have no knowledge of specific implementation details.
     */
     virtual ~ListInterface(){}
     /*
     * @pre a length member variable
     * @post checks if the list is empty or not
     * @return returns if the list is empty
     */
     virtual bool isEmpty() const = 0;
     /*
     * @pre a length member variable
     * @post The length of the list is returned
     * @return returns the length of the list
     */
     virtual int getLength() const = 0;
     /*
     * @pre The position is between 1 and the list's length+1
     * @post The entry is inserted at the given position
     * @param position:  1<= position <= length+1
     * @param entry: An entry to put in the list
     * @throw std::runtime_error if the position is invalid.
     */
     virtual void insert(int position, T entry) = 0;
     /*
     * @pre The position is between 1 and the list's length
     * @post The entry at the given position is removed
     * @param position:  1<= position <= length
     * @throw std::runtime_error if the position is invalid.
     */
     virtual void remove(int position) = 0;
     /*
     * @pre a constructor is created
     * @post all the nodes in the object are deleted.
     */
     virtual void clear() = 0;
     /*
     * @pre The position is between 1 and the list's length
     * @post The entry at the given position is read and returned
     * @param position:  1<= position <= length
     * @throw std::runtime_error if the position is invalid.
     * @return returns a pointer to the value of the entry at position.
     */
     virtual T* getEntryptr(int position) const = 0;
     /*
     * @pre The position is between 1 and the list's length
     * @post The entry at the given position is read and returned
     * @param position:  1<= position <= length
     * @throw std::runtime_error if the position is invalid.
     * @return returns the value of the entry at position.
     */
     virtual T getEntry(int position) const = 0;
     /*
     * @pre The position is between 1 and the list's length
     * @post The entry at the given position is replaced with the new entry
     * @param position:  1<= position <= length
     * @param newEntry: A new entry to put in the list
     * @throw std::runtime_error if the position is invalid.
     */
     virtual void replace(int position, T newEntry) = 0;
};
#endif
