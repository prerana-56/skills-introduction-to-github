/* Write C++ program for storing appointment schedule for day. Appointments are booked
randomly using linked list. Set start and end time and min and max duration for visit slot.
Write functions fora) Display free slots
b) Book appointment
c) Cancel appointment ( check validity, time bounds, availability)
d) Sort list based on time
e) Sort list based on time using pointer manipulation
*/
#include<iostream> 
using namespace std;
struct node{
    int time;
    int apt_no;
    string free;
    node* next;
};

class Day{
    node* head = nullptr;
    int apt_no = 0;
    public:
    Day(){
        for(int i = 9; i < 18; i++){ 
            node* new_node = new node();
            if(!head){
                head = new_node;
            }
            new_node->free = "Free";
            new_node->time = i;
            node* temp = head;
            while(temp->next){
                temp = temp->next;
            }
            temp->next = new_node;
            new_node->next = nullptr;
        }
    }
        ~Day() { 
        node* temp = head;
        while (temp->next) {
            temp = temp->next;
            delete temp; 
        }
    }
    void displayslots(){
        node* temp= head;
        cout << endl;
        while(temp->next){
            cout << temp->time << " - " << (temp->next)->time<< " : " << temp->free << endl;
            temp = temp->next;
        }
        cout << endl;
    }
    void bookappointment(){
        int hr;
        int len;
        cout << "What time would you like to book your appointment? ";
        cin >> hr;
        cout << "Would you like to book a 1 hour slot or a 2 hour slot? (1/2) ";
        cin>> len;
        node* temp = head;
        if(len == 1){ 
            while(temp){
                if(temp->time == hr){
                    if(temp->free == "Free"){
                        temp->free = "Booked";
                        apt_no += 1;
                        temp->apt_no = apt_no;
                        cout << "\nAppointment successfully booked! Your appointment number is " << apt_no << endl;
                    }
                    else{
                        cout << "\n Sorry! This slot is booked. " << endl;
                    }
                    break;
                }
                temp = temp->next;
            }
        }
        else if(len == 2){
            while(temp){
                if(temp->time == hr && temp->next){
                    if(temp->free == "Free" && (temp->next)->free == "Free"){
                        temp->free = "Booked";
                        (temp->next)->free = "Booked";
                        apt_no += 1;
                        temp->apt_no = apt_no;
                        (temp->next)->apt_no = apt_no;
                        cout << "\nAppointment successfully booked! Your appointment number is " << apt_no << endl;
                    }
                    else{
                        cout << "\n Sorry! This slot is booked. " << endl;
                    }
                    break;
                }
                temp = temp->next;
            }
        }
        else cout << "\nInvalid appointment duration. " << endl;
        if(!temp){
            cout << "\nInvalid time." << endl;
        }
    }
    void cancelapt(){
        int hr, aptno, len;
        cout << "What time is your appointment? ";
        cin>> hr;
        cout << "What is your appointment number? ";
        cin >> aptno;
        cout << "How long is your appointment? ";
        cin >> len;
        node* temp = head;
        if(len == 1){ 
            while(temp){
                if(temp->time == hr){
                    if(temp->apt_no == aptno){
                        temp->free = "Free";
                        temp->apt_no = 0;
                        cout<< "\nAppointment successfully cancelled. " << endl;
                    }
                    else cout << "\nInvalid appointment number. " << endl;
                    break;
                }
                temp = temp->next;
            }
        }
        else if(len == 2){
            while(temp->next){
                if(temp->time == hr){
                    if(temp->apt_no == aptno && (temp->next)->apt_no == aptno){
                        temp->free = "Free";
                        (temp->next)->free = "Free";
                        temp->apt_no = 0;
                        (temp->next)->apt_no = 0;
                        cout<< "\nAppointment successfully cancelled. " << endl;
                    }
                    else cout << "\nIncorrect appointment number or length enetered. " << endl;
                    break;
                }
                temp = temp->next;
            }
        }
        else cout << "\nInvalid appointment duration. " << endl;
    }

};
int main(){
    Day d1;
    int choice;
    char cont = 'y';
    while(cont == 'y'){ 
        cout << "\nWhat would you like to do?\n 1. Display Slots \n 2. Book an appointment \n 3. Cancel an appointment \n 4. Exit program " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            d1.displayslots();
            break;
        case 2:
            d1.bookappointment();
            break;
        case 3:
            d1.cancelapt();
            break;
        case 4: 
            break;
        default:
            cout << "\nInvalid Choice. ";
            break;
        }
        cout << "Would you like to continue? (y/n)";
        cin>> cont;
    }
    return 0;
}
