//
// Created by George_PC on 11/20/2020.
//

#include "Database.h"
void Database::Add(const Date& data, const string& event) {
    events[data].push_back(event);
    sort(events[data].begin(), events[data].end());
}

void Database::Delete(const Date& data, const string& event){
    auto isin = find(events[data].begin(), events[data].end(), event);
    if(events.contains(data) && isin != events[data].end() ){
        events[data].erase(isin);
        cout << "Deleted successfully" << endl;
    }
    else{
        cout << "Event not found" << endl;
    }
}

void Database::Delete(const Date &data) {
    if(events.contains(data)){
        cout << "Deleted " << events[data].size() << " events" << endl;
        events[data].clear();
    }
    else{
        cout << "Deleted 0 events" << endl;
    }
}

void Database::Find(const Date &data) const{
    if(events.contains(data)){
        for(const auto& event : events.at(data)){
            cout << event << endl;
        }
    }
}

void Database::Print() const {
    for(const auto& item : events){
        for(const auto& event : item.second){
            cout << item.first.str() << " " << event << endl;
        }
    }
}