/*Write a C++ program that creates an output file, writes information to it, closes the file
andopen it again as an input file and read the information from the file.*/

#include<iostream>
#include<fstream>
using namespace std;
class Employee
{
    string Name;
    int ID;
    double salary;
    public:
    void accept()
    {
        cout<<"Enter Name : ";
        cin.ignore();
        getline(cin,Name);
        cout<<"Enter Id : ";
        cin>>ID;
        cout<<"Enter Salary : ";
        cin>>salary;
    }
    void display()
    {
        cout<<"\nName : "<<Name;
        cout<<"\nId : "<<ID;
        cout<<"\nSalary : "<<salary<<endl;
    }
};

int main()
{
    cout << "Name: Prerana Pokarna " <<endl;
    cout << "Batch: S11 " << endl;
    cout << "Roll Number: SCOD38 "<< endl;
    Employee temp;
    fstream f;
    int i,n;

    f.open("Employee.txt", ios::out | ios::trunc);
    if(!f.is_open()){
        cout << "Error opening file!" << endl;
    }
    else{ 
    cout<<"\nEnter the number of employees you want to store : ";
    cin>>n;
    for(i=0;i<n;i++)
    {
        cout<<"\nEnter information of Employee "<<i+1<<"\n";
        temp.accept();
        f.write((char*)&temp,sizeof(temp));
    }
    f.close();
    f.open("Employee.txt", ios::in);
    i = 1;
    cout << endl << endl;
    while(f.read((char*)&temp,sizeof(temp)))
    {
        cout << "Information of Employee " << i << ": ";
        temp.display();
        i++;
        cout << endl;
    }
    f.close();
    }
    return 0;
}