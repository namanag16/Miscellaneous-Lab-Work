#include<iostream>
#include<cstdio>
using namespace std;
class person{
    private:
        int ssnNum;
        char name[50];
    public: friend void getPerson( person a);
            virtual void display(){
                cout<<"\nName="<<name;
                cout<<"\nSSN number="<<ssnNum;
            }
};
void getPerson(person a){
    cout<<"\nEnter person name";
    cin>>a.name;
    cout<<"\nEnter person SSN Number";
    cin>>a.ssnNum;
}
class medicine{
    private:
        char medicineName[50];
        int cost;
    public:
        void getMed(){
            cout<<"\n Enter medicine name";
            cin>>medicineName;
            cout<<"\n Enter cost";
            cin>>cost;
        }
        friend class patient;
        void display(){
            cout<<"\nMedicine name= "<<medicineName;
            cout<<"\ncost = "<<cost;
        }
        char* retMedicineName(){
            return medicineName;
        }
        int retCost(){
            return cost;
        }
};
class doctor: public person{
    private:
        char qualification[10];
        char specialization[10];
        int roomNo;
        int consultationFees;
    public:
        friend class treatment;
        void getDoc(){
            getPerson(*this);
            cout<<"\nEnter Qualification : ";
            cin>>qualification;
            cout<<"\nEnter Specialization : ";
            cin>>specialization;
            cout<<"\nEnter Room No. : ";
            cin>>roomNo;
            cout<<"Enter consultation fees: ";
            cin>>consultationFees;
        }
    public:
        void display(){
        person::display();
        cout<<"\nQualification= "<<qualification;
        cout<<"\nSpecialization= "<<specialization;
        cout<<"\nRoom No= "<<roomNo;
        cout<<"Consultation Fees: "<<consultationFees;
    }
};


class test{
    private:
        char testName[20];
        int testCost;
    public:
        void getTest(){
            cout<<"\nEnter test name ";
            cin>>testName;
            cout<<"\nEnter test cost";
            cin>>testCost;
        }
        int retTestCost(){
            return testCost;
        }
        char* retTestName(){
            return testName;
        }
        void display(){
            cout<<"\nTest name= "<<testName;
            cout<<"\nTest cost= "<<testCost;
        }
};

class patient:public person{

    public:
            friend class treatment;
            medicine medicines[20];
            test tests[10];
            int noOfTests;
            int noOfMedicines;
            void getPatient(){
                getPerson(*this);
                cout<<"\nEnter Number of tests: ";
                cin>>noOfTests;
                for(int i=0;i<noOfTests;i++){
                cout<<"\nEnter Details of test "<<i<<"\n";
                tests[i].getTest();
                }
                cout<<"\nEnter Number of medicines: ";
                cin>>noOfMedicines;
                for(int i=0;i<noOfMedicines;i++){
                cout<<"\nEnter Details of medicines "<<i<<"\n";
                medicines[i].getMed();
                }
            }


            void display(){
                person::display();

                cout<<"\nTests:\n";
                for(int i=0;i<noOfTests;i++){
                    tests[i].display();
                }
                cout<<"\nMedicines:\n";
                for(int i=0;i<noOfMedicines;i++){
                    medicines[i].display();
                }
            }

};
class treatment{
    public:
    patient p1;
    doctor assignedDoctor;
    void getTreatment(){
        person *firstperson;
        cout<<"\n-------- Enter Patient Details-------\n";
        p1.getPatient();
        cout<<"\n-------- Enter doctor Details-------\n";
        assignedDoctor.getDoc();
    }
    void display(){
        cout<<"\n-----------Patient details:-------\n";
        person *firstPerson;
        firstPerson=&p1;
        firstPerson->display();
        cout<<"\n-----------Doctor details:-------\n";
        firstPerson=&assignedDoctor;
        firstPerson->display();
    }
    void generateBill(){
        cout<<"\n--------Bill--------\n";
        cout<<"\nConsultation Fees="<<assignedDoctor.consultationFees;
        float total=assignedDoctor.consultationFees;
        cout<<"\nTest charges=\n";
        float testTotal=0;
        for(int i=0;i<p1.noOfTests;i++)
        {
            p1.tests[i].display();
            testTotal+=p1.tests[i].retTestCost();
        }
        cout<<"\nTotal Test cost="<<testTotal;
        total+=testTotal;
        float medicineTotal=0;
        for(int i=0;i<p1.noOfMedicines;i++)
        {
            p1.medicines[i].display();
            medicineTotal+=p1.medicines[i].retCost();
        }
        cout<<"\nTotal Test cost="<<medicineTotal;
        total+=medicineTotal;
        cout<<"\n Grand Total ="<<total;

    }
};
int main(){
    treatment t1;
    t1.getTreatment();
    t1.display();
    t1.generateBill();
}
