#ifndef ANSWER_H
#define ANSWER_H
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

class Answer
{
private:
    int id;
    int Qid;
    string name;
    string text;
    int votes;

public:
    Answer();
    Answer(int id, int q, string name, string t, int v): id{id}, Qid{q}, name{name}, text{t}, votes{v}{}
    int getQID() {return this->Qid;}
    string toString() {ostringstream res; res<<this->id<<"-"<<Qid<<"-"<<name<<"-"<<this->text<<"-"<<this->votes; return res.str();}
    int getVotes() {return this->votes;}
    string getName() {return this->name;}
    int getID() {return this->id;}
    void setVotes(int i) {this->votes = i;}
    friend ofstream& operator<<(ofstream& os, const Answer& a) {os<<a.id<<"|"<<a.Qid<<"|"<<a.name<<"|"<<a.text<<"|"<<a.votes; return os;}

};

#endif // ANSWER_H
