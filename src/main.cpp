#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

#include "data.hpp"
#include "file.hpp"

#define cls system("cls")
#define pause system("pause"); saveSt(students); break

using namespace std;

int menu ();

int main () {
    cout << "Welcome!\n";

    string name, field;
    int id, multiplier; float grade;
    Student student;
    Subject subject;
    vector <Student> students = loadSt(), temp{};
    bool did;

    while (1) {
        switch (menu()) {
            case 1:
                cls;
                cout << setw(15) << left << "ID" << setw(25) << "Name" << setw(15) << "Field" << "\n";
                cout << "------------------------------------------------------------\n";
                for (int i = 0; i < students.size(); i++) cout << setw(15) << left << students[i].id << setw(25) << students[i].name << setw(15) << students[i].field << "\n";
                cout << "------------------------------------------------------------\n\n";
                pause;
            case 2:
                cls;
                temp = students;
                for (int i = 0; i < temp.size() - 1; i++) for (int j = 0; j < temp.size() - i - 1; j++) if (scoreCalc(temp[j]) < scoreCalc(temp[j + 1])) swap(temp[j], temp[j + 1]);
                
                cout << setw(15) << left << "ID" << setw(25) << "Name" << setw(15) << "Field" << setw(6) << "Score" << "\n";
                cout << "------------------------------------------------------------\n";
                for (int i = 0; i < temp.size(); i++) cout << setw(15) << left << temp[i].id << setw(25) << temp[i].name << setw(15) << temp[i].field << setw(6) << scoreCalc(temp[i]) << "\n";
                cout << "------------------------------------------------------------\n\n";
                temp = {};
                pause;
            case 3:
                cls;
                cout << "Please enter the Studying Field that you want to list students of : ";
                cin >> field;
                cout << setw(15) << left << "ID" << setw(25) << "Name" << "\n";
                cout << "------------------------------------------------------------\n";
                for (int i = 0; i < students.size(); i++) if (students[i].field == field) cout << setw(15) << left << students[i].id << setw(25) << students[i].name << "\n";
                cout << "------------------------------------------------------------\n\n";
                pause;
            case 4:
                cls;
                cout << "Please enter ID of the student in question : "; cin >> id; did = false;
                for (int i = 0; i < students.size(); i++) if (students[i].id == id) {
                    cout << "\nActive Subjects of " << students[i].name << "\n";
                    cout << setw(20) << left << "Name" << setw(7) << "Credit" << setw(5) << "Grade" << "\n";
                    cout << "------------------------------------------------------------\n";
                    for (int j = 0; j < students[i].subjects.size(); j++) cout << setw(20) << left << students[i].subjects[j].name << setw(7) << students[i].subjects[j].multiplier << setw(5) << students[i].subjects[j].score << "\n";
                    did = true;
                }

                if (!did) cout << "\nStudent Not found\n"; else cout << "------------------------------------------------------------\n\n";
                pause;
            case 5:
                cls;
                student = {};
                did = false;

                cout << "Please Enter name of the student you want to register : ";
                cin.ignore();
                getline(cin, name);
                student.name = name;

                cout << "\nThe field this student studies at : ";
                getline(cin, field);
                student.field = field;

                Iid:
                cout << "\nStudent's ID : ";
                cin >> id;
                for (int i = 0; i < students.size(); i++) if (students[i].id == id) did = true;
                if (id != 0) student.id = id; else {
                    cout << "\nID cannot be 0, Try Again.\n";
                    goto Iid;
                }

                if (!did) students.push_back(student), cout << "\nStudent Registered.\n";
                else {
                    cout << "\nStudent with the ID " << id << " already exists, Try Again.\n";
                    goto Iid;
                }
                pause;
            case 6:
                cls;
                cout << "Please enter ID of the student in question : "; cin >> id; did = false;
                for (int i = 0; i < students.size(); i++) if (students[i].id == id) {
                    subject = {};

                    cout << "\nName of Subject you want to assign to "<< students[i].name <<" : ";
                    cin.ignore();
                    getline(cin, name);
                    subject.name = name;

                    cout << "\nIts credit : ";
                    cin >> multiplier;
                    subject.multiplier = multiplier;

                    cout << "\nIts Grade (0 to enter a random number) : ";
                    cin >> grade;
                    if (!grade) subject.score = scoreRand(); else subject.score = grade;

                    students[i].subjects.push_back(subject);
                    
                    cout << "\nSubject " << name << " is assigned to " << students[i].name << "\n";

                    did = true;
                }

                if (!did) cout << "\nStudent Not found\n";
                pause;
            case 7:
                cls;
                cout << "Please enter ID of the student in question : "; cin >> id; did = false;
                for (int i = 0; i < students.size(); i++) if (students[i].id == id) {
                    cout << "What do you want to do with " << students[i].name << "\n1 - Delete\n2 - Rewrite Info\n";
                    cin >> grade;
                    if (grade == 1) {
                        cout << "Are you sure ? (y/N) ";
                        cin >> name;
                        if (name == "Y" || name == "Yes" || name == "y" || name == "yes") students.erase(students.begin() + i), cout << "\nRemoved.\n";
                        else cout << "\nAbort.\n";
                    } else if (grade == 2) {
                        cout << "\nPlease Enter name of the student you want to register : ";
                        cin.ignore();
                        getline(cin, name);
                        students[i].name = name;

                        cout << "\nThe field this student studies at : ";
                        getline(cin, field);
                        students[i].field = field;

                        cout << "\nChanges Done.\n";
                    } else cout << "\nAbort.\n";

                    did = true;
                }

                if (!did) cout << "\nStudent Not found\n";
                pause;
            case 8:
                cls;
                cout << "Please enter ID of the student in question : "; cin >> id; did = false;
                for (int i = 0; i < students.size(); i++) if (students[i].id == id) {
                    cout << "\nActive Subjects of " << students[i].name << "\n";
                    cout << "------------------------------------------------------------\n";
                    cout << setw(20) << left << "Name" << setw(7) << "Credit" << setw(5) << "Grade" << "\n";
                    for (int j = 0; j < students[i].subjects.size(); j++) cout << setw(20) << left << students[i].subjects[j].name << setw(7) << students[i].subjects[j].multiplier << setw(5) << students[i].subjects[j].score << "\n";
                    did = true;
                    cout << "------------------------------------------------------------\n\nPlease Enter name of the subject you want to modify : "; cin >> name;
                    id = 0;
                    for (int j = 0; j < students[i].subjects.size(); j++) if (students[i].subjects[j].name == name) {
                        cout << "\n What action you want to perform on the subject " << students[i].subjects[j].name << " assigned to " << students[i].name << "?\n1 - Delete\n2 - Rewrite Info\n3 - Change Grade\n";
                        id++;
                        cin >> grade;
                        if (grade == 1) {
                            cout << "Are you sure ? (y/N) ";
                            cin >> name;
                            if (name == "Y" || name == "Yes" || name == "y" || name == "yes") students[i].subjects.erase(students[i].subjects.begin() + j), cout << "\nRemoved.\n";
                            else cout << "\nAbort.\n";
                            break;
                        } else if (grade == 2) {
                            subject = {};

                            cout << "\nNew Name of the Subject : ";
                            cin.ignore();
                            getline(cin, name);
                            subject.name = name;

                            cout << "\nIts credit : ";
                            cin >> multiplier;
                            subject.multiplier = multiplier;

                            cout << "\nIts Grade (0 to enter a random number) : ";
                            cin >> grade;
                            if (!grade) subject.score = scoreRand(); else subject.score = grade;

                            students[i].subjects[j] = subject;

                            cout << "\nChanges Done.\n";
                        } else if (grade == 3) {
                            cout << "\nNew Grade to Assign : ";
                            cin >> grade;

                            students[i].subjects[j].score = grade;

                            cout << "\nChanges Done.\n";
                        }else cout << "\nAbort.\n";
                    }

                    if (!id) cout << "\nSubject Not found\n";
                }

                if (!did) cout << "\nStudent Not found\n";
                pause;
            case 9:
                cls;
                cout << "These Options are Dangerous, Can Overwrite data, Proceed with caution!\n\n1 - Insert Randomized Scores for all Subjects of all Students\n2 - Reset Database (Remove Everything)\n3 - Reset all Subjects\n\n4 - Save\n";
                cin >> id;
                switch (id) {
                    case 1:
                        cout << "Are you sure ? This Action overwrites every saved score and cannot be recovered. (y/N) ";
                        cin >> name;
                        if (name == "Y" || name == "Yes" || name == "y" || name == "yes") {
                            for (int i = 0; i < students.size(); i++) for (int j = 0; j < students[i].subjects.size(); j++) students[i].subjects[j].score = scoreRand(students[i].subjects[j].multiplier * students[i].subjects[j].name[0] * time(nullptr));
                            cout << "\nChanges Done.\n";
                        }
                        else cout << "\nAbort.\n";
                        break;
                    case 2:
                        cout << "Are you sure ? This Action Removes all registered students and assigned subjects from the database and cannot be recovered. (y/N) ";
                        cin >> name;
                        if (name == "Y" || name == "Yes" || name == "y" || name == "yes") students = {}, remove("students.dat"), cout << "\nAll Data Reset.\n";
                        else cout << "\nAbort.\n";
                        break;
                    case 3:
                        cout << "Are you sure ? This Action Removes all assigned subjects from the database and cannot be recovered. (y/N) ";
                        cin >> name;
                        if (name == "Y" || name == "Yes" || name == "y" || name == "yes") for (int i = 0; i < students.size(); i++) students[i].subjects = {}, cout << "\nAll Subjects Reset.\n";
                        else cout << "\nAbort.\n";
                        break;
                    case 4:
                        saveSt(students);
                        cout << "\nChanges Saved.\n";
                        break;
                    default:
                        cout << "Abort.\n";
                }
                pause;
            default:
                saveSt(students);
                exit(0);
        }
        cls;
    }
}

int menu() {
    cout << "Please type the number associated with action you want to perform : \n1 - List students\n2 - Sort and List students by Score\n3 - Filter and List students by Studying Field\n4 - List Subjects of an Student\n5 - Register a new Student\n6 - Assign a new Subject\n7 - Edit Students\n8 - Edit Subjects\n\n9 - Database Management\n\nType any other character to save and exit ...\n";
    int i;
    cin >> i;
    return i;
}