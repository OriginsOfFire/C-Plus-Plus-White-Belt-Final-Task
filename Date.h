//
// Created by George_PC on 1/28/2021.
//
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

#ifndef C_PLUS_PLUS_WHITE_BELT_FINAL_TASK_DATE_H
#define C_PLUS_PLUS_WHITE_BELT_FINAL_TASK_DATE_H

using namespace std;
class Date{
private:
    int year;
    int month;
    int day;

public:
    Date(int _year, int _month, int _day){
        if (_month < 1 || _month > 12)
        {
            throw out_of_range("Month value is invalid: " + to_string(_month));
        } else if (_day < 1 || _day > 31)
        {
            throw out_of_range("Day value is invalid: " + to_string(_day));
        }
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
};

bool operator<(const Date& lhs, const Date& rhs);
ostream& operator << (ostream& stream, const Date& date);
Date Parse(const string& date);
#endif //C_PLUS_PLUS_WHITE_BELT_FINAL_TASK_DATE_H
