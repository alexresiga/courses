#ifndef TASK_H
#define TASK_H
#include <string.h>
#include <sstream>

using namespace std;

class Task
{
private:
    string description;
    int duration;
    int priority;
public:
    Task();
    Task(const string& d, const int& du, const int& p): description{d}, duration{du}, priority{p} {}
    string getDesc() const {return this->description;}
    int getPrior() const {return this->priority;}
    int getDuration() const {return this->duration;}
    string toString(){stringstream res; res<<this->getDesc()<<" -> "<<this->getPrior(); return res.str();}

};

#endif // TASK_H
