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
    vector <Subject> subjects;
};

struct Data {
    void listStudents () {
        
    };
    void registerStudent (string name, int id, string field = "Computer Engineering") {

    };
    void removeStudent (Student student) {

    };
    void addSubject (Subject subject)  {

    };
    Student findStudent (int id) {

    };
};



#endif