#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "user.h"
#include <question.h>
#include <answer.h>
#include "observer.h"

class Controller: public Observable
{
private:
    vector<User> users;
    vector<Question> questions;
    vector<Answer> answers;
public:
    Controller(){this->readUsers();this->readQ();this->readA();}
    void readUsers();
    void readQ();
    void readA();
    vector<User> getU(){return this->users;}
    vector<Question> getQ() {return this->questions;}
    vector<Answer> getA() {return this->answers;}
    Question findQ(int id);
    vector<Question> search(string s);
    string topThree(Question q);
    double similarity(string a, string b);
    /*
     * DEsc: adds new question
     * Input: string text, string name
     * Output: the created question was added to the question vector
     * Throws runtime_error if text is empty
     */
    void addQ(string text, string name);
    void testAdd();
    /*
     * DESc: return all answers for a question
     * Input: id of question
     * Output:vector of all answers for that questions
     */
    vector<Answer> showAnswers(int id);
    void testShow();
    void addA(int, string, string);
    void writeToFile();

    void increase(int id, int i);
};

#endif // CONTROLLER_H
