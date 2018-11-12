#ifndef USER_H
#define USER_H
#include <string>
using namespace std;
class User
{
private:
    std::string name;
public:
    User();
    User(const std::string& name): name{name} {}
    string getName() {return this->name;}

};

#endif // USER_H
