// constructing vectors
#include <iostream>
#include <vector>
#include<conio.h>
using namespace std;
int main ()
{
  vector<int>::iterator it;
  // constructors used in the same order as described above:
  vector<int> first;                                // empty vector of ints
  vector<int> second (4,100);                       // four ints with value 100
  vector<int> third (second.begin(),second.end());  // iterating through second
  vector<int> fourth (third);                       // a copy of third

  // the iterator constructor can also be used to construct from arrays:
  int myints[] = {16,2,77,29};
  vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
  cout << "The contents of first are: \n";
  for(it=first.begin();it!=first.end();++it)
 cout<<*it;
 cout << "\n The contents of secong are: \n";
  for(it=second.begin();it!=second.end();++it)
 cout<<*it;
 cout << "\n The contents of third are: \n";
  for(it=third.begin();it!=third.end();it++)
 cout<<*it;
 cout << "\n The contents of fourth are: \n";
  for(it=fourth.begin();it!=fourth.end();it++)
 cout<<*it;
  cout << "\n The contents of fifth are:";
  for ( it = fifth.begin(); it != fifth.end(); ++it)
   cout << ' ' << *it;
  cout << '\n';
 getch();
  return 0;
}
