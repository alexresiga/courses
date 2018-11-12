#ifndef QUESTION_H
#define QUESTION_H
#include <string>
#include <vector>
#include <sstream>
#include <ostream>

using namespace std;
class Question
{
private:
    int id;
    string text;
    string correct;
    int score;
public:
    Question() {}
    Question(int id, string text, string c, int s): id{id}, text{text}, correct{c}, score{s} {}
    int getID() const {return this->id;}
    string getCorrect() const{return this->correct;}
    int getScore() const{return this->score;}
    string getText() const{return this->text;}
    string toString() {ostringstream res; res<<this->id<<" "<<this->text<<" "<<this->correct<<" "<<this->score; return res.str();}
    friend ostream& operator<<(ostream& os, const Question& q)
    {
        os<<q.getID()<<"|"<<q.getText()<<"|"<<q.getCorrect()<<"|"<<q.getScore();
        return os;
    }

};

#endif // QUESTION_H
