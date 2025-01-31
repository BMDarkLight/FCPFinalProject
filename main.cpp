#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

#include "data.hpp"
#include "file.hpp"

using namespace std;

int menu ();

int main () {
    cout << "Welcome!\n";

    string name, field;
    int id, grade, multiplier;
    Student student;
    Subject subject;
    vector <Student> students = loadSt();
    while (1) {
        switch (menu()) {
            case 1:
                cout << "ID\tName\tField\n";
                for (int i = 0; i < students.size(); i++) cout << students[i].id << "\t" << students[i].name << "\t" << students[i].field << "\n";
                break;
            case 2:
                break;// SORT BY GRADE
            case 3:
                cout << "\nPlease enter ID of the student in question : \n"; int id; cin >> id;
                for (int i = 0; i < students.size(); i++) if (students[i].id == id) {
                    cout << "Active Subjects of " << students[i].name << "\n";
                    cout << "Name\tMultiplier\tGrade\n";
                    for (int j = 0; j < students[i].subjects.size(); j++) cout << students[i].subjects[j].name << "\t" << students[i].subjects[j].multiplier << "\t" << students[i].subjects[j].score << "\n";
                }
                break;
            case 4:
                student = {};

                cout << "\nPlease Enter name of the student you want to register : ";
                cin >> name;
                student.name = name;

                cout << "\nThe field this student studies at : ";
                cin >> field;
                student.field = field;

                cout << "\nStudent's ID : ";
                cin >> id;
                student.id = id;

                students.push_back(student);

                cout << "\nStudent Registered.\n";
                break;
            case 5:
                cout << "\nPlease enter ID of the student in question : "; cin >> id;
                for (int i = 0; i < students.size(); i++) if (students[i].id == id) {
                    subject = {};

                    cout << "\nName of Subject you want to assign : ";
                    string name; cin >> name;
                    subject.name = name;

                    cout << "\nIts credit : ";
                    cin >> multiplier;
                    subject.multiplier = multiplier;

                    cout << "\nIts Grade (default = 0) : ";
                    cin >> grade;
                    subject.score = grade;

                    students[i].subjects.push_back(subject);
                    
                    cout << "\nSubject " << name << " is assigned to " << students[i].name << "\n";
                }
                break;
            case 6:
                // Edit STU
                break;
            case 7:
                // EDIT SUB
                break;
            default: 
                saveSt(students);
                exit(0);
        }
    }
}

int menu() {
    cout << "Please type the number associated with action you want to perform : \n1 - List students\n2 - Sort and List students by Score\n3 - List Subjects of an Student\n4 - Register a new Student\n5 - Assign a new Subject\n6 - Edit Students\n7 - Edit Subjects\n\nType any other character to save and exit ...\n";
    int i;
    cin >> i;
    return i;
}