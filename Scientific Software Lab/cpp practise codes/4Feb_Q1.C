//virtual functions
//friend functions
//overloaded functions


#include <iostream>

using namespace std;

class savingAccount{
    short rate = 5;
    public:
        short amount;
    void calc_amount(int init_amt){
        for(int i=0;i<6;i++)
            cout << "amount after " << i << " years: " << (init_amt + (init_amt * rate * i)/100) << endl;
    }
};

class fixedDeposit{
    short rate = 10;
    public:
        short amt;
    void calc_amount(int init_amt){
        for(int i=0;i<6;i++)
            cout << "amount after " << i << " years: " << (init_amt + (init_amt * rate * i)/100) << endl;
    }
};

class customer : public savingAccount, public fixedDeposit {
        public:
        string name;
        short initial_amt;
        int sum;

};


int main(){

    customer c[3];
    savingAccount s;
    fixedDeposit f;

    for(int i=0;i<3;i++)
    {
        cout << "enter name, initial amount for customer #" << i << ": ";
        cin >> c[i].name >> c[i].initial_amt;
    }

    for(int i=0;i<3;i++)
    {
        cout << "for savings account of customer " << i << ":" << endl;
        s.calc_amount(c[i].initial_amt);
        cout << "for fixed  diposit account of customer " << i << ":" << endl;
        f.calc_amount(c[i].initial_amt);
    }


}
