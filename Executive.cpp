/* -------------------------------------------------
 *
 * File Name: Executive.cpp
 * Author: Afnan Elhamshari
 * Description: Implementation of the Executive class, calls all the functions and other classes
 * Date: 11/16/2022
 *
 ------------------------------------------------ */
#include "Executive.h"
#include <iostream>
using namespace std;


Executive::Executive(string filename)
{
  inFile.open(filename);
}

Executive::~Executive()
{
  processlist.clear();
}


void Executive::START(string r)
{
  Process newprocess(r);
  try
  {
    processlist.insert(processlist.getLength()+1, newprocess);
    processlist.getEntryptr(processlist.getLength())->SetFunction("main", true);
  }
  catch (std::runtime_error& e)
  {
    cout << e.what();
  }
}

void Executive::CALL(string r)
{
  string function;
  char choice;
  bool canhandle= false;
  for (int i=1; i<=processlist.getLength(); i++)
  {
    if (processlist.getEntry(i).getprocess_name()==r)
    {
        inFile >> function;
        inFile >> choice;
        if (choice == 'y')
        {
          canhandle = true;
        }
        else if (choice == 'n')
        {
          canhandle = false;
        }
        processlist.getEntryptr(i)->SetFunction(function, canhandle);
    }
  }
}

void Executive::THROW(string r)
{
  for (int i = 1; i<= processlist.getLength(); i++)
  {
    if (processlist.getEntryptr(i)->getprocess_name()==r)
    {
      processlist.getEntryptr(i)->handle();
    }
  }
}

void Executive::RETURN(string r)
{
  for (int i=1; i<=processlist.getLength(); i++)
  {
    if (processlist.getEntryptr(i)->getprocess_name()==r)
    {
      cout << processlist.getEntryptr(i)->getprocess_name();
      cout << " [" << processlist.getEntryptr(i)->viewtop() << "]\n";
    }
  }
}

void Executive::PRINT()
{
  cout << "\nHere are all the processes names and their current running functions!\n";
      cout << "===============\n";
      for (int i=1; i<=processlist.getLength(); i++)
      {
        cout << processlist.getEntryptr(i)->getprocess_name();
        cout << " [" << processlist.getEntryptr(i)->viewtop() << "]\n";
      }
      cout << "===============\n";
}

void Executive::run()
{
  string read;
  inFile >> read;
  while(!(inFile.eof()))
  {
    if (read == "START")
    {
      inFile >> read;
      START(read);
    }
    else if (read == "CALL")
    {
      inFile >> read;
      CALL(read);
    }
    else if (read == "THROW")
    {
      inFile >> read;
      THROW(read);
    }
    else if (read == "RETURN")
    {
      inFile >> read;
      RETURN(read);
    }
    else if (read == "PRINT")
    {
      PRINT();
    }
    else
    {
      cout << "Command " << read << " not found!\n";
      getline (inFile, read, '\n');
    }
    inFile >> read;
  }
}
