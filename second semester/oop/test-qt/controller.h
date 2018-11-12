#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "document.h"
#include "assert.h"

class Controller
{
private:
    vector<Document> documents;
    string filename;

public:
    Controller();
    Controller(string f): filename{f} {this->readFromFile();}
    vector<Document> getAll() {return this->documents;}
    void readFromFile();
    /*
      Description: compute best matching document for given string
      Input:  string s -from query
      Output: Document best_match -> best match document
     */
    double similarity(string, string);
    Document computeBestMatch(string);

    void testBestMatch();
};

#endif // CONTROLLER_H
