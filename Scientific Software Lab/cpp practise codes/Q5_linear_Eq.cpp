#include <iostream>

using namespace std;

int determinant(int,int,int,int,int,int,int,int,int);
int determinant_two(int,int,int,int);

int main()
{
	int a,b,c,d,e,f,g,h,i,t1,t2,t3;
	cout << "System of equations will be of the form: \nax+by+cz=t1\ndx+ey+fz=t2\ngx+hy+iz=t3" << endl;
	cout << "x,y,z are variables. Rest are coefficients " << endl;
	a=9; b=-2; c = 3; t1 = 8;
	d=4; e = 3; f = 6; t2 = -3; 
	g=7 ; h =6 ; i =12 ; t3 =-6 ;
	//cout << "Enter the values in order " << endl;
	//cin >> a >> b >> c >> t1 >> d >> e >> f >> t2 >> g >> h >> i >> t3;
	
	int det,detx,dety,detz;
	det = determinant(a,b,c,d,e,f,g,h,i);
	detx = determinant(t1,b,c,t2,e,f,t3,h,i);
	dety = determinant(a,t1,c,d,t2,f,g,t3,i);
	detz = determinant(a,b,t1,d,e,t2,g,h,t3);
	
	if(det != 0)
	{
		cout << "system of equations is consistent" << endl;
		cout << "x=" << (float)(detx)/det << endl;
		cout << "y=" << (float)(dety)/det << endl;
		cout << "z=" << (float)(detz)/det << endl;
		
	}
	else if (det == 0 && (detx !=0 || dety !=0 || detz !=0))
		cout << "No solutions exist\n" ;
	else if(det == 0 && detx == 0 && dety == 0 && detz == 0)
	{
		t1 = t1 - a;
        t2 = t2 - d;
        t3 = t3 - g;
        
        cout << "The system has infinite solutions\n";
        cout << "we will find one of the possible solutions by finding rank" << endl;
        float x = determinant_two(b,c,e,f);
        float y = determinant_two(b,c,h,i);
        float z = determinant_two(e,f,h,i);
        
        if(x !=0)
		{	cout << "x=1 \n";
			cout << "y=" << determinant_two(t1,c,t2,f)/x << endl;
			cout << "z=" << determinant_two(b,t1,c,t2)/x << endl;		
		}
		else if ( y != 0)
		{	cout << "x=1 \n";
			cout << "y=" << determinant_two(t1,c,t3,i)/x << endl;
			cout << "z=" << determinant_two(b,t1,h,t3)/x << endl;	
		}
		else if ( z !=0)
		{	cout << "x=1 \n";
			cout << "y=" << determinant_two(t2,f,t3,i)/x << endl;
			cout << "z=" << determinant_two(e,t2,h,t3)/x << endl;	
		}
	}
		
}


int determinant(int a,int b,int c,int d,int e,int f,int g,int h,int i)
{
	return a*(e*i - h*f) - b*(d*i - f*g) + c*(d*h -g*e) ;
}

int determinant_two(int a, int b , int c , int d)
{
    return a*d - b*c ;
}





