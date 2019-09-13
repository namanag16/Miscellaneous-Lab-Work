/* ****************************************************************************
see vectors, map & stack, sets

Given N travel tickets(src - dest)
Arrange the tickets in a order sucht that it forms a valid travel route. (Assume that input is given such that
a unique route exits)
*******************************************************************************/
#include <iostream>
#include <map>
#include <set>

using namespace std;


int main()
{
    map<string, string> first;
    map<string, string>::iterator firsti;
    map<string, int> second;
    map<string, int>::iterator i,j;
    set<string> sd;
    set<string>::iterator sdi;
    char ch;
    bool flag = true;
    string x,y;
    while(flag == true)
    {
        cout << "enter source and destination: " ;
        cin >> x >> y;
        first.insert(pair<string,string>(x,y));

        if(!second.empty())
        {
            // search for source
            i = second.find(x);
            if(i != second.end())
            {
                // update the value
                i->second +=1;
            }
            else
            {
                second.insert(pair<string,int>(x,1));
            }
            // search for destination
            j = second.find(y);
            if(j != second.end())
            {
                // update the value
                j->second +=1;
            }
            else
            {
                second.insert(pair<string,int>(y,1));
            }
        }
        else
        {
            second.insert(pair<string,int>(x,1));
            second.insert(pair<string,int>(y,1));
        }
        cout << "insert another value? (Y,N) ";
        cin >> ch;
        if(ch != 'Y') //|| ch != 'y')
            flag = false;
    }

    for(i = second.begin();i!=second.end();i++)
    {
        if(i->second == 1)
        {
            sd.insert(i->first);
        }
    }

//    if(sd.count()!= 2)
  //  {
    //    cout << "some error.. returning";
    //    return;
    //}

    sdi = sd.begin();
    cout << *sdi << endl;
  loop:

    firsti= first.find(*sdi);
    if(firsti == first.end())
    {
        sdi++;
           goto loop;
    }

    // PRINT the values
    int countz = 1;
    cout << "before the loop";
    for(;firsti!=first.end();)
    {
        //cout << "m coming here ";
        if(countz == 1)
        {
        cout << firsti->first << "  " << firsti->second;
        firsti = first.find(firsti->second);
        countz ++;
        }
        else
        {
        cout << "  " << firsti->second;
        firsti = first.find(firsti->second);
        }
    }

}
