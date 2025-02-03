/* The ticket booking system of Cinemax theater has to be implemented using C++ program.
There are 10 rows and 7 seats in each row. Doubly circular linked list has to be
maintained to keep track of free seats at rows. Assume some random booking to start
with. Use array to store pointers (Head pointer) to each row. On demand
a) The list of available seats is to be displayed
b) The seats are to be booked
c) The booking can be cancelled.
*/
#include<iostream>
using namespace std;
struct node{
    string data;
    node* next;
    node* prev;
};

class Row{
    node* first = nullptr;
    node* last = nullptr;
    static char fir;
    public:
    Row(int columns = 7){
        for(int i = 0; i<=columns; i++){ 
            node* new_node = new node();
            if(!first){
                first = new_node;
                last = new_node;
                new_node->data = fir;
                new_node->next = new_node->prev = new_node;
            }
            else{ 
                new_node->data = " ___ ";
                new_node->next = first;
                new_node->prev = last;
                last->next = new_node;
                first->prev = new_node;
                last = new_node;
            }
        }
        fir = fir + 1;
    }
    ~Row(){
        while(first != last){
            delete first;
            first = first->next;
        }
        cout << first;
    }
    node* returnhead(){
        return first;
    }
};
char Row::fir = 65;
void displayrow(node* first){
        node* temp = first;
        do {
            cout << temp->data;
            temp = temp->next;
        }
        while(temp != first);
        cout << endl;
    }
void book(node* arr[], int len){
    string row;
    int column;
    cout << "\nWhat seat would you like to book? ";
    cin>> column >> row;
    node* head;
    bool flag;
    for(int i = 0; i < len; i++){
        if((arr[i])->data == row){
            head = arr[i];
            flag = true;
            break;
        }
        flag = false;
    }
    if(flag == true){ 
        node* first = head;
        for(int j =0; j < column; j++ ){
            head = head->next;
            if(head == first){
                cout << "Invalid column number. " << endl;
                break;
            }
        }
        if(head->data == " ___ "){ 
            head->data = " _B_ ";
            cout << "\nSeat " << column << row << " successfully booked" << endl;
        }
        else if(head != first) cout << "Seat is booked. " << endl;
    }
    else if(flag == false) cout << "Invalid row. " << endl;
}

void display(node* arr[], int len){
    cout << endl;
    cout << "   1    2    3    4    5    6    7" << endl;
    for(int i = 0; i < len; i++){
        displayrow(arr[i]);
    }
    cout << endl;
}

void cancel(node* arr[], int len){
    string row;
    int column;
    cout << "\nWhat seat booking would you like to cancel? ";
    cin>> column >> row;
    node* head;
    bool flag;
    for(int i = 0; i < len; i++){
        if((arr[i])->data == row){
            head = arr[i];
            flag = true;
            break;
            flag = false;
        }
    }
    if(flag == true){ 
        node* first = head;
        for(int j =0; j < column; j++ ){
            head = head->next;
            if(head == first){
                cout << "Invalid column number. " << endl;
                break;
            }
        }
        if(head->data == " _B_ "){ 
            head->data = " ___ ";
            cout << "\nBooking of seat " << column << row << " successfully cancelled." << endl;
        }
        else if(head != first) cout << "Seat is not booked. " << endl;
    }
    else if(flag == false) cout << "Invalid row. " << endl;
}

int main(){
    int rows = 10;
    int choice;
    char cont = 'y';
    node* ptrs[rows] = {};
    for(int i = 0; i < rows; i++){
        Row* r = new Row();
        node* ptr = r->returnhead();
        ptrs[i] = ptr;
    }
    while(cont == 'y'){ 
        cout << "\nWhat would you like to do? \n 1. Display seats \n 2. Book tickets \n 3. Cancel booking " << endl;
        cin >> choice;
        switch(choice){
            case 1:
                display(ptrs, rows);
                break;
            case 2:
                int tickets;
                cout << "How many tickets would you like to book? ";
                cin>> tickets;
                for(int i = 0; i < tickets; i++)
                book(ptrs, rows);
                break;
            case 3:
                int tickets_c;
                cout << "How many tickets would you like to cancel? ";
                cin>> tickets_c;
                for(int i = 0; i < tickets_c; i++)
                cancel(ptrs, rows);
                break;
            default:
                cout << "Invalid choice. " << endl;
        }
        cout << "\nWould you like to continue? (y/n) ";
        cin>> cont;
    }
}