#include<iostream>
#include<cstdio>
using namespace std;
class A{
    private: int roll;
    public: friend void printRoll( A a);
    void virtual getRoll(){
        cin>>roll;
    }
};
class B:public A{
public:
        void getRoll(){
            A::getRoll();
        }
};
void printRoll(A a){
    cout<<a.roll;
}
int main(){
    A a;
    a.getRoll();
    printRoll(a);
    cout<<"Enter B roll";
    B b;
    b.getRoll();
}
