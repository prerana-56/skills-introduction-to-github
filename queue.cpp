/* Write program to implement a priority queue in C++ using an inorder list to store the
items in the queue. Create a class that includes the data items (which should be
template) and the priority (which should be int). The inorder list should contain these
objects, with operator <= overloaded so that the items with highest priority appear at the
beginning of the list (which will make it relatively easy to retrieve the highest item.)
*/
#include<iostream>
using namespace std;
class Job{
    int priority, id;
    public:
    void accept(){
        cout << "Enter job ID: ";
        cin>> id;
        cout << "Enter Priority: ";
        cin>> priority;
    }
    friend class PQueue;
};

class PQueue{
    int front = -1, rear = -1, max = 5;
    Job queue[5];
    public:
    bool isfull(){
        if((rear + 1) == max) return true;
        else return false;
    }
    bool isempty(){
        if(front == -1) return true;
        else return false;
    }
    void enqueue(){
        if(isfull()) cout << "Queue overflow. " << endl;
        else{
            Job j1;
            j1.accept();
            if(isempty()){
                front++;
                rear++;
                queue[rear] = j1;
            }
            else{
                int i = rear;
                while(i >= front && (queue[i].priority >j1.priority)){
                    queue[i+1] = queue[i];
                    i--;
                }
                queue[i+1] = j1;
                rear++;
            }
        }
    }
    void dequeue(){
        if(isempty()) cout << "Queue Underflow" << endl;
        else{
            if(front == rear){
                front = -1;
                rear = -1;
            }
            else{
                front ++;
            }
        }
    }
    void print(){
        if(isempty()) cout << "Queue is Empty. " << endl;
        else{
            int i = front;
            while(i <= rear){
                cout << "Job ID: " << queue[i].id << endl;
                cout << "Job Priority: "<< queue[i].priority << endl << endl;
                i++;
            }
        }
    }
};
int main(){
    PQueue p1;
    int choice= 0;
    while(choice != 4){
        cout << "What would you like to do? \n 1. Insert Job \n 2. Process Job \n 3. Display Jobs \n 4. Exit \n";
        cin >> choice;
        switch(choice){
            case 1:
            p1.enqueue();
            break;
            case 2:
            p1.dequeue();
            break;
            case 3:
            p1.print();
            break;
            case 4:
            break;
            break;
        }
    }
    return 0;
}