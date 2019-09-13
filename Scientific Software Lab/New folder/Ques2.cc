#include <iostream>
#include <fstream>

using namespace std;


class train
{
    protected:
    int train_no;
    char name[30];
    char dest[30];
    char source[30];

    //public:
    //    void set_values(int no, char nam[],char dest[],char source[])
    //    {
    //
    //    }
    public:
    virtual void input()
    {
        cout << "nothing " << endl;
    }
};

class shatabadi : public train
{
        int ac3,ac2,ac1;
        int date;
    public:
        friend void return_seat1(shatabadi s,int *ac1, int *ac2, int *ac3);
        //friend void return_seat(rajdhani r, shatabadi s,jan_shatabadi j);
        void input()
        {
            char file1[30];
            short n;
            //char file2[30];
            //cout << "enter file for train : ";
            //cin >> file1;
            //file1 = "input_train1.txt";
            //cout << "enter file for seats: ";
            //cin >> file2;
            //file2 = "input_seats.txt";
            ifstream fin("input_train1.txt");
//            cout << "enter number of trains" ;
//            cin >> n;
//            short i =1;
//            while(i<=n)
//            {
            fin >>  this->train_no;
            fin >>  this->name;
            fin >> this->dest;
            fin >> this->source;

            fin >>  this->ac3;
            fin >>  this->ac2;
            fin >> this->ac1;
            fin >> this->date;
        }

};

class jan_shatabadi: public train
{
        int ac3,ac2,ac1;
        int date;
    public:
    friend void return_seat2(jan_shatabadi s,int *ac1, int *ac2, int *ac3);
    //friend void return_seat(rajdhani r, shatabadi s,jan_shatabadi j);
        void input()
        {
            char file1[30];
            short n;
            ifstream fin("input_train2.txt");
            fin >>  this->train_no;
            fin >>  this->name;
            fin >> this->dest;
            fin >> this->source;

            fin >>  this->ac3;
            fin >>  this->ac2;
            fin >> this->ac1;
            fin >> this->date;
        }

};

class rajdhani: public train
{

        int ac3,ac2,ac1;
        int date;
    public:
        friend void return_seat3(rajdhani s,int *ac1, int *ac2, int *ac3);
        //friend void return_seat(rajdhani r, shatabadi s,jan_shatabadi j);
        void input()
        {
            char file1[30];
            short n;
            ifstream fin("input_train3.txt");
            fin >>  this->train_no;
            fin >>  this->name;
            fin >> this->dest;
            fin >> this->source;

            fin >>  this->ac3;
            fin >>  this->ac2;
            fin >> this->ac1;
            fin >> this->date;
        }

};



int main()
{
    train *t;
    shatabadi s;
    jan_shatabadi j;
    rajdhani r;

    t = &s;
    t->input();

    t = &j;
    t->input();

    t = &r;
    t->input();

    int tot1,tot2,tot3,ac1,ac2,ac3;
    tot1=0;
    tot2=0;
    tot3=0;


    return_seat3(r,&ac1,&ac2,&ac3);
    tot1 = tot1 + ac1;
    tot2 = tot2 + ac2;
    tot3 = tot3 + ac3;

    return_seat2(j,&ac1,&ac2,&ac3);
    tot1 = tot1 + ac1;
    tot2 = tot2 + ac2;
    tot3 = tot3 + ac3;

    return_seat1(s,&ac1,&ac2,&ac3);
    tot1 = tot1 + ac1;
    tot2 = tot2 + ac2;
    tot3 = tot3 + ac3;

    cout << "total passengers travelled: \nac1 " << tot1 << "\nac2 "<< tot2 << "\nac3 "<< tot3 ;
}
//void return_seat(rajdhani r,shatabadi s, jan_shatabadi j)
//{
//    cout << "total number of ac3 passengers: " << r.ac3 + s.ac3 + j.ac3 << endl;
//    cout << "total number of ac2 passengers: " << r.ac2 + s.ac2 + j.ac2 << endl;
//    cout << "total number of ac1 passengers: " << r.ac1 + s.ac1 + j.ac1 << endl;
//}

void return_seat3(rajdhani s,int *ac1, int *ac2, int *ac3)
{
    *ac1 = s.ac1;
    *ac2 = s.ac2;
    *ac3 = s.ac3;
}
void return_seat2(jan_shatabadi s,int *ac1, int *ac2, int *ac3)
{
    *ac1 = s.ac1;
    *ac2 = s.ac2;
    *ac3 = s.ac3;
}

void return_seat1(shatabadi s,int *ac1, int *ac2, int *ac3)
{
    *ac1 = s.ac1;
    *ac2 = s.ac2;
    *ac3 = s.ac3;
}
