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
bool isNumber (const string&);

int main () {
    cout << "Welcome!\n";

    string name, field, input;
    int id, multiplier;
    float grade;
    bool did;

    Student student;
    Subject subject;

    vector <Student> students = loadSt(), temp{};
    
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
                if (!students.size()) {
                    cout << "No Students Registered.\n\n";
                    pause;
                }
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
                cout << "Please enter ID of the student to issue : ";
                
                I4id:
                cin >> input;
                if (isNumber(input)) id = stoi(input); else {cout << "Invalid Input. Please Enter Again. \n"; goto I4id;}

                did = false;

                
                for (int i = 0; i < students.size(); i++) if (students[i].id == id) {
                    cls;
                    grade = i;
                    cout << "Report Card of Student : \n------------------------------------------------------------\n ID: "<< students[i].id << "\n Name: " << students[i].name << "\n Studying Field: " << students[i].field << "\n Active Subjects:\n------------------------------------------------------------\n";
                    cout << " " << setw(20) << left << "Name" << setw(7) << "Credit" << setw(5) << "Grade" << "\n";
                    for (int j = 0; j < students[i].subjects.size(); j++) cout << " " << setw(20) << left << students[i].subjects[j].name << setw(7) << students[i].subjects[j].multiplier << setw(5) << students[i].subjects[j].score << "\n";
                    did = true;
                }

                if (!did) cout << "\nStudent Not found\n"; else cout << "\n Overall Score : " << scoreCalc(students[grade]) <<"\n------------------------------------------------------------\n\n";
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
                cin >> input;
                if (isNumber(input)) id = stoi(input); else {cout << "Invalid Input. Please Enter Again. \n"; goto Iid;}

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
                cout << "Please enter ID of the student in question : ";
                
                I6id:
                cin >> input;
                if (isNumber(input)) id = stoi(input); else {cout << "Invalid Input. Please Enter Again. \n"; goto I6id;}
                
                did = false;
                for (int i = 0; i < students.size(); i++) if (students[i].id == id) {
                    subject = {};

                    cout << "\nName of Subject you want to assign to "<< students[i].name <<" : ";
                    cin.ignore();
                    getline(cin, name);
                    subject.name = name;

                    cout << "\nIts credit : ";
                    
                    I6multiplier:
                    cin >> input;
                    if (isNumber(input)) multiplier = stoi(input); else {cout << "Invalid Input. Please Enter Again. \n"; goto I6multiplier;}

                    subject.multiplier = multiplier;

                    Igrade:
                    cout << "\nIts Grade (0 to enter a random number) : ";
                    cin >> input;
                    if (isNumber(input)) grade = stof(input); else {cout << "Invalid Input. Please Enter Again. \n"; goto Igrade;}
                    
                    if (!grade) subject.score = scoreRand(); else if (grade < 0 || grade > 20) {
                        cout << "Invalid Input. Please Enter Again. \n";
                        goto Igrade;
                    } else subject.score = grade;

                    students[i].subjects.push_back(subject);
                    
                    cout << "\nSubject " << name << " is assigned to " << students[i].name << "\n";

                    did = true;
                }

                if (!did) cout << "\nStudent Not found\n";
                pause;
            case 7:
                cls;
                cout << "Please enter ID of the student in question : ";
                
                I7id:
                cin >> input;
                if (isNumber(input)) id = stoi(input); else {cout << "Invalid Input. Please Enter Again. \n"; goto I7id;}
                
                did = false;
                for (int i = 0; i < students.size(); i++) if (students[i].id == id) {
                    cout << "What do you want to do with " << students[i].name << "\n1 - Delete\n2 - Rewrite Info\n";
                    I7g:
                    cin >> input;
                    if (isNumber(input)) grade = stoi(input); else {cout << "Invalid Input. Please Enter Again. \n"; goto I7g;}
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
                cout << "Please enter ID of the student in question : ";

                I8id:
                cin >> input;
                if (isNumber(input)) id = stoi(input); else {cout << "Invalid Input. Please Enter Again. \n"; goto I8id;}
                
                did = false;
                for (int i = 0; i < students.size(); i++) if (students[i].id == id) {
                    cout << "\nActive Subjects of " << students[i].name << "\n";
                    cout << "------------------------------------------------------------\n";
                    cout << setw(20) << left << "Name" << setw(7) << "Credit" << setw(5) << "Grade" << "\n";
                    for (int j = 0; j < students[i].subjects.size(); j++) cout << setw(20) << left << students[i].subjects[j].name << setw(7) << students[i].subjects[j].multiplier << setw(5) << students[i].subjects[j].score << "\n";
                    did = true;
                    cout << "\n------------------------------------------------------------\n\nPlease Enter name of the subject you want to modify : "; cin >> name;
                    id = 0;
                    for (int j = 0; j < students[i].subjects.size(); j++) if (students[i].subjects[j].name == name) {
                        cout << "\n What action you want to perform on the subject " << students[i].subjects[j].name << " assigned to " << students[i].name << "?\n1 - Delete\n2 - Rewrite Info\n3 - Change Grade\n";
                        id++;
                        
                        I8g:
                        cin >> input;
                        if (isNumber(input)) grade = stoi(input); else {cout << "Invalid Input. Please Enter Again. \n"; goto I8g;}

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
                            
                            I8multiplier:
                            cin >> input;
                            if (isNumber(input)) multiplier = stoi(input); else {cout << "Invalid Input. Please Enter Again. \n"; goto I8multiplier;}

                            subject.multiplier = multiplier;

                            cout << "\nIts Grade (0 to enter a random number) : ";
                            
                            I8grade:
                            cin >> input;
                            if (isNumber(input)) grade = stoi(input); else {cout << "Invalid Input. Please Enter Again. \n"; goto I8grade;}


                            if (!grade) subject.score = scoreRand(); else if (grade < 0 || grade > 20) {
                                cout << "Invalid Input. Please Enter Again. \n";
                                goto I8grade;
                            } else subject.score = grade;

                            students[i].subjects[j] = subject;

                            cout << "\nChanges Done.\n";
                        } else if (grade == 3) {
                            cout << "\nNew Grade to Assign : ";
                            
                            I8grade2:
                            cin >> input;
                            if (isNumber(input)) grade = stof(input); else {cout << "Invalid Input. Please Enter Again. \n"; goto I8grade2;}
                            
                            if (grade < 0 || grade > 20) {
                                cout << "Invalid Input. Please Enter Again. \n";
                                goto I8grade2;
                            } else students[i].subjects[j].score = grade;

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
                
                I9id:
                cin >> input;
                if (isNumber(input)) id = stoi(input); else {cout << "Invalid Input. Please Enter Again. \n"; goto I9id;}

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
                        if (name == "Y" || name == "Yes" || name == "y" || name == "yes") {
                            for (int i = 0; i < students.size(); i++) students[i].subjects = {};
                            cout << "\nAll Subjects Reset.\n";
                        } else cout << "\nAbort.\n";
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
                cls;
                saveSt(students);
                cout << "Changes Saved.\n";
                system("pause");
                exit(0);
        }
        cls;
    }
}

int menu() {
    cout << "Please type the number associated with action you want to perform : \n1 - List students\n2 - Sort and List students by Score\n3 - Filter and List students by Studying Field\n4 - Issue Report Card of a Student\n5 - Register a new Student\n6 - Assign a new Subject\n7 - Edit Students\n8 - Edit Subjects\n\n9 - Database Management\n\nType any other character to save and exit ...\n";
    int i; string input;
    
    I:
    cin >> input;
    if (isNumber(input)) i = stoi(input); else {cout << "Invalid Input. Please Enter Again. \n"; goto I;}
    
    return i;
}

bool isNumber(const string& s) {
    int d = 0;
    for (char c : s) if (!isdigit(c) && c != '.') return false; else if (c == '.') d++;
    
    if (s[0] == '.' || s[s.length() - 1] == '.') return false;
    if (d == s.length()) return false;

    return true;
}