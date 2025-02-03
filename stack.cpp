/* Implement C++ program for expression conversion as infix to postfix and its evaluation
using stack based on given conditions:
1. Operands and operator, both must be single character.
2. Input Postfix expression must be in a desired format.
3. Only '+', '-', '*' and '/ ' operators are expected. */

#include<iostream>
using namespace std;
template<class T>
class Stack{
    int top = -1, max = 100;
    T stack[100];
    public:
    bool isempty(){
        if(top == -1) return true;
        else return false;
    }
    void push(T data){
        if((top +1)== max) cout << "Stack Overflow. " << endl;
        else{
            top++;
            stack[top] = data;
        }
    }
    void pop(){
        if(top == -1) cout << "Stack Undeflow" << endl;
        else{
            top--;
        }
    }
    T peek(){
        return stack[top];
    }
};

int weight(char op){
    switch(op){
        case '+': 
        case '-':
        return 1;
        break;
        case '*':
        case '/':
        return 2;
        break;
        default:
        return 0;
        break;
    }
}
string infixtopostfix(string infix){
    string postfix = "";
    Stack<char> convert;
    for(int i = 0; i < infix.length(); i++){
        char ch = infix[i];
        if(isalpha(ch)){
            postfix = postfix + ch;
        }
        else if(ch == '('){
            convert.push(ch);
        }
        else if(ch == ')'){
            while(convert.peek() != '('){
                postfix = postfix + convert.peek();
                convert.pop();
            }
            convert.pop();
        }
        else if(ch == '+'||ch == '-'||ch == '*'||ch == '/'){
            while(weight(ch) <= weight(convert.peek())){
                postfix = postfix + convert.peek();
                convert.pop();
            }
            convert.push(ch);
        }
    }
    while(!convert.isempty()){
        postfix = postfix + convert.peek();
        convert.pop();
    }
    return postfix;
}
int operate(int op1, char op, int op2){
    switch(op){
        case '+':
        return op1+op2;
        break;
        case '-':
        return op1-op2;
        break;
        case '*':
        return op1*op2;
        break;
        case '/':
        return op1/op2;
        break;
        default:
        return 0;
        break;
    }
}
int evalpostfix(string postfix){
    string s1;
    for(int i = 0; i < postfix.length(); i++){
        if(isalpha(postfix[i])){ 
            bool flag = false;
            for(int j = 0; j<s1.length(); j++){
                if(postfix[i] == s1[j]){
                    flag = true;
                    break;
                }
            }
            if(!flag) s1 = s1+ postfix[i];
        }
    }
    int values[s1.length()];
    for(int i = 0; i < s1.length(); i++){
        cout << "Enter the value of " << s1[i] << ": ";
        cin>> values[i];
    }
    Stack<int> temp;
    for(int i = 0; i <postfix.length(); i++){
        char ch = postfix[i];
        if(isalpha(ch)){
            int val;
            for(int j = 0; j < s1.length(); j++){
                if(ch == s1[j]) {
                    val = values[j];
                    break;
                }
            }
            temp.push(val);
        }
        else if(ch == '+'||ch == '-'||ch == '*'||ch == '/'){
            int op2 = temp.peek();
            temp.pop();
            int op1 = temp.peek();
            temp.pop();
            int res = operate(op1, ch, op2);
            temp.push(res);
        }
    }
    return temp.peek();
}
int main(){
    string infix;
    cout << "Enter infix string: ";
    cin>> infix;
    string pfix = infixtopostfix(infix);
    cout << pfix;
    cout << endl;
    int fin = evalpostfix(pfix);
    cout << fin;

}