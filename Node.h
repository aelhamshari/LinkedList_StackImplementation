/* -------------------------------------------------
 *
 * File Name: Node.h
 * Author: Afnan Elhamshari
 * Description: Declaration of the Node class
 * Date: 11/16/2022
 *
 ------------------------------------------------ */
 #ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{
  private:
    T m_value;
    Node<T>* m_next;

  public:
    /*
     * @pre None
     * @post Creates a Node object
    */
    Node();
    /*
     * @pre None
     * @post destructs Node objects
    */
    ~Node(){}
    /*
     * @pre Have a node object
     * @param original is a node object passed by reference
     * @post Creates a copy of the passed Node object
    */
    Node (const Node& original);
    /*
     * @pre Have an Entry Value
     * @param value taken from the user
     * @post Creates a Node object that houses value
    */
    Node (T value);
    /*
     * @pre Have an Entry Value, and a next node
     * @param value taken from the user
     * @param next Node is assigned
     * @post Creates a Node object that houses value, and assigns next to m_next
    */
    Node (const T& value, Node<T>* next);
    /*
     * @pre Have an Entry Value
     * @param takes value from user
     * @post node value is entry
    */
    void setValue(const T& entry);
    /*
     * @pre None
     * @post None
     * @return Returns a pointer to a value at the node
    */
    T* getValueptr();
    /*
     * @pre None
     * @post None
     * @return Returns the value at the node
    */
    T getValue()const;
    /*
     * @pre None
     * @post None
     * @return Returns a pointer to a node
    */
    Node<T>* getNext()const;
    /*
     * @pre Have a node entry
     * @param an adjacent node
     * @post next node is equal to next
    */
    void setNext(Node<T>* next);
};
#include "Node.cpp"
#endif
