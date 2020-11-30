#include <iostream>
#include "Database.h"
using namespace std;

int main() {
    Database test;
    test.Add("2002/05/16", "birthday");
    test.Print();
    return 0;
}
