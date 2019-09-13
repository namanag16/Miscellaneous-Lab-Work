#include <iostream>
#include <stdio.h>

using namespace std;
struct complex{
                    int real;
                    int img;
                };

namespace ops{	

    void c_add(struct complex c1,struct complex c2,struct complex *c3)
    {
        (*c3).real = c1.real + c2.real;
        (*c3).img = c1.img + c2.img;

    }
    void c_mul(struct complex c1,struct complex c2,struct complex *c3)
    {
        c3->real = (c1.real*c2.real) - (c1.img * c2.img);
        c3->img = (c1.img*c2.real) + (c1.real * c2.img);
    }
    void c_div(struct complex c1,struct complex c2,struct complex *c3)
    {
        int x = c2.real * c2.real + c2.img * c2.img;
        c2.img = - c2.img;
        ops::c_mul(c1,c2,c3);
        
/*        cout << "number received is" << endl;
        cout << c3->real << "+ i " << c3->img;
        cout << endl;
        cout << x << endl; */
        
        printf("(%d/%d) + i (%d/%d)",c3->real,x,c3->img,x);
      
    }


}
int main()
{
    struct complex c1;
    struct complex c2;
    struct complex c3;
    label:
    cout << "enter real and img parts of first complex number: ";
    cin >> c1.real;
    cin >> c1.img;
    cout << "enter real and img parts of second complex number: ";
    cin >> c2.real;
    cin >> c2.img;
    
    int opt;
    cout << "Enter operation: \n1.Add\n2.Mul\n3.Div\n";
    cin >> opt;
    switch(opt)
    {
        case 1: ops::c_add(c1,c2,&c3);
                break;
        case 2: ops::c_mul(c1,c2,&c3);
                break;
        case 3: ops::c_div(c1,c2,&c3);
                break;
        default: cout << "wrong option";
    }
    
    if(opt !=3)
		cout << c3.real << " + i " << c3.img;
    cout << endl;
    char ch;
    cout << "wanna repeat (Y/N)";
    cin >> ch;
    if(ch =='y' || ch=='Y')
		goto label;
	
    


}
