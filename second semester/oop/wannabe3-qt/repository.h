#ifndef REPOSITORY_H
#define REPOSITORY_H
#include <vector>
#include "question.h"
#include "participant.h"

using namespace std;

class Repository
{
private:
    vector<Question> questions;
    vector<Participant> participants;
    string qname;
    string pname;
public:
    Repository();
    Repository(string qn, string pn): qname{qn}, pname{pn} {this->readParticipants();this->readQuestions();}

    vector<Question> getQ() {sort(this->questions.begin(), this->questions.end(), [](Question a, Question b){return a.getID() < b.getID();});return this->questions;}
    vector<Participant> getP() {return this->participants;}
    void readQuestions();
    void readParticipants();
    void addQ(Question q) {this->questions.push_back(q);}
    void write();
    void increaseScore(Participant p, int i) {p.setScore(i);}
};

#endif // REPOSITORY_H
