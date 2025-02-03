/*Implement a class Complex which represents the Complex Number data type. Implement
the following
1. Constructor (including a default constructor which creates the complex number 0+0i).
2. Overloaded operator+ to add two complex numbers.
3. Overloaded operator* to multiply two complex numbers.4. Overloaded << and >> to
print and read Complex Numbers.*/

#include<iostream>
using namespace std;
class Complex{

    public:
    float real, imag;
    Complex(){
        real = 0;
        imag = 0;
    }
    Complex(float real, float imag){
        this->real = real;
        this->imag = imag;
    }
    Complex operator+(Complex const obj){
        Complex res;
        res.real = real + obj.real;
        res.imag = imag + obj.imag;
        return res;
    }
    Complex operator*(Complex const obj){
        Complex res;
        res.real = real*obj.real - imag*obj.imag;
        res.imag = real*obj.imag + imag*obj.real;
        return res;
    }
    friend istream & operator >> (istream &, Complex & i){
        string ins;
        cin >> i.real >> ins>> i.imag;
        cin.ignore(1, 'i');
        return cin;
        }
    friend ostream & operator << (ostream &, const Complex & d){
        cout << d.real << " + " << d.imag << "i";
        return cout;
    }

};
int main(){
    cout << "Name: Prerana Pokarna " <<endl;
    cout << "Batch: S11 " << endl;
    cout << "Roll Number: SCOD38 "<< endl;
    Complex c1, c2;
    int choice;
    cout << "Enter complex number 1: ";
    cin >> c1;
    cout << "Enter complex number 2: ";
    cin >> c2;
    cout<< "What operation would you like to perform? \n 1. Addition \n 2. Multiplication. \n";
    cin >> choice;
    switch(choice){
        case(1):
            cout <<"(" << c1 << ") + (" << c2 << ") = (" << c1+c2 << ")\n";
            break;
        case(2):
            cout <<"(" << c1 << ") * (" << c2 << ") = (" << c1*c2 << ")\n"; 
    }
}
