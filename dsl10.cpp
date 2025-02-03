/* A palindrome is a string of character that‘s the same forward and backward. Typically,
punctuation, capitalization, and spaces are ignored. For example, “Poor Dan is in a droop”
is a palindrome, as can be seen by examining the characters “poor danisina droop” and
observing that they are the same forward and backward. One way to check for a
palindrome is to reverse the characters in the string and then compare with them the
original-in a palindrome, the sequence will be identical. Write C++ program with
functionsa) To print original string followed by reversed string using stack
b) To check whether given string is palindrome or not
*/

#include<iostream>
using namespace std;
int stack[70], n = 70, top = -1;
void push(char val){
    if(top >= n){
        cout << "Stack Overflow. "<< endl;
    }
    else{
        top++;
        stack[top] = val;
    }
}
void pop(){
    if(top < 0){
        cout << "Stack underflow. " << endl;
    }
    else{
        top--;
    }
}
char peek(){
    if(top < 0) cout << "Underflow " << endl;
    else if(top >=n ) cout << "Overflow "<< endl;
    else return stack[top];
    return ' ';
}
void clear(){
    while(top != -1){
        pop();
        top--;
    }
}
void reversestring(){
    char x;
    cout << "Enter a string: ";
    while(cin.get(x)){ 
        if(x == '\n')
        break;
        push(x);
    }
    while(top>=0){
        cout << peek();
        pop();
    }
}

bool ispalindrome() {
    string y;
    cout << "Enter a string: ";
    cin.ignore();
    getline(cin, y);
    int length = y.length();
    for (int i = 0; i < length; i++) {
        if (isalpha(y[i])) {
            push(tolower(y[i])); // Push lowercase characters
        }
    }

    for (int i = 0; i < length; i++) {
        if (isalpha(y[i])) {
            char lowerChar = tolower(y[i]);
            if (lowerChar != peek()) {
                clear(); // Clear the stack for next operation
                return false;
            }
            pop();
        }
    }
    
    clear(); // Clear the stack after operation
    return true;
}
int main(){
    int choice;
    char cont = 'y';
    while(cont == 'y'){ 
        cout << "What would you like to do? \n 1. Reverse String \n 2. Check if string is palindrome. "<< endl;
        cin>> choice;
        switch(choice){
            case 1:
                cin.ignore();
                reversestring();
                clear();
                break;
            case 2:
                if(ispalindrome() == true)
                cout << "\nString is palindrome. ";
                else cout << "\nString is not a palindrome. ";
                clear();
                break;
            default:
                cout << "\n Invalid Choice. ";
                break;
        }
        cout << "\nDo you want to continue? (y/n)";
        cin>> cont;
    }
    
}