//
// Created by George_PC on 1/28/2021.
//
#include "Date.h"

bool operator<(const Date& lhs, const Date& rhs){
    if(lhs.GetYear() == rhs.GetYear()){
        if(lhs.GetMonth() == rhs.GetMonth()){
            return lhs.GetDay() < rhs.GetDay();
        }
        return lhs.GetMonth() < rhs.GetMonth();
    }
    return lhs.GetYear() < rhs.GetYear();
}

ostream& operator << (ostream& stream, const Date& date){
    stream << setfill('0') << setw(4) << to_string(date.GetYear()) << "-";
    stream << setfill('0') << setw(2) << to_string(date.GetMonth()) << "-";
    stream << setfill('0') << setw(2) << to_string(date.GetDay());
    return stream;
}

Date Parse(const string& date){
    stringstream ss(date);
    bool flag = true;
    int year, month, day;

    flag = flag && (ss >> year);
    flag = flag && (ss.peek() == '-');
    ss.ignore();

    flag = flag && (ss >> month);
    flag = flag && (ss.peek() == '-');
    ss.ignore();

    flag = flag && (ss >> day);
    flag = flag && ss.eof();

    if(!flag){
        throw logic_error("Wrong date format: " + date);
    }
    return {year, month, day};
}