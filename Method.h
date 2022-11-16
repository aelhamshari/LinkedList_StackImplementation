/* -------------------------------------------------
 *
 * File Name: Method.h
 * Author: Afnan Elhamshari
 * Description: Declaration of the Method class
 * Date: 11/16/2022
 *
 ------------------------------------------------ */
 #ifndef METHOD_H
#define METHOD_H
#include <string>
using namespace std;
class Method
{
private:
  bool Methodhandle;
  string Methodname;

public:
  /*
   * @pre None
   * @post Creates a Mehtod object
  */
  Method();
  /*
   * @pre Have a Handle Value
   * @param Handle is the handling capability read from the file
   * @post handle has the same value as Handle
  */
  void sethandle(bool Handle);
  /*
   * @pre None
   * @post None
   * @return Returns the value of handle
  */
  bool gethandle() const;
  /*
   * @pre Have a Methodname member variable
   * @param name is the method name read from the file
   * @post Methodname has the same value as name
  */
  void setMethodname(string name);
  /*
   * @pre None
   * @post None
   * @return Returns the value of Methodname
  */
  string getMethodname() const;
};
#endif
