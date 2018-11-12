#include "controller.h"
#include <fstream>
#include <iostream>

void Controller::readFromFile()
{
    ifstream f;
    f.open("in.txt");
    if (!f.is_open())
        cout<<"The file could not be opened!";
    else
    while(!f.eof())
    {
        string line;
        getline(f, line);
        if (line == "")
            return;
        vector<string> v;
        char* token;
        token = strtok(&line[0], " ");
        while (token != NULL)
        {
            v.push_back(token);
            token = strtok(NULL, " ");
        }
        Task t{v[0], stoi(v[1]), stoi(v[2])};
        this->tasks.push_back(t);
    }
    f.close();
}

vector<Task> Controller::getByPriority()
{
     vector<Task> sorted = this->getRepo();
     sort(sorted.begin(), sorted.end(), [](Task a, Task b){return a.getPrior() < b.getPrior();});

     return sorted;
}

int Controller::compute(int pr)
{
    int sum = 0;
    for (auto t: this->tasks)
    {
        if (t.getPrior() == pr) sum+=t.getDuration();
    }
    return sum;
}
