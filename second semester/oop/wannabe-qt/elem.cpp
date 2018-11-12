#include "elem.h"

ifstream& operator>>(ifstream& in, Elem& e)
{
    in>>e.id>>e.name;
    return in;
}
