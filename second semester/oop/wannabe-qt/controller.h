#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <vector>
#include <elem.h>

class Controller
{

private:
    vector<Elem> elems;
public:
    Controller();
    void add(const int&, const string&);
    vector<Elem> getAll() {return this->elems;}
    vector<Elem> filter(const string&);
    void remove_element(const int&);
    void readFromFile(const string&);
};

#endif // CONTROLLER_H
