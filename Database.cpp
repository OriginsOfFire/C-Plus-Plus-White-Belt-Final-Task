//
// Created by George_PC on 11/20/2020.
//

#include "Database.h"
void Database::Add(const string& date, const string& event) {
    if(find(events.at(date).begin(), events.at(date).end(), event) != events[date].end()){
        return;
    }
    else{
        events.at(date).push_back(event);
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
        vector<int> k = {1, 2, 3};
        for(size_t i = 0; i < events.at(date).size(); ++i){
            if(events.at(date)[i] == event){
                events.at(date).erase(events.at(date).begin() + i);
            }
        }
    }
}