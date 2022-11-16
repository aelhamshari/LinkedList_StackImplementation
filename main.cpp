/* -------------------------------------------------
 *
 * File Name: main.cpp
 * Author: Afnan Elhamshari
 * Description: Implementation of main, passes in the arguments to start the program
 * Date: 11/16/2022
 *
 ------------------------------------------------ */
#include "Executive.h"
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
  if (argc < 2)
  {
    cout << "Invalid Number of inputs. Terminating the Program.\n";
  }
  else
  {
    Executive exec(argv[1]);
    exec.run();
  }
  return 0;
}
