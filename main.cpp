#include <iostream>
#include "Database.h"
using namespace std;

Date Input(stringstream ss){
    if(ss) {
        int year, month, day;
        ss >> year;
        ss.ignore(1);
        ss >> month;
        ss.ignore(1);
        ss >> day;
        return {year, month, day};
    }
    
}

int main() {
    Database test;
    string command;
    while (getline(cin, command)) {
        stringstream ss(command);
        string action;
        ss >> action;
        cout << action;


        if(ss) {
            string event;
            ss >> event;
        }

    }
    return 0;
}
