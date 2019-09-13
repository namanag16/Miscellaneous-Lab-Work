/***************************************************************************
This program shows takes k sorted lists and merges them to one sorted list.
****************************************************************************/
#include<iostream>
#include<queue>
#include<list>
using namespace std;
class myEleCmp{
    public: bool operator()(const list<int> lhs,const list<int> rhs){
        return lhs.front()>rhs.front();
    }
};
int main(){
    list<int> finalList;
    priority_queue<list<int>,vector<list<int> >,myEleCmp> myHeap;
    int noList;
    cout<<"Enter no of lists ";
    cin>>noList;
    list<int> kLists[20];
    for(int i=0;i<noList;i++){
        cout<<"Enter number of elements in list "<<i;
        int noEle;
        cin>>noEle;
        cout<<"Enter sorted list";
        for(int j=0;j<noEle;j++){
            int ele;
            cin>>ele;
            kLists[i].push_back(ele);
        }
        myHeap.push(kLists[i]);
    }

    //cout<<myHeap.size();
    //cout<<myHeap.top().front();
    cout<<"\nAns:\n";
    while(myHeap.size()!=0){
            list<int> item=myHeap.top();
            myHeap.pop();
            finalList.push_back(
            item.front());
            //cout<<item.front()<<" ";
            item.pop_front();
            if(item.size()>0)
                myHeap.push(item);
    }
    list<int>::iterator it;
    for(it=finalList.begin();it!=finalList.end();it++)
        cout<<(*it)<<" ";
}
