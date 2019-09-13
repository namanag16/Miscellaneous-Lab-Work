#include <iostream>
#include <fstream>

using namespace std;
/*
int main()
{
	ofstream fp("detail_today.txt");
	char ch[20];
	for(int i = 0;i<10;i++)
	{
		fp << i << endl;
	}
	fp.close();
	ifstream fin("detail_today.txt");
	fin.read(ch,20);
	
	for(int i=0;i<20;i++)
		cout << ch[i];
		
	fin.close();
}


*/

struct emp
{
	char name[30];
	int empID;
	int salary;
};
void viewEmp();
void updateEmp();
int main()
{
	emp e1;
	/*
	ofstream fout("details_today.txt",ios::app);
	
	
	cout << "Enter name: ";
    //cin.ignore();
    cin.getline(e1.name,30);
    
    cout << "Enter empID, salary: ";
    cin >> e1.empID >> e1.salary ;
    
    fout.write((char*)&e1,sizeof(e1));
    fout.close();
    */
    
    ifstream fin("details_today.txt");
    emp e;
    cout << "\nempID" << "\t" << "name"<< "\t" << "salary";
    while(fin.read( (char *)&e, sizeof(e) )){
        cout<< "\n" << e.empID << "\t" << e.name << "\t" << e.salary;
    }
    fin.close();
    
    //viewEmp();
    updateEmp();
}

void viewEmp()
{
	int pos;
	ifstream fin("details_today.txt");
	
	cout << endl << "Enter record position: ";
	cin >> pos;
	
	pos = (pos-1) * sizeof(emp);
	cout << endl << endl;
	fin.seekg(pos);
    emp e;
    cout << "\nempID" << "\t" << "name"<< "\t" << "salary";
    
    fin.read( (char *)&e, sizeof(e) );
		//if(e.empID == id)
        cout<< "\n" << e.empID << "\t" << e.name << "\t" << e.salary;
    fin.close();
}

void updateEmp()
{
	int pos;
	emp e1;
	cout << endl << "Enter record position to modify: ";
	cin >> pos;
	pos = (pos-1) * sizeof(emp);
	cout << endl << endl;
	
	fstream fout("details_today.txt");
	cout << "Enter name: ";
    cin.ignore();
    cin.getline(e1.name,30);
    cout << "Enter empID, salary: ";
    cin >> e1.empID >> e1.salary ;
    fout.seekp(pos);
    fout.write((char*)&e1,sizeof(e1));
    fout.close();
    //viewEmp();
    
}
