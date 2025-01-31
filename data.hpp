#ifdef DATA_HPP
#else
#define DATA_HPP

using namespace std;

struct Subject {
    short multiplier;
    string name;
    short score;
};
struct Student {
    string name;
    int id;
    string field;
    vector <Subject*> subjects;
};

struct Data {
    void listStudents () {for (int i = 0; i < students.size(); i++) cout << students[i].id << "\t" << students[i].name << "\t" << students[i].field << endl;};

    void registerStudent (string name, int id, string field = "Computer Engineering") {
        students.push_back({name, id, field, {}});
    };

    void removeStudent (Student student) {

    };

    void addSubject (Subject subject, Student student)  {student.subjects.push_back(&subject);};

    /*Student findStudent (int id) {

    };*/

    vector <Student> students;
    vector <Subject> subjects;
};

#endif