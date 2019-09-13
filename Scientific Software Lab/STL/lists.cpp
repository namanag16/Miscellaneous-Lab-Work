// An example using STL list. 
// This program pushes 4 integer values to an STL list.
// It then prints out each of these 4 values before
// deleting them from the list
#include <iostream>
#include <list>		// list class library
using namespace std;
  
int main()  
{  
  // Now create a "list" object, specifying its content as "int".
  // The "list" class does not have the same "random access" capability
  // as the "vector" class, but it is possible to add elements at
  // the end of the list and take them off the front.
  list<int> list1;

  // Add some values at the end of the list, which is initially empty.
  // The member function "push_back" adds at item at the end of the list.
  int value1 = 10;
  int value2 = -3;
  list1.push_back (value1);
  list1.push_back (value2);
  list1.push_back (5);
  list1.push_back (1);

  // Output the list values, by repeatedly getting the item from
  // the "front" of the list, outputting it, and removing it
  // from the front of the list.
  cout << endl << "List values:" << endl;
  // Loop as long as there are still elements in the list.
  list<int>::iterator it
  for(it=list1.begin();it!=list1.end();it++)
  cout<<" " << *it;
 
  return(0); 
}  

