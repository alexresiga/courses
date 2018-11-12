#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "repository.h"
#include "observer.h"

class Controller: public Observable
{
private:
    Repository repo;
public:
    Controller();
    Controller(Repository repo): repo{repo}{}
    vector<Question> getAllQ() {return this->repo.getQ();}
    vector<Participant> getAllP() {return this->repo.getP();}
    void addQuestion(Question);
    void increaseS(Participant p, int i) {this->repo.increaseScore(p, i);}
};

#endif // CONTROLLER_H
