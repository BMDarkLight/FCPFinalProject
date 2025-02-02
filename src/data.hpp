#ifdef DATA_HPP
#else
#define DATA_HPP

#include <ctime>
#include <cstdlib>

using namespace std;

struct Subject {
    short multiplier;
    string name;
    float score = 0;
};

struct Student {
    string name;
    int id;
    string field;
    vector <Subject> subjects;
};

float scoreCalc(const Student &student) {
    vector <Subject> subjects = student.subjects; float score = 0; int n = 0;

    if (!subjects.size()) return 0;
    for (int i = 0; i < subjects.size(); i++) score += subjects[i].score * subjects[i].multiplier, n += subjects[i].multiplier;

    score /=n;

    return score;
}

float scoreRand(int seed = time(nullptr)) {
    srand(seed);
    return (rand() % 100) / 5.0;
}

#endif