/*Develop an object oriented program in C++ to create a database of student information
system containing the following information: Name, Roll number, Class, division, Date of
Birth, Blood group, Contact address, telephone number, driving license no. and other.
Construct the database with suitable member functions for initializing and destroying the
data viz constructor, default constructor, Copy constructor, destructor, static member
functions, friend class, this pointer, inline code and dynamic memory allocation
operators-new and delete*/

#include<iostream>
using namespace std;
class Student{
    int rollno, cls;
    string telephone, lisence;
    string name, address, dob, blood;
    char div;
    static int count;
    public:
    Student() //default constructor
    {
        rollno, cls = 0;
        telephone, lisence = "0";
        name, address, dob = "-";
        div, blood = '-';
        count += 1;
    }
    Student( int rollno, int cls, string telephone, string lisence, string name, string address, string dob, char div, string blood) //parametrized constructor
    {
        this->rollno = rollno; //this pointer
        this->cls = cls;
        this->telephone = telephone;
        this->lisence = lisence;
        this->name = name;
        this->address = address;
        this->dob = dob;
        this->div = div;
        this->blood = blood;
        count +=1;
    }
    Student(const Student &s){ //copy constructor
        cout << "\nCopy of student " << s.name << " is created." << endl;
        this->rollno = s.rollno; 
        this->cls = s.cls;
        this->telephone = s.telephone;
        this->lisence = s.lisence;
        this->name = s.name;
        this->address = s.address;
        this->dob = s.dob;
        this->div = s.div;
        this->blood = s.blood;
        count += 1;
    }
    ~Student(){
        count -= 1;
        cout << "Student is destroyed." << endl;
        displaycount();
    }
    static void displaycount(){
        cout << "Number of students is:" << count << endl;
    }
    void input()
    {
        cout <<endl;
        cout << "Enter student name: ";
        getline(cin, name);
        cout << "Enter student class: ";
        cin >> cls;
        cout << "Enter student division : ";
        cin >> div;
        cout << "Enter student roll number : ";
        cin >> rollno;
        cout << "Enter student address : ";
        cin.ignore();
        getline(cin, address);
        cout << "Enter student date of birth : ";
        cin.ignore();
        getline(cin, dob);
        cout << "Enter student telephone number : ";
        cin >> telephone;
        cout << "Enter student driving lisence number : ";
        cin >> lisence;
        cout << "Enter student blood type : ";
        cin >> blood;     
    }
    void display(){
        cout << "\nDetails of student " << count<< endl;
        cout << "Student name: " << name << endl;
        cout << "Student class: " << cls << endl;
        cout << "Student division : " << div << endl;
        cout << "Student roll number : " << rollno << endl;
        cout << "Enter student address : " << address << endl;
        cout << "Student date of birth: " << dob << endl;
        cout << "Student telephone number: " << telephone << endl;
        cout << "Student driving lisence number : " << lisence << endl;
        cout << "Student blood type : " << blood << endl;

    }

};
int Student::count = 0;
int main(){
    cout << "Name: Prerana Pokarna " <<endl;
    cout << "Batch: S11 " << endl;
    cout << "Roll Number: SCOD38 "<< endl;
    Student s1;
    s1.display();
    Student s2 = {1, 12, "773344256", "52273829", "Riya Sharma ", "Hadapsar", "12 September 2007", 'D', "A"};
    s2.display();
    Student s3;
    s3.input();
    s3.display();
    Student s4(s3);
    s4.display();
    Student::displaycount();

}