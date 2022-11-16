/* -------------------------------------------------
 *
 * File Name: StackInterface.h
 * Author: Afnan Elhamshari
 * Description: Declaration of the StackInterface
 * Date: 11/16/2022
 *
 ------------------------------------------------ */
#ifndef STACK_INTERFACE_H
#define STACK_INTERFACE_H

#include <stdexcept>

template <typename T>
class StackInterface
{
     public:
     /*
     * @post All memory allocated by the implementing class should be freed.
     *       This, as with all virtual destrucors, is an empty definition since we
     *       have no knowledge of specific implementation details.
     */
     virtual ~StackInterface(){}
     /*
     * @pre a stack is constructed and have at least one value on it
     * @post The value of the top of the stack is returned
     * @throw std::runtime_error if the stack is empty
     */
     virtual T peek() const=0;
     /*
     * @pre a stack is constructed and have at least one value on it
     * @post the top of the stack is removed
     * @throw std::runtime_error if the stack is empty
     */
     virtual void pop()=0;
     /*
     * @pre The position is length+1
     * @post The entry is inserted at the given position
     * @param entry: An entry to put in the stack
     * @throw std::runtime_error if the position is invalid.
     */
     virtual void push(T entry)=0;
     /*
     * @pre none
     * @post checks if the list is empty or not
     * @return returns if the list is empty
     */
     virtual bool isEmpty() const = 0;
};
#endif
