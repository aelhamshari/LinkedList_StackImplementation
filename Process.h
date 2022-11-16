/* -------------------------------------------------
 *
 * File Name: Process.h
 * Author: Afnan Elhamshari
 * Description: Declaration of the Process class
 * Date: 11/16/2022
 *
 ------------------------------------------------ */
#ifndef PROCESS_H
#define PROCESS_H
#include "Stack.h"
#include "Method.h"
#include <string>
using namespace std;

class Process
{
  private:
    Stack<Method> process_stack;
    string process_name;
  public:
    /*
    * @pre none
    * @post creates a Process object
    */
    Process();
    /*
    * @pre none
    * @post creates a Process object
    * @param input is the name of the process read from a file
    */
    Process(string input);
    /*
    * @pre a Process object
    * @post creates a copy of the Process object
    * @param a Process object passed by reference
    */
    Process(const Process& original);
    /*
    * @pre a Process object
    * @post creates a copy overload of the process object
    * @param a process object passed by reference
    * @return returns a copy of the process object
    */
    Process& operator=(const Process& original);
    /*
    * @pre an existing Process object
    * @post destructs the Process object
    */
    ~Process();
    /*
     * @pre Have an input Value
     * @param input is the name of the Process read from the file
     * @post process_name has the same value as input
    */
    void setprocess_name(string input);
    /*
     * @pre None
     * @post None
     * @return Returns process_name
    */
    string getprocess_name() const;
    /*
     * @pre Have an input value, handle value
     * @param input is the name of the method read from the file
     * @param handle is the handling capability read from the file
     * @post Method name and andling capability are assigned
    */
    void SetFunction(string input, bool handle);
    /*
    * @pre a method is existing on the stack
    * @post all the methods that can't handle exceptions are poped from the stack
    */
    void handle();
    /*
     * @pre A stack exists
     * @post None
     * @return Returns the value of the Method on top of the stack
    */
    string viewtop() const;
};
#endif
