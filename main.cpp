#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

#include "interface.hpp"
#include "data.hpp"
#include "save.hpp"
#include "read.hpp"

using namespace std;

int main () {
    Data data = load();

    data.listStudents();

    string name; int id; string field;
    cin >> name >> id >> field;
    data.registerStudent(name, id, field);
}