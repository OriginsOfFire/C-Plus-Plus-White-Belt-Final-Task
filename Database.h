//
// Created by George_PC on 11/20/2020.
//
#include <map>
#include <string>
#include <sstream>
#include <vector>
#ifndef C_PLUS_PLUS_WHITE_BELT_FINAL_TASK_DATABASE_H
#define C_PLUS_PLUS_WHITE_BELT_FINAL_TASK_DATABASE_H

using std::map;
using std::string;
using std::vector;
using std::find;
using std::stringstream;

class Database {
private:
    map<string, vector<string>> events;

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
