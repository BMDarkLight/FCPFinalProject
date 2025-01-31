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
    vector <Student> students;
    vector <Subject> subjects;
};

#endif