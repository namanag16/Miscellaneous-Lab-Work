/* ****************************************************************************
see vectors, map & stack, sets
given an array of INTS, find all the duplicate elements of the array.
*******************************************************************************/

#include <iostream>
#include <set>
using namespace std;


int main()
{
    int x;
    set<int> my_list;
    set<int> dup;
    set<int>::iterator i,j;
    char ch;
    bool flag = true;
    while(flag == true)
    {
        cout << "enter a value: ";
        cin >> x;
        if(!my_list.empty())
        {
            i = my_list.find(x);
            if(i != my_list.end())
            {
                dup.insert(x);
            }
        }
        my_list.insert(x);
        cout << "insert another value? (Y,N) ";
        cin >> ch;
        if(ch != 'Y') //|| ch != 'y')
            flag = false;
    }
//
//    for(i=my_list.begin();i!=my_list.end();i++)
//    {
//        for(j=i+;j!=my_list.end();j++)
//        {
//            if(*j == *i)
//            {
//                cout << "inside equal" << endl;
//                dup.insert(*j);
//            }
//        }
//    }
//
//

    for(i=dup.begin();i!=dup.end();i++)
    {
        cout << "" << *i << "  ";
    }
}
