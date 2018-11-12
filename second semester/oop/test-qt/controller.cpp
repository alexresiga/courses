#include "controller.h"
#include <fstream>
#include <iostream>
#include "utility"
#include <string>

Controller::Controller()
{

}

void Controller::readFromFile()
{
    ifstream f;
    f.open("in.txt");
    if (!f.is_open())
        cout<<"The file could not be opened!";
    else
    while(!f.eof())
    {
        string line;
        getline(f, line);
        if (line == "")
            return;
        vector<string> v;
        char* token;
        token = strtok(&line[0], "|");
        while (token != NULL)
        {
            v.push_back(token);
            token = strtok(NULL, "|");
        }
        Document t{v[0], v[1], v[2]};
        this->documents.push_back(t);
    }
    f.close();
}

double Controller::similarity(string a, string b)
{

   if (b.find(a) != string::npos)
        return (double)a.length()/b.length();
    return 0;
}

Document Controller::computeBestMatch(string s)
{
    vector<pair<Document, double>> pairs;
    for(auto d: this->documents)
    {
        pairs.push_back(make_pair(d, this->similarity(s, d.getName())));
    }
    sort(pairs.begin(), pairs.end(), [](pair<Document, double> a, pair<Document, double> b){return a.second > b.second;});

    return pairs[0].first;

}

void Controller::testBestMatch()
{
    assert(similarity("Ja", "Java") == 0.5);
    assert(similarity("Java", "Java") == 1);
}
