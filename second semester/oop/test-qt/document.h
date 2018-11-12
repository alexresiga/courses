#ifndef DOCUMENT_H
#define DOCUMENT_H
#include <string>
#include <vector>
#include <sstream>

using namespace std;
class Document
{
protected:
    string name;
    string keywords;
    string content;

public:
    Document();
    Document(string name, string keywords, string cont) : name{name}, keywords{keywords}, content{cont} {}
    string toString() {ostringstream res; res<<this->name<<"-> "<<this->keywords<<"\n"; return res.str();}
    string getName() {return this->name;}
    string getKeyW() {return this->keywords;}

};

#endif // DOCUMENT_H
