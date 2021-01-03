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

    int GetYear() const{
        return year;
    }

    int GetMonth() const{
        return month;
    }

    int GetDay() const{
        return day;
    }

    string str() const{
        return to_string(year) + "-" + to_string(month) + "-" + to_string(day);
    }
};

bool inline operator<(const Date& lhs, const Date& rhs){
    if(lhs.GetYear() == rhs.GetYear()){
        if(lhs.GetMonth() == rhs.GetMonth()){
            return lhs.GetDay() < rhs.GetDay();
        }
        return lhs.GetMonth() < rhs.GetMonth();
    }
    return lhs.GetYear() < rhs.GetYear();
}

class Database {
private:
    map<Date, vector<string>> events;
public:
    void Add(const Date& data, const string& event);
    void Delete(const Date& data, const string& event);
    void Delete(const Date& data);
    void Find(const Date& data) const;
    void Print() const;
};


#endif //C_PLUS_PLUS_WHITE_BELT_FINAL_TASK_DATABASE_H
