#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ofstream fp("detail_today.txt");
	char ch[20];
	cout << "enter name: " ;
	cin >> ch;
	fp << ch;
	fp.close();
	
	ifstream fin("detail_today.txt");
	fin.read(ch,20);
	
	for(int i=0;i<20;i++)
		cout << ch[i];
		
	fin.close();
	
	
}
