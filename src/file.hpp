#ifdef FILE_HPP
#else
#define FILE_HPP

#include <vector>
#include <fstream>
#include <iostream>

#include "data.hpp"

using namespace std;

void saveSt(const vector<Student>& students) {
    ofstream file("students.dat", ios::binary | ios::trunc);
    if (!file) {
        cout << "Unable to Save. " << endl;
        return;
    }

    int size = students.size();
    file.write(reinterpret_cast<const char*>(&size), sizeof(size));

    for (const Student& student : students) {
        int nameLength = student.name.size();
        file.write(reinterpret_cast<const char*>(&nameLength), sizeof(nameLength));
        file.write(student.name.c_str(), nameLength);

        file.write(reinterpret_cast<const char*>(&student.id), sizeof(student.id));

        int fieldLength = student.field.size();
        file.write(reinterpret_cast<const char*>(&fieldLength), sizeof(fieldLength));
        file.write(student.field.c_str(), fieldLength);

        int subjectCount = student.subjects.size();
        file.write(reinterpret_cast<const char*>(&subjectCount), sizeof(subjectCount));

        for (const Subject& subject : student.subjects) {
            int subNameLength = subject.name.size();
            file.write(reinterpret_cast<const char*>(&subNameLength), sizeof(subNameLength));
            file.write(subject.name.c_str(), subNameLength);
            
            file.write(reinterpret_cast<const char*>(&subject.multiplier), sizeof(subject.multiplier));
            file.write(reinterpret_cast<const char*>(&subject.score), sizeof(subject.score));
        }
    }

    file.close();
}

vector<Student> loadSt() {
    ifstream file("students.dat", ios::binary);
    if (!file) {
        cout << "No Saves Detected to Load. " << endl;
        return {};
    }

    int size;
    file.read(reinterpret_cast<char*>(&size), sizeof(size));

    vector <Student> students(size);
    for (Student& student : students) {
        int nameLength;
        file.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));
        student.name.resize(nameLength);
        file.read(&student.name[0], nameLength);

        file.read(reinterpret_cast<char*>(&student.id), sizeof(student.id));

        int fieldLength;
        file.read(reinterpret_cast<char*>(&fieldLength), sizeof(fieldLength));
        student.field.resize(fieldLength);
        file.read(&student.field[0], fieldLength);

        int subjectCount;
        file.read(reinterpret_cast<char*>(&subjectCount), sizeof(subjectCount));

        student.subjects.resize(subjectCount);
        for (Subject& subject : student.subjects) {
            int subNameLength;
            file.read(reinterpret_cast<char*>(&subNameLength), sizeof(subNameLength));
            subject.name.resize(subNameLength);
            file.read(&subject.name[0], subNameLength);
            
            file.read(reinterpret_cast<char*>(&subject.multiplier), sizeof(subject.multiplier));
            file.read(reinterpret_cast<char*>(&subject.score), sizeof(subject.score));
        }
    }

    file.close();
    return students;
}

#endif