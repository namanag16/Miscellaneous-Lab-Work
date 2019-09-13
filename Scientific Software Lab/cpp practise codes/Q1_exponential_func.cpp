#include <iostream>
#include <stdlib.h>
using namespace std;

int power(int,int);
int main()
{
    int x,n;
    cout << "enter x: ";
    cin >> x;
    float curr;
    float sum =1,prev = 1;
    float err;
    do
    {
        n=1;
        if(n%2 != 0)
            curr = (- power(x,n))/n;
        else
            curr = (power(x,n))/n;
        sum = sum + curr;
        err = abs(sum - prev);
        prev = sum;
        n++;
    }while(err > .00001);

    cout << "\nthe value for exp(-"  << x << ") is " << sum;
}

int power(int x,int n)
{
    if(n==1)
        return x;
    if(n%2==0)
        return power(x,n/2)*power(x,n/2);
    else
        return power(x,n/2)*power(x,n/2)*x;
}

