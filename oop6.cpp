/* Write C++ program using STL for sorting and searching with user defined records such as
person record(Name, DOB, Telephone number), Item record (Item code, name,
cost,quantity) using vector container */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<string> personal_records;
    string name, birth, telephone;
    vector<string>::iterator it;
    vector<string> item_records;
    string item_name, quantity, cost, code;
    vector<string>::iterator it1;
    char cont = 'y';
    while(cont == 'y'){ 
        int choice;
        cout << "What would you like to do? 1. Access Personal Records 2. Access item records. ";
        cin>> choice;
        if(choice == 1)
        {
        bool a = true;
        int ch;
        int i;
        while(a){
            i = 1; 
            cout << "***MENU*** \n 1. Insert Record \n 2. Delete Record \n 3. Display Records \n 4. Exit \n";
            cin >> ch;
            switch(ch){
                case 1:
                { 
                    cout << "Enter details of record to be inserted. " << endl;
                    cout <<"Enter name: ";
                    cin.ignore();
                    getline(cin, name);
                    cout << "Enter date of birth: ";
                    getline(cin, birth);
                    cout << "Enter telephone: ";
                    cin >> telephone;
                    personal_records.push_back(name);
                    personal_records.push_back(birth);
                    personal_records.push_back(telephone);
                    break;
                }
                case 2:
                { 
                    cout <<"Enter name of record to be deleted: ";
                    cin >> name;
                    it = personal_records.begin();
                    while(it != personal_records.end()){
                        if(*it == name){
                            personal_records.erase(it, (it+3));
                            cout << "Successfully deleted" << endl;
                            break;
                        }
                        it = it + 3;
                    }
                    if(it == personal_records.end()){
                        cout << "Invalid details." << endl;
                    }
                    break;
                }
                case 3:
                { 
                    it = personal_records.begin();
                    while(it != personal_records.end()){
                        cout << "Record " << i << endl;
                        cout << "Name: " << *it << endl;
                        cout << "Date of birth: " << *(it +1)<< endl;
                        cout << "Telephone number: " << *(it +2) << endl;
                        it = it +3;
                        i++;
                    }
                    break;
                }
                case 4:
                    a = false;
                    break;
                default:
                    cout << "Invalid choice \n";
                    break;
                }
            }
        }
        if(choice == 2){
            bool b = true;
            int cho;
            string item;
            int i;
            while(b){ 
                i = 1;
                cout << "***MENU*** \n 1. Insert \n 2. Display \n 3. Search \n 4. Delete \n 5. Exit \n";
                cin >> cho;
                switch(cho){
                    case 1:
                    { 
                        cout << "Enter details of record to be inserted. " << endl;
                        cout << "Enter name: ";
                        cin >> item_name;
                        cout << "Enter code: ";
                        cin>> code;
                        cout << "Enter cost: ";
                        cin>> cost;
                        cout << "Enter quantity: ";
                        cin >> quantity;
                        item_records.push_back(item_name);
                        item_records.push_back(code);
                        item_records.push_back(cost);
                        item_records.push_back(quantity);
                        break;
                    }
                    case 2:
                    { 
                        it1 = item_records.begin();
                        while(it1 != item_records.end()){
                            cout << "Record " << i << endl;
                            cout << "Name: " << *it1 << endl;
                            cout << "Code: " << *(it1 +1) << endl;
                            cout << "Cost: " << *(it1 +2)<< endl;
                            cout << "Quantity: " << *(it1 +3) << endl;
                            it1 = it1 +4;
                            i++;
                        }
                        break;
                    }
                    case 3:
                    { 
                        cout << "Enter item name to search for. ";
                        cin >> item;
                        it1 = find(item_records.begin(), item_records.end(), item);
                        if(it1 == item_records.end()){
                            cout << "Invalid ";
                        }
                        else{
                            cout << "Name: " << *(it1) << endl;
                            cout << "Code: " << *(it1+ 1) << endl;
                            cout << "Cost: " << *(it1 + 2) << endl;
                            cout << "Quantity: " << *(it1 +3) << endl;
                        }
                        break;
                    }
                    case 4:
                    {
                        cout << "Enter item name to delete. ";
                        cin >> item;
                        it1 = find(item_records.begin(), item_records.end(), item);
                        if(it1 == item_records.end()){
                            cout << "Invalid ";
                        }
                        else{
                        item_records.erase(it1, (it1 +4));
                        cout << "Successfully Deleted \n";
                        }
                        break;
                    }
                    case 5:
                        b = false;
                        break;
                    default:
                        cout << "Invalid choice \n";
                        break;
                }
            }
        }
        cout << "Do you want to continue? (y/n)";
        cin >> cont;
    }
    return 0;
}