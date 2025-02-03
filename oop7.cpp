/* Write a program in C++ to use map associative container. The keys will be the names of
states, and the values will be the populations of the states. When the program runs, the
user is prompted to type the name of a state. The program then looks in the map, using
the state name as an index, and returns the population of the state. */

#include <iostream>
#include <map>
#include <string>
using namespace std;
int main(){
    map<string, string> populations = {
        {"Uttar Pradesh","199,581,477"},
        {"Maharashtra","112,372,972"},
        {"Bihar","103,804,637"},
        {"West Bengal", "91,347,736"},
        {"Andhra Pradesh", "84,665,533"},
        {"Madhya Pradesh", "72,597,565"},
        {"Tamil Nadu", "72,138,958"},
        {"Rajasthan", "68,621,012"},
        {"Karnataka", "61,130,704"},
        {"Gujrat", "60,383,628"},
        {"Odisha", "41,947,358"},
        {"Telangana", "35,193,978"},
        {"Kerala", "33,387,677"},
        {"Jharkhand", "32,966,238"},
        {"Assam", "31,169,272"},
        {"Punjab", "27,704,236"},
        {"Haryana", "25,353,081"},
        {"Chhattisgarh", "25,540,196"},
        {"Delhi", "16,753,235"},
        {"Jammu and Kashmir", "12,267,013"},
        {"Uttarakhand", "11,116,752"},
        {"Himachal Pradesh", "6,856,509"},
        {"Tripura", "3,671,032"},
        {"Meghalaya", "2,964,007"},
        {"Manipur", "2,721,756"},
        {"Nagaland", "1,980,602"},
        {"Goa", "1,457,723"},
        {"Arunachal Pradesh", "1,382,611"},
        {"Mizoram", "1,091,014"},
        {"Sikkim", "607,688"},
        {"Puducherry", "1,244,464"},
        {"Chandigarh", "1,054,686"},
        {"Dadra and Nagar Haveli and Daman and Diu", "585,764"},
        {"Andaman and Nicobar Islands", "379,944"},
        {"Ladakh", "274,289"},
        {"Lakshadweep" ,"64,429"}
    };
    map<string, string>::iterator it = populations.begin();
    string state;
    cout << "What state would you like the population of?";
    cin>> state;
    while (it != populations.end()) {
        if(it->first == state){
        break;
        }
        it++;
    }
    if(it == populations.end()){
        cout << "Invalid state!" << endl;
    }
    else{
        cout << "Population = " << it->second;
    }
}