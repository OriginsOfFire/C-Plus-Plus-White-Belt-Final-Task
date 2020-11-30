//
// Created by George_PC on 11/20/2020.
//

#include "Database.h"
int Database::AssembleNumber(const string& res) {
    int grade = 1, month = 0;
    for(unsigned i = res.size() - 1; i > 0; --i){
        month += (int)res[i] * grade;
        grade *= 10;
    }
    return month;
}

int Database::GetYear(const string &date) {
    string res;
    for(const auto& c : date){
        if(c == '/')
            break;
        else{
            res += c;
        }
    }
    return AssembleNumber(res);
}

int Database::GetMonth(const string &date) {
    string res;
    int countSlash = 0;
    for(const auto& c : date){
        if(c == '/')
            countSlash++;
        if(countSlash == 2)
            break;
        else if(countSlash == 1){
            res += c;
        }
    }
    return AssembleNumber(res);
}

int Database::GetDay(const string &date) {
    string res;
    int countSlash = 0;
    for(const auto& c : date){
        if(c == '/')
            countSlash++;
        if(countSlash == 3){
            res += c;
        }
    }
    return AssembleNumber(res);
}

void Database::PrintEvents(const vector<string> &current) {
    for(const auto& event : current){
        cout << event << " ";
    }
    cout << endl;
}

bool Database::FindStringInVector(const vector<string> &current, const string& event) {
    for(const auto& i : current){
        if(i == event)
            return true;
    }
    return false;
}

void Database::Add(const string& date, const string& event) {
    if(events.count(date) > 0){
        if(FindStringInVector(events.at(date), event)){
            return;
        }
        else{
            events.at(date).push_back(event);
            sort(events.at(date).begin(), events.at(date).end());
        }
    }
    else{
        events[date].push_back(event);
    }
}

string Database::Delete(const string& date) {
    int count = events.at(date).size();
    events.at(date).clear();
    stringstream result;
    result << "Deleted " << count << " events";
    return result.str();
}

string Database::Delete(const string &date, const string &event) {
    stringstream result;
    if(!(find(events.at(date).begin(), events.at(date).end(), event) != events[date].end())){
        result << "Event not found";
        return result.str();
    }
    else{
        for(size_t i = 0; i < events.at(date).size(); ++i){
            if(events.at(date)[i] == event){
                events.at(date).erase(events.at(date).begin() + i);
            }
        }
    }
}

void Database::Find(const string &date) {
    for(const auto& i : events.at(date)){
        cout << i << endl;
    }
}

void Database::Print() {
    for(const auto& item : events){
        cout << setw(4) << setfill('0') << GetYear(item.first)
        << '-' << setw(2) << setfill('0') << GetMonth(item.first)
        << '-' << setw(2) << setfill('0') << GetDay(item.first) << " ";
        PrintEvents(item.second);
    }
}

