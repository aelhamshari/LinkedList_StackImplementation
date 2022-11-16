/* -------------------------------------------------
 *
 * File Name: Executive.h
 * Author: Afnan Elhamshari
 * Description: Declaration of the Executive class
 * Date: 11/16/2022
 *
 ------------------------------------------------ */
#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include "Process.h"
#include <fstream>
#include <iostream>
using namespace std;

class Executive
{
  private:
    LinkedList<Process> processlist;
    ifstream inFile;
  public:
    /*
    * @pre arguments are imported from main
    * @param the argumnets passed during runtime
    * @post creates an Executive object
    */
    Executive(string filename);
    /*
    * @pre an existing Executive object
    * @post deletes the Executive object
    */
    ~Executive();
    /*
    * @pre a constructor is created
    * @post runs the program
    */
    void run();

    void START(string r);
    void CALL(string r);
    void THROW(string r);
    void RETURN(string r);
    void PRINT();
};
#endif
