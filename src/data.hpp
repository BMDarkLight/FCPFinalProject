#ifdef DATA_HPP
#else
#define DATA_HPP

using namespace std;

struct Subject {
    short multiplier;
    string name;
    short score = 0;
};

struct Student {
    string name;
    int id;
    string field;
    vector <Subject> subjects;
};
#endif