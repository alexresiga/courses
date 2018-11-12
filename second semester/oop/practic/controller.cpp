#include "controller.h"
#include <fstream>
#include <iostream>
#include <assert.h>

void Controller::readUsers()
{
    ifstream f;
    f.open("u.txt");
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
        User u{v[0]};
        this->users.push_back(u);
    }
    f.close();

}

void Controller::readQ()
{
    ifstream f;
    f.open("q.txt");
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
        Question q{stoi(v[0]), v[1], v[2]};
        this->questions.push_back(q);
    }
    f.close();

}

void Controller::readA()
{
    ifstream f;
    f.open("a.txt");
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
        Answer a{stoi(v[0]), stoi(v[1]), v[2], v[3], stoi(v[4])};
        this->answers.push_back(a);
    }
    f.close();

}

Question Controller::findQ(int id)
{
    for(auto a: this->questions)
        if (a.getID() == id)
            return a;
}

double Controller::similarity(string a, string b)
{
    double s = 0;
    for(int i = 0 ; i < min(a.size(), b.size()); ++i)
        if (a[i] == b[i]) s++;

    return s;
}

vector<Question> Controller::search(string s)
{
    vector<pair<Question, double>> pairs;
    for(auto a: this->questions)
        pairs.push_back(make_pair(a, similarity(a.getText(),s)));
    sort(pairs.begin(), pairs.end(), [](pair<Question, double> a, pair<Question, double> b){return a.second > b.second;});
    vector<Question> result;
    for(auto p: pairs)
        result.push_back(p.first);
    return result;
}

string Controller::topThree(Question q)
{
    ostringstream res;
    res<<q.toString()<<"\n";
    vector<Answer> ans = this->getA();
    sort(ans.begin(), ans.end(), [](Answer a, Answer b){return a.getVotes() > b.getVotes();});
    for(auto a: this->answers)
        if (a.getQID() == q.getID())
            res<<"\t"<<a.toString()<<"\n";
    return res.str();

}

void Controller::addQ(string text, string name)
{
    if (text == "")
        throw runtime_error("empty name");
    Question q{this->questions.back().getID()+1, text, name};
    this->questions.push_back(q);
    this->notify();
    this->writeToFile();
}
void Controller::testAdd()
{

    Controller ctrl{};
    Question q{1, "text", "name"};
    assert(ctrl.getQ().size() == 3);
    ctrl.addQ("text", "name");
    assert(ctrl.getQ().size() == 4);
}

vector<Answer> Controller::showAnswers(int id)
{
    vector<Answer> result;
    for(auto a: this->answers)
        if (a.getQID() == id)
            result.push_back(a);
    return result;
}

void Controller::testShow()
{
    Controller ctrl{};
    assert(ctrl.showAnswers(1).size() == 2);
    assert(ctrl.showAnswers(2).size() == 4);
}

void Controller::addA(int id, string text, string name)
{
    if (text == "")
        throw runtime_error("empty text");
    Answer a{this->answers.back().getID()+1, id, name, text, 0};
    this->answers.push_back(a);
    this->writeToFile();
    this->notify();
}

void Controller::writeToFile()
{
    ofstream g("q.txt");
    for(auto q: this->questions)
        g<<q<<"\n";
    g.close();

    ofstream h("a.txt");
    for(auto a: this->answers)
        h<<a<<"\n";
    h.close();
}

void Controller::increase(int id, int i)
{
    for(auto a: this->answers)
        if (a.getID() == id)
            a.setVotes(i);
}
