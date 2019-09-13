#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class customer
{
	public:
	int accno;
	string name;
	float balance;
};
class transaction
{
	public:
		int accno;
		float amount;
		char typeot;
		
};
int main()
{
	customer cust[4];
	ofstream myfile,myfile2;
	string line;
  myfile.open ("customer.txt");
	cout<<"\n Enter the details";
	for(int i=0;i<4;++i)
	{
		cin>>cust[i].accno>>cust[i].name>>cust[i].balance;
	    	myfile<<cust[i].accno<<"\t"<<cust[i].name<<"\t"<<cust[i].balance<<"\n";	
	}
	myfile.close();
	
	ifstream myfile1,myfile3;
  myfile1.open ("customer.txt");
   while ( getline (myfile1,line) )
    {
      cout << line << '\n';
    }
    myfile1.close();
    //updation
   int acc,lline=0,p=0,c;
    float bal;
    char wd;
    cout<<"\n Enter the account number to be updated";
    cin>>acc;
    for(int i=0;i<4;++i)
    {
          if(cust[i].accno == acc)
		  {
		  	break;
		  }	
		  ++lline;
    }
    
    	c=(cust[lline].name).length();
    	cout<<c;
    	cout<<"\n Enter the amount and trac";
	 cin>>bal>>wd;
	 myfile2.open("transaction.txt");
	 myfile2<<acc<<"\t"<<bal<<"\t"<<wd<<"\n";
	 myfile2.close();
	 switch(wd)
	 {
	case 'w':cust[lline].balance=cust[lline].balance-bal;
	        break;
	case 'd':cust[lline].balance=cust[lline].balance+bal;        
	        break;
	 default: cout<<"\n invalid entry";       
     }
	// fstream myfile2;
	 myfile1.open ("customer.txt");
   while(p!=lline)
   {
   	getline(myfile1,line);
   	++p;
   }
   long pos = myfile1.tellg();
   pos=pos-2;
   myfile1.close();
   if(lline==0)
   pos=0;
	 
  if(lline == p)
  {
   //ifstream myfile2;
	 myfile.open ("customer.txt",std::ios_base::in);
	 myfile.seekp (0,ios::beg);
	 //long pos = myfile.tellp();	
	 cout<<"\n"<<pos;
   myfile.seekp ((pos+6+c));
	myfile<<cust[lline].balance;
	myfile.close();
}


string line1;
myfile1.open ("customer.txt");
//myfile1.seekg(0,ios::beg);
   while ( getline(myfile1,line) )
    {
      cout << line << '\n';
    }
    myfile1.close();

myfile3.open("transaction.txt");
 while ( getline(myfile3,line1) )
    {
      cout << line1 << '\n';
    }
    myfile3.close();
}

