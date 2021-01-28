#include "Database.h"

int main() {
    Database database;
    string command;

    try {
        while (getline(cin, command)) {
            if (command.empty())
                continue;

            stringstream input(command);
            string operation;
            input >> operation;

            if (operation == "Add") {
                string date, event;
                input >> date >> event;
                const Date data = Parse(date);
                if (!event.empty() || event != " ") {
                    database.Add(data, event);
                }
            } else if (operation == "Del") {
                string date, event;
                input >> date;
                if (!input.eof()) {
                    input >> event;
                }

                const Date data = Parse(date);

                if (event.empty()) {
                    const int deleted = database.Delete(data);
                    cout << "Deleted " << deleted << " events" << endl;
                } else {
                    if (database.Delete(data, event)) {
                        cout << "Deleted successfully" << endl;
                    } else {
                        cout << "Event not found" << endl;
                    }
                }
            } else if (operation == "Find") {
                string date, event;
                input >> date >> event;
                const Date data = Parse(date);
                set<string> events = database.Find(data);

                for (const string &another : events) {
                    cout << another << endl;
                }
            } else if (operation == "Print") {
                database.Print();
            } else {
                cout << "Unknown command: " << operation << endl;
            }
        }
    }
    catch (exception& e){
        cout << e.what() << endl;
        return 0;
    }
    return 0;
}
