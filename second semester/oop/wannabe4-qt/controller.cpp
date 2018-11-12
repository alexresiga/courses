#include "controller.h"
#include <fstream>
#include <iostream>


Controller::Controller()
{
   this->files = vector<SourceFile>();
   this->readMembers();
   this->readFiles();

}

Member Controller::find(string name)
{
    for(auto a: this->getMembers())
        if (a.getName() == name)
            return a;
    return Member{"", -1, -1};
}

void Controller::addFile(string name, string creator)
{
    if (name =="")
        throw runtime_error("empty name");
    for(auto f: this->files)
        if (f.getName() == name)
            throw runtime_error("existing file");
    SourceFile s{name, "not_revised", this->find(creator), Member{"", -1, -1}};
    this->files.push_back(s);
    this->notify();
}

void Controller::revise(string name, string person)
{
    for(SourceFile& s: this->files)
        if (s.getName() == name)
        {
            s.setRevised();
            s.setReviewer(this->find(person));
        }

    this->notify();
}

void Controller::readFiles()
{
    ifstream f;
    f.open("s.txt");
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
        token = strtok(&line[0], "|");
        while (token != NULL)
        {
            v.push_back(token);
            token = strtok(NULL, "|");
        }
        SourceFile f{v[0], v[1], this->find(v[2]), this->find(v[3])};
        this->files.push_back(f);
    }
    f.close();

}

void Controller::readMembers()
{
    ifstream f;
    f.open("m.txt");
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
        token = strtok(&line[0], "|");
        while (token != NULL)
        {
            v.push_back(token);
            token = strtok(NULL, "|");
        }
        Member m{v[0], stoi(v[1]), stoi(v[2])};
        this->members.push_back(m);
    }
    f.close();

}
