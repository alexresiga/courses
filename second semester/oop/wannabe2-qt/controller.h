#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <task.h>
#include <vector>

class Controller
{
private:
    string filename;
    vector<Task> tasks;

public:
    Controller();
    Controller(const string& _filename): filename{_filename} {this->readFromFile();}
    vector<Task> getRepo() {return this->tasks;}
    vector<Task> getByPriority();
    void readFromFile();
    int compute(int);

};

#endif // CONTROLLER_H
