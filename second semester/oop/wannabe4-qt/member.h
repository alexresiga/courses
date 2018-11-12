#ifndef MEMBER_H
#define MEMBER_H
#include <string>
#include <sstream>
using namespace std;

class Member
{
private:
    string name;
    int number;
    int total;
public:
    Member();
    Member(string n, int a, int b): name{n}, number{a}, total{b}{}
    string toString() {ostringstream res;if (this->name == "") res<<"None"; else res<<this->name<<"-"<<this->number<<"-"<<this->total; return res.str();}
    string getName() {return this->name;}
    int getNumber() {return this->number;}
    int getTotal() {return this->total;}
    void increase() {this->number++;}
};

#endif // MEMBER_H
