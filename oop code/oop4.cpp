#include<iostream>
#include<fstream>
using namespace std;

class Employee
{
    char Name[20];
    int ID;
    double salary;
    public:
        void accept()
        {
            cin>>Name;
            cin>>ID;
            cin>>salary;
        }
        void display()
        {
            cout<<"\n Enter Name:"<<Name;
            cout<<"\n Enter Id:"<<ID;
            cout<<"\n Enter Salary:"<<salary;
        }
};
       
int main()
{
    Employee e[5];
    fstream f;
    int i,n;
   
    f.open("Hello.txt");
    cout<<"\n How many employee information do you need to store?";
    cin>>n;
    cout<<"\n Enter information of employee in this format(NAME/ID/SALARY)";
    for(i=0;i<n;i++)
    {
        cout<<"\n Enter information of:"<<i<<"\n Employee";
        e[i].accept();
        f.write((char*)&e[i],sizeof e[i]);
    }
   
    f.close();
   
    f.open("Hello.txt",ios::in);
    cout<<"\n Information of Employees is as follows:";
    for(i=0;i<n;i++)
    {
        f.write((char*)&e[i],sizeof e[i]);
        e[i].display();
    }
    f.close();
   
    return 0;
}