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

float score_gen() {
        if (subjects.size() == 0) {
            return 0;
        }
        float score = 0;
        for (auto subject : subjects)
            score += subject.score * subject.multiplier;
        score /= subjects.size();

        return score;
    } float score = score_gen();
};


#endif