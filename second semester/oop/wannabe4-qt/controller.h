#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "observer.h"
#include "sourcefile.h"
#include "member.h"
using namespace std;
class Controller: public Observable
{

private:
    vector<Member> members;
    vector<SourceFile> files;
public:
    Controller();
    void readMembers();
    void readFiles();
    vector<SourceFile> getFiles() {return this->files;}
    vector<Member> getMembers() {return this->members;}
    Member find(string name);
    void addFile(string name, string creator);
    void revise(string name, string person);
    SourceFile findF(string name);

};

#endif // CONTROLLER_H
