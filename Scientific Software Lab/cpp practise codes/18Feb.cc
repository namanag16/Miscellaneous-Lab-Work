/* ****************************************
1. create a base class -- customer (name net-balance telephone acc no)
      derived class -- current acc (private members, curr_acc_no, balance)
      derived class -- savings acc (private members, savings_acc_no, balance)

public functions
virtual input(acc_no, bal)

use virtual function to call suitable function

2. create class tests (private-- test_name, test_cost)
   create class medicine(name,cost)
   create class patient (name ,, medicines ,, tests)

include doctors and treatment class
******************************************/
#include <iostream>

using namespace std;

class tests{
    char* test_name;
    short test_cost;

    public:

    void setTests(char* name, short cost){
        test_cost = cost;
        test_name = name;
    }
    friend class patient;
};

class medicines{
    char* med_name;
    short med_cost;

    public:


    void setMedicines(char* name, short cost){
        med_cost = cost;
        med_name = name;
    }
};

class doctor{
    short doc_id;
    char* doc_name;

    public:


    void setDoctorInfo(short id,char* name){
        doc_id = id;
        doc_name = name;
    }
};

class treatment {

    protected:
        doctor d;
        tests t[10];
        medicines m[10];
        short count_tests=0;
        short count_meds=0;
    public:

        virtual void setTreatmentInfo(){};

};


class patient : public treatment{
    short patient_id;
    char* patient_name;
    //treatment my_treat;

    public:
        void setPatientInfo(char *name,short id)
        {
            patient_id = id;
            patient_name = name;
        }

        void setTreatmentInfo();

        void displayTestBill(){
            int total =0;
            for(int i =0;i<count_tests;i++)
            {
                total += t[i].test_cost;
            }
            cout << "total test cost is: " << total << endl;
        }


};



int main()
{
    cout << "here i am" << endl;
    patient p;
    char* name;
    short id;

    cout << "enter patient name and id: ";
    cin >> name >> id;
    p.setPatientInfo(name,id);
    p.setTreatmentInfo();
    p.displayTestBill();
}

void patient::setTreatmentInfo(){

   char* name;
    short cost;
    cout << "enter doc name and doc id: ";
    cin >> name >> cost;

    d.setDoctorInfo(cost,name);

    cout << "enter test name and test cost: ";
    cin >> name >> cost;

    t[count_tests].setTests(name,cost);
    count_tests +=1;

    cout << "enter med name and med cost: ";
    cin >> name >> cost;

    m[count_meds].setMedicines(name,cost);
    count_meds +=1;

}

