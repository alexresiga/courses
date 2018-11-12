#ifndef QUESTION_H
#define QUESTION_H
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

class Question
{
private:
    int id;
    string text;
    string name;
public:
    Question();
    Question(int id, string text, string name): id{id}, text{text}, name{name} {}
    string toString(){ostringstream res; res<<this->id<<"-"<<this->name<<"-"<<this->text; return res.str();}
    int getID() {return this->id;}
    string getText() {return this->text;}
    friend ofstream& operator<<(ofstream& os, const Question& q) {os<<q.id<<"|"<<q.text<<"|"<<q.name; return os;}
};

#endif // QUESTION_H
