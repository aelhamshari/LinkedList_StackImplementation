/* -------------------------------------------------
 *
 * File Name: Process.cpp
 * Author: Afnan Elhamshari
 * Description: Implementation of the Process class
 * Date: 11/16/2022
 *
 ------------------------------------------------ */
#include "Process.h"
#include <iostream>
using namespace std;
Process::Process()
{
  process_name = "\0";
}

Process::Process(string input)
{
  process_name = input;
}


Process::Process(const Process& original)
{
  process_name = original.getprocess_name();
  if (!(original.process_stack.isEmpty()))
  {
    process_stack = original.process_stack;
  }
}

Process& Process::operator=(const Process& original)
{
  this->process_name = original.process_name;
  if (!(original.process_stack.isEmpty()))
  {
    this->process_stack = original.process_stack;
  }
  return((*this));
}

Process::~Process()
{
  while(!(process_stack.isEmpty()))
  {
    process_stack.pop();
  }
}

void Process::setprocess_name(string input)
{
  process_name = input;
}

string Process::getprocess_name() const
{
  return (process_name);
}

void Process::SetFunction(string input, bool handle)
{
  Method newmethod;
  newmethod.setMethodname(input);
  newmethod.sethandle(handle);
  try
  {
    process_stack.push(newmethod);
  }
  catch (std::runtime_error& e)
  {
    e.what();
  }
}

string Process::viewtop() const
{
  try
  {
    Method a = process_stack.peek();
    return(a.getMethodname());
  }
  catch (std::runtime_error& e)
  {
    cout <<e.what();
  }
  return("Stack is Empty");
}


void Process::handle()
{
  for (int i= 1; i<=process_stack.getstackLength(); i++)
  {
    if (process_stack.peek().gethandle())
    {
      break;
    }
    else
    {
      try
      {
        process_stack.pop();
      }
      catch (std::runtime_error& e)
      {
        cout <<e.what();
      }
    }
  }
}
