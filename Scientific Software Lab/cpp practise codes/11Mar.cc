/***************************************************************
The following code merges 3 sorted lists into one sorted list
using a heap

***************************************************************/


#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;
class Compare
{
    public:
    bool operator() (map<int,short> t, map<int,short> x)
    {
        map<int,short>::iterator i,p;
        i = t.begin();
        p = x.begin();
        if(i->first >= p->first)
        {
            return true;
        }
    }
};




int main()
{
    int no=3;
    char el;
    map<int,short> my_map[3];
    map<int,short>::iterator ii;


    //my_map ar[10];
    //vector<map<int,short>> vecOfMaps;

//    cout << "how many lists(max 10) ";
//    cin >> no;
    for(short ip = 0 ; ip< no ;ip++)
    {
        cout << "enter the list " << ip+1 << endl;
        short element = 0;
        int x;
        do
        {
            cout << "enter element " << element << ": ";
            cin >> x;
            my_map[ip].insert(pair<int,short>(x,ip));


            cout << "insert another element(y/n) ";
            cin >> el;
            element ++;
        }while(el == 'y');
    }


    for(short i=0;i<no;i++)
    {
        for(ii=my_map[i].begin();ii!=my_map[i].end();ii++)
        {
            cout << ii->first << "  " << ii->second << endl;
        }
        cout << endl << endl;
    }

    priority_queue<map<int,short>, vector<map<int,short> >, Compare> heap;

    heap.push(my_map[0]));
    heap.push(my_map[1]);
    heap.push(my_map[2]);


}
