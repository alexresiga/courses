#ifndef SOURCEFILE_H
#define SOURCEFILE_H
#include <string>
#include "member.h"
class SourceFile
{
private:
    string name;
    string status;
    Member creator;
    Member reviewer;
public:
    SourceFile();
    SourceFile(string n, string s, Member a, Member b): name{n}, status{s}, creator{a}, reviewer{b} {}
    string toString() {ostringstream res; res<<this->name<<"-"<<this->status<<"-"<<this->creator.toString()<<"-"<<this->reviewer.toString(); return res.str();}
    bool isRevised() {return this->status == "revised";}
    string getName() {return this->name;}
    void setRevised() {this->status = "revised";}
    void setReviewer(Member m) {this->reviewer = m;}
};

#endif // SOURCEFILE_H
