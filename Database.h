//
// Created by George_PC on 11/20/2020.
//
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#ifndef C_PLUS_PLUS_WHITE_BELT_FINAL_TASK_DATABASE_H
#define C_PLUS_PLUS_WHITE_BELT_FINAL_TASK_DATABASE_H

using namespace std;
class Date{
private:
    int year;
    int month;
    int day;
public:
    Date(int _year, int _month, int _day){
        year = _year;
        month = _month;
        day = _day;
    }
    
};
class Database {
private:
    map<string, vector<string>> events;
    int AssembleNumber(const string& res);
    int GetYear(const string& date);
    int GetMonth(const string& date);
    int GetDay(const string& date);
    void PrintEvents(const vector<string>& current);
    bool FindStringInVector(const vector<string>& current, const string& event);
public:
    Database() = default;;
    ~Database()= default;;

    void Add(const string& date, const string& event);
    string Delete(const string& date);
    string Delete(const string& date, const string& event);
    void Find(const string& date);
    void Print();
};


#endif //C_PLUS_PLUS_WHITE_BELT_FINAL_TASK_DATABASE_H
