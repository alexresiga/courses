#ifndef ELEM_H
#define ELEM_H
#include <string>
#include <sstream>

using namespace std;
class Elem
{
protected:
    int id;
    string name;
public:
    Elem();
    Elem(int id, string name): id{id}, name{name} {}
    string toString() {ostringstream s; s<<this->id<<": "<<this->name; return s.str();}
    int getID() const {return this->id;}
    friend ifstream& operator>>(ifstream& in, const Elem& e);

};

#endif // ELEM_H
