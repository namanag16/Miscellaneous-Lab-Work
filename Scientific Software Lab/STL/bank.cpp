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
	customer cust[5];
	ofstream myfile,myfile2;
	string line;
  myfile.open ("customer.txt");
	cout<<"\n Enter the details";
	for(int i=0;i<5;++i)
	{
		cin>>cust[i].accno>>cust[i].name>>cust[i].balance;
	    	myfile<<cust[i].accno<<" "<<cust[i].name<<" "<<cust[i].balance<<"\n";	
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
    char ch='y';
    char x;
    while(ch=='y'||ch=='Y')
{   
    cout<<"\n Enter the account number to be updated";
    cin>>acc;
    for(int i=0;i<5;++i)
    {
          if(cust[i].accno == acc)
		  {
		  	break;
		  }	
		  ++lline;
    }
    	c=(cust[lline].name).length();
    


cout<<"\n press n to update name and b to update balance \n";   
cin>>x;
switch(x){
     
  case 'b':{  	cout<<"\n Enter the amount";
	 cin>>bal;
        cout<<"\n Enter w if u want to withdraw and d in case u want to deposit";
        cin>>wd;
	 myfile2.open("transaction.txt");
	 myfile2<<acc<<" "<<bal<<" "<<wd<<"\n";
	 myfile2.close();
	 switch(wd)
	 {
	case 'w':cust[lline].balance=(cust[lline].balance)-bal;
	        break;
	case 'd':cust[lline].balance=(cust[lline].balance)+bal;        
	        break;
	 default: cout<<"\n invalid entry";       
     }
	// fstream myfile2;
	 myfile1.open ("customer.txt",ios::binary);
   while(p!=lline)
   {
   	getline(myfile1,line);
   	++p;
   }
   long pos = myfile1.tellg();
   cout<<"\n main pos:"<<pos;
   pos=pos-2;
   myfile1.close();
   if(lline==0)
   pos=0;
	 
  if(lline == p)
  {
   //ifstream myfile2;
	 myfile.open ("customer.txt",std::ios_base::in);
	 //myfile.seekp (0,ios::beg);
	 //long pos = myfile.tellp();	
	 cout<<"\n pos:"<<pos;
   myfile.seekp ((pos+6+c));
	myfile<<(cust[lline].balance);
	myfile.close();
}}
break;


case 'n':{ string s;
cout<<"enter name";
cin>>s;
myfile1.open ("customer.txt",ios::binary);
   while(p!=lline)
   {
   	getline(myfile1,line);
   	++p;
   }
   long pos = myfile1.tellg();
   //pos=pos-2;
   myfile1.close();
   /*if(lline==0)
   pos=0;
   if(lline==19)
   pos=pos+2-1;*/
	 
  if(lline == p)
  {
   //ifstream myfile2;
	 myfile.open ("customer.txt",std::ios_base::in);
	 myfile.seekp (0,ios::beg);
	 //long pos = myfile.tellp();	
	 cout<<"\n"<<pos;
   myfile.seekp ((pos+5));
	myfile<<s;
	myfile.close();

}}
break;}
p=0;lline=0;
cout<<"\n do u wanna further update";
cin>>ch;
}


string line1;
myfile1.open ("customer.txt");
//myfile1.seekg(0,ios::beg);
   while ( getline(myfile1,line) )
    {
      cout << line << '\n';
    }
    myfile1.close();
/*
myfile3.open("transaction.txt");
 while ( getline(myfile3,line1) )
    {
      cout << line1 << '\n';
    }
    myfile3.close(); */
return 0;
}

