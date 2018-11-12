#include "repository.h"
#include <string>
#include <fstream>
#include <iostream>
Repository::Repository()
{

}

void Repository::readQuestions()
{
    ifstream f;
        f.open(this->qname);
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
            Question q{stoi(v[0]), v[1], v[2], stoi(v[3])};
            this->questions.push_back(q);
        }
        f.close();
}


void Repository::readParticipants()
{
    ifstream f;
        f.open(this->pname);
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
            Participant p{v[0], stoi(v[1])};
            this->participants.push_back(p);
        }
        f.close();
}

void Repository::write()
{
    ofstream g(this->qname);
    for(auto q: this->getQ())
        g<<q<<endl;
}


