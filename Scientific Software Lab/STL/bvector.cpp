#include<vector>
#include<iostream>
using namespace std;

void display(vector<int> &v)
{
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
cout<<"\n";

}

int main()
{
vector<int> v;
cout<<"\nInitial size ="<<v.size()<<"\n";
int x,n;
cout<<"\n Enter number of values :";
cin>>n;
for(int i=0;i<n;i++)
{
	cin>>x;
	v.push_back(x);
}
cout<<"\n Size of vector now :"<<v.size();
cout<<"\n Display contents";
display(v);
v.push_back(6.6);
cout<<"\nsize ="<<v.size();
cout<<"\ncontents :";
display(v);
vector<int> :: iterator itr=v.begin();
itr=itr+3;
//cout<<"\nNUmber :"<<v[itr];
v.insert(itr,9);
cout<<"\nAfter insertion :";
display(v);
cout<<"\n After erasing";
v.erase(v.begin()+1,v.begin()+3);
display(v);
cout<<"**********"<<v.at(1);



return 0;}
