#ifdef FILE_HPP
#else
#define FILE_HPP

#include <vector>
#include <fstream>
#include <iostream>

#include "data.hpp"

using namespace std;

void saveSt(const vector<Student>& students) {
    ofstream file("students.dat", ios::binary);
    if (!file) {
        cout << "Error opening file for writing!" << endl;
        return;
    }
    
    size_t size = students.size();
    file.write(reinterpret_cast<const char*> (&size) , sizeof(size));
    file.write(reinterpret_cast<const char*> (students.data()) , size * sizeof(Student));
    
    file.close();
}

vector<Student> loadSt() {
    ifstream file("students.dat", ios::binary);
    if (!file) {
        cout << "Error opening file for reading!" << endl;
        return {};
    }
    
    size_t size;
    file.read(reinterpret_cast<char*> (&size) , sizeof(size));
    
    vector<Student> students(size);
    file.read(reinterpret_cast<char*> (students.data()) , size * sizeof(Student));
    
    file.close();
    return students;
}

void saveSu(const vector<Subject>& subjects) {
    ofstream file("subjects.dat", ios::binary);
    if (!file) {
        cout << "Error opening file for writing!" << endl;
        return;
    }
    
    size_t size = subjects.size();
    file.write(reinterpret_cast<const char*> (&size) , sizeof(size));
    file.write(reinterpret_cast<const char*> (subjects.data()) , size * sizeof(Subject));
    
    file.close();
}

vector<Subject> loadSu() {
    ifstream file("subjects.dat", ios::binary);
    if (!file) {
        cout << "Error opening file for reading!" << endl;
        return {};
    }
    
    size_t size;
    file.read(reinterpret_cast<char*> (&size) , sizeof(size));
    
    vector<Subject> subjects(size);
    file.read(reinterpret_cast<char*> (subjects.data()) , size * sizeof(Subject));
    
    file.close();
    return subjects;
}

#endif