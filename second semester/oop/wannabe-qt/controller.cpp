#include "controller.h"

Controller::Controller()
{
    this->readFromFile("in.txt");
}

void Controller::add(const int& id, const string& name)
{
    Elem e{id, name};
    this->elems.push_back(e);
}

vector<Elem> Controller::filter(const string & filter)
{
    vector<Elem> good;
    for(auto e: this->getAll())
    {
        if (atoi(filter.c_str()) == e.getID()) good.push_back(e);
    }

    return good;
}


void Controller::remove_element(const int & idx)
{
   int i = 0;
   while (i < this->elems.size())

        if (this->elems[i].getID() == idx)
            this->elems.erase(this->elems.begin()+i);
        else i++;

}

void Controller::readFromFile(const string & filename)
{
    ifstream f(filename);
    Elem e{};
    while(f>>e)
        this->elems.push_back(e);
    f.close();
}
