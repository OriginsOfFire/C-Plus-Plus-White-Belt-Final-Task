//
// Created by George_PC on 11/20/2020.
//

#include "Database.h"
void Database::Add(const Date& data, const string& event) {
    if(!event.empty()){
        events[data].insert(event);
    }
}

bool Database::Delete(const Date& data, const string& event){
    if(events.count(data) > 0 && events[data].count(event) > 0){
        events[data].erase(event);
        return true;
    }
    return false;
}

int Database::Delete(const Date &data) {
   int deleted = 0;
   if(events.count(data) > 0){
       deleted = events.at(data).size();
       events.erase(data);
   }
   return deleted;
}

set<string> Database::Find(const Date &data) const{
    set<string> found;
    if(events.count(data) > 0){
        found = events.at(data);
    }
    return found;
}

void Database::Print() const {
    for(const auto& date : events){
        for(auto& event : date.second){
            cout << date.first << " " << event << endl;
        }
    }
}
