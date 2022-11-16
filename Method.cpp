/* -------------------------------------------------
 *
 * File Name: Method.cpp
 * Author: Afnan Elhamshari
 * Description: Implementation of the Method class
 * Date: 11/16/2022
 *
 ------------------------------------------------ */
#include "Method.h"

Method::Method()
{
  Methodhandle = false;
  Methodname = " ";
}

void Method::sethandle(bool Handle)
{
  Methodhandle = Handle;
}

bool Method::gethandle() const
{
  return (Methodhandle);
}

void Method::setMethodname(string name)
{
    Methodname = name;
}

string Method::getMethodname() const
{
  return(Methodname);
}
