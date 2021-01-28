//
// Created by George_PC on 11/20/2020.
//
#include <map>
#include <set>
#include "Date.h"
#ifndef C_PLUS_PLUS_WHITE_BELT_FINAL_TASK_DATABASE_H
#define C_PLUS_PLUS_WHITE_BELT_FINAL_TASK_DATABASE_H

class Database {
private:
    map<Date, set<string>> events;
public:
    void Add(const Date& data, const string& event);
    bool Delete(const Date& data, const string& event);
    int Delete(const Date& data);
    set<string> Find(const Date& data) const;
    void Print() const;
};


#endif //C_PLUS_PLUS_WHITE_BELT_FINAL_TASK_DATABASE_H
