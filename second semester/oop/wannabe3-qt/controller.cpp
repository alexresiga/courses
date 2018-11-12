#include "controller.h"

Controller::Controller()
{
    this->notify();
}

void Controller::addQuestion(Question q)
{
    if (q.getText() == "")
        throw runtime_error("empty text");
    for (auto ques: this->getAllQ())
        if (q.getID() == ques.getID())
                throw runtime_error("existing question");
    this->repo.addQ(q);
    this->repo.write();
    this->notify();
}
