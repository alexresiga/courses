#ifndef PARTICIPANT_H
#define PARTICIPANT_H
#include <string>
using namespace std;

class Participant
{
private:
    string name;

    int score;
public:
    Participant();
    Participant(string name, int score):name{name}, score{score} { score = 0;}
    string getName(){return this->name;}
    int getScore(){return this->score;}
    void setScore(int i) {this->score+=i;}
};

#endif // PARTICIPANT_H
