//
//  main.cpp
//  wannabe3
//
//  Created by Alex Resiga on 14/06/2018.
//  Copyright © 2018 Alex Resiga. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <deque>
#include <iterator>
using namespace std;
/*
class Complex
{
private:
    int real;
    int imaginary;

public:
    Complex() :real{0}, imaginary{0} {}
    Complex(int a, int b): real{a}, imaginary{b} {}
    int getReal() const  {return this->real;}
    int getImaginary() const {return this->imaginary;}
    Complex operator/(const int& b)
    { if (b==0)
        throw runtime_error("Division by zero\n");
    
        return Complex{this->real/b, this->imaginary/b};
        
    }
    friend ostream& operator<<(ostream& os, const Complex& c){os<<c.getReal()<<"+"<<c.getImaginary()<<"i"; return os;};
    inline bool operator==(const Complex& b){return this->real == b.getReal() and this->imaginary == b.getImaginary();}
    
};

template<typename T>
class Vector
{
private:
    vector<T> elems;
public:
    Vector(vector<T> v): elems{v}{}
    void printAll(ostream& os){for (auto x: elems) os<<x<<", ";}
};

int main()
{
    Complex a{}, b{1, 2}, c{6,4}, d{b};
    cout<<d;
    Complex res1 = c/2;
    cout<<res1;
    try
    {
        Complex res2 = b/0;
    }
    catch(runtime_error& e)
    {
        cout<<e.what();
    }
    
    Vector<string> v1{vector<string>{"hello", "bye"}};
    v1.printAll(cout);
    cout<<endl;
    Vector<Complex> v2{vector<Complex>{a, b, c, d} };
    
    v2.printAll(cout);
    cout<<endl;
    return 0;
 
}
*/
/*
int main()
{
    vector<int> v{1, 2,3,4,5};
    vector<int>::iterator it = find(v.begin(), v.end(), 4);
    v.insert(it, 8);
    it = v.begin()+2;
    *it = 10;
    vector<int> x;
    copy_if(v.begin(), v.end(), back_inserter(x), [](int a){return a%2==0;});
    for(auto a:x)
        cout<<a<<" ";
    return 0;
}
*/
/*
class Ex1{
public:
    Ex1() {cout<<"exception1 ";}
    Ex1(const Ex1& ex) {cout<<"copy ";}
};

class Ex2: public Ex1
{
public:
    Ex2() {cout<<"Exception2 ";}
    Ex2(const Ex2& ex) {cout<<"copy2 ";}
    
};

void except(int x)
{
    if (x<0)
        throw Ex1{};
    else if (x==0)
        throw Ex2{};
    cout<<"done ";
}

int main()
{
    try
    {
        cout<<"start ";
        try{
            except(0);
        }
        catch (Ex1& e) {}
        except(-2);
    }catch(Ex1 e) {}
    
    return 0;
}
 */
/*
class B
{
public:
    void f() { cout <<"B.f ";}
    virtual ~B() {}
};

class D1: public B
{
public:
    virtual void f() { cout<<"D1.f ";}
    virtual ~D1() {}
};

class D2: public D1
{
public:
    void f()  {cout<<"D2.f ";}
};


int main()
{
    B* b1 = new B{}; b1->f();delete b1;
    B* b2 = new D1{}; b2->f();delete b2;
    B* b3 = new D2{}; b3->f();delete b3;
    D1* d = new D2{}; d->f();delete d;
    
    return 0;
}
*/
/*
class Vector
{
    int* elems;
    int size;
    
public:
    Vector(): size{0} {elems = new int[10]; }
    void add(int elem)
    {
        elems[size++] = elem;
    }
    int& operator[](int pos)
    {
        if (pos < 0 || pos >= size)
            throw runtime_error("index out of bounds");
        return elems[pos];
    }
    ~Vector() {delete[] elems;}
};

int main()
{
    Vector v1;
    v1.add(0);
    v1.add(1);
    Vector v2 = v1;
    try{
        v1[0] = 2;
        cout<< v1[0]<<" "<<v1[1]<<" ";
        cout<< v2[0]<<" "<<v2[1]<<" ";
    }catch(runtime_error& e)
    {
        cout<<e.what();
    }
    return 0;
}
*/
/*
class A
{
protected:
    string name;
public:
    A(){}
    A(const string& s): name{s}{cout<<"A ";}
    string toString(){stringstream res; res<<name<<" ";return res.str();}
};


class B: public A
{
private:
    string type;
public:
    B(const string& n, const string& t): type{t}, A{n} {cout<<A::toString();cout<<"B";}
    //string toString(){stringstream res; res<<name<<" + "<<type<<" "; return res.str();}
};

int main()
{
    B a{"da", "nu"};
    cout<<a.toString();
    
    cout<<endl;
    return 0;
}
*/

/*
class Animal
{
protected:
    std::string colour;
    double weight;
    
public:
    Animal(std::string _colour, double _weight);
    //~Animal();
    Animal(const Animal& a) {cout<<"poate merge\n";}
    virtual ~Animal();
    
    std::string getColour() const;
    double getWeight() const;
    
    //std::string toString() const;
    
    virtual std::string toString() const;    // allows polymorphism
};


Animal::Animal(std::string _colour, double _weight) : colour{ _colour }, weight{ _weight }
{
cout << "Constructing an animal." << endl;
}

Animal::~Animal()
{
    cout << "Animal is being destroyed." << endl;
}

std::string Animal::getColour() const
{
    return this->colour;
}

double Animal::getWeight() const
{
    return this->weight;
}

std::string Animal::toString() const
{
    stringstream buffer;
    buffer << "Animal \n\t weight: " << this->weight << " kg"<< endl << "\t colour: " << this->colour << endl;
    return buffer.str();
}


class Dog :    public Animal
{
private:
    std::string breed;
    double furLength;
    
public:
    Dog(std::string _colour, double _weight, std::string _breed, double _furLength);
    ~Dog();
    
    std::string getBreed() const;
    double getFurLength() const;
    
    //std::string toString() const;
    
    std::string toString() const override;
};

Dog::Dog(std::string _colour, double _weight, string _breed, double _furLength) : Animal{ _colour, _weight }, breed{ _breed }, furLength{ _furLength}
{
    cout << "Constructing a dog, breed " << this->breed<< " weighting " << this->weight << " kg, having the colours: " << this->colour << " and the fur length "<<this->furLength<<" cm." << endl;
}

string Dog::getBreed() const
{
    return this->breed;
}

double Dog::getFurLength() const
{
    return this->furLength;
}

std::string Dog::toString() const
{
    stringstream buffer;
    buffer << "Dog \n\t weight: " << this->weight <<" kg " << endl << "\t colour: " << this->colour << endl <<"\t breed: " << this->breed << endl << "\t fur length: " << this->furLength << " cm." << endl;
    return buffer.str();
}

Dog::~Dog()
{
    cout << "Dog: breed " << this->breed << " weighting " << this->weight << " kg, having the colours: " << this->colour << " and the fur length " << this->furLength << " cm is being destroyed." << endl;
}


class Penguin: public Animal
{
private:
    std::string type;
    
public:
    Penguin(std::string _colour, double _weight, std::string _type);
    ~Penguin();
    
    std::string getType() const;
    
    //std::string toString() const;
    
    std::string toString() const override;
};

Penguin::Penguin(std::string _colour, double _weight, std::string _type) : Animal{ _colour, _weight }, type{ _type }
{
    cout << "Constructing a "<<this->type<<" penguin, weighting "<<this->weight<<" kg and having the colours: "<<this->colour<<"." << endl;
}

Penguin::~Penguin()
{
    cout <<this->type<<" penguin, weighting "<<this->weight<<" kg and having the colours : "<<this->colour<<" is being destroyed." << endl;
}

std::string Penguin::getType() const
{
    return this->type;
}

std::string Penguin::toString() const
{
    // access the function from the base class
    string baseStr = Animal::toString();
    
    stringstream buffer;
    buffer << "Penguin \n\t type: " << this->type << endl;
    return baseStr + buffer.str();
}


int main()
{
    
    
    Animal* a1 = new Penguin{ "black and white", 7, "Magellanic" };
    Penguin* p1 = static_cast<Penguin*>(a1);    // Valid! p1 is a valid and correct pointer to a Penguin
    Penguin* p2 = dynamic_cast<Penguin*>(a1);   // Valid! p2 is a valid and correct pointer to a Penguin
    
    Animal* a2 = new Animal{ "brown", 5 };
    Penguin* p3 = static_cast<Penguin*>(a2);    // works, but the "type" data member of the penguin is invalid!
    Penguin* p4 = dynamic_cast<Penguin*>(a2);   // cast fails => p4 is now a nullptr
    if (p4 == nullptr)
    {
        cout << "Dynamic cast failed." << endl;
    }
    
    delete a1;
    delete a2;
    
    
    return 0;
}
*/
/*
template <typename T>
class Stack
{
private:
    int cap;
    vector<T> elems;
public:
    Stack(const int& cap): cap{cap} {}
    int getMaxCapacity() {return this->cap;}
    Stack& operator+(const T& elem)
    {
        if (this->cap == this->elems.size())
            throw runtime_error("stack is full");
        this->elems.push_back(elem);
        
        return *this;
    }
    
    T pop(){auto elem =  this->elems.back();this->elems.pop_back(); return elem;}
};
int main()
{
    Stack<std::string> s{ 2 };
    assert(s.getMaxCapacity() == 2);
    try {
        s = s + "examination";
        s = s + "oop";
        s = s + "test";
    }
    catch (std::exception& e) {
        assert(strcmp(e.what(), "stack is full") == 0);
    }
    assert(s.pop() == "oop");
    cout<<s.pop();
    
    return 0;
}
*/
/*
class Activity
{
private:
    string title;
    string time;
public:
    Activity(string a, string b): title{a}, time{b} {}
    string getTtitle() {return title;}
    string getTime() {return time;}
    friend ostream& operator<<(ostream& os, const Activity& a)
    {
        os<<a.title<<" at "<<a.time;
        return os;
    }
    
};

template <typename T>
class ToDo
{
    
public:
    ToDo(){}
    ToDo& operator+=(const T& elem)
    {
        this->elems.push_back(elem);
        sort(this->elems.begin(), this->elems.end(),[](Activity a, Activity b){return a.getTime() < b.getTime();});
        return *this;
    }
    using container = vector<T>;
    using iterator = typename container::iterator;
    using const_iterator = typename container::const_iterator;
    
    iterator begin() {return elems.begin();}
    const_iterator begin() const {return elems.begin();}
    iterator end() {return elems.end();}
    const_iterator end() const {return elems.end();}
    
    void reversePrint(ostream& os)
    {
        sort(this->elems.begin(), this->elems.end(),[](Activity a, Activity b){return a.getTime() > b.getTime();});
        for(auto a: this->elems)
            os<<a<<"\n";
    }
    
private:
    container elems;
};

int main()
{
    Activity tiff{"tiff", "20:00"};
    Activity project{"project", "09:20"};
    ToDo<Activity> todo{};
    todo += tiff;
    todo += project;
    for(auto a: todo)
        cout<<a<<"\n";
    todo.reversePrint(cout);
    return 0;
}
*/
/*
class B
{
public:
    B() { std::cout << "B{}"; }
    virtual void print() { std::cout <<
        "B    "; }
    virtual ~B() { std::cout << "~B()"; }
};
class D : public B
{
public:
    D() { std::cout << "D{}"; }
    void print() override { std::cout <<
        "D"; }
    virtual ~D() { std::cout << "~D()"; }
};

int main()
{
    B b[] = {  B{},  D{} };
    b[0].print();
    b[1].print();
    
    return 0;
}
*/
/*
class Person
{
public:
    Person() { std::cout << "Person{}"; }
    virtual void print() = 0;
    virtual ~Person() { std::cout <<
        "~Person()"; }
};
class Student : public Person
{
public:
    Student() { std::cout << "Student{}";
    }
    void print() override { std::cout <<
        "Student"; }
    virtual ~Student() { std::cout <<
        "~Student()"; }
};

int main()
{
    //Person* p = new Person{};
    //delete p;
    Person* s = new Student{};
    s->print();
    delete s;
    return 0;
}
*/
/*
class E
{
public:
    E() { std::cout << "E{}"; }
    virtual ~E() { std::cout << "~E()"; }
};
class DE : public E
{
public:
    static int n;
    DE() { n++; }
};
int DE::n = 0;
int fct2(int x)
{
    if (x < 0)
    {
        throw E{};
        std::cout << "number less than 0" << std::endl;
    }
    else if (x == 0)
    {
        throw DE{};
        std::cout << "number equal to 0"<< std::endl;
    }
    return x % 10;
}

int main()
{
    try
    {
        int res = 0;
        res = fct2(-5);
        std::cout << DE::n;
        res = fct2(0);
        std::cout << DE::n;
        res = fct2(25);
        std::cout << DE::n;
    }
    catch (E&)
    {
        std::cout << DE::n;
    }
    return 0;
}
*/

/*
int main()
{
    std::deque<std::string> d;
    d.push_back("A");
    d.push_front("B");
    d.push_back("C");
    d.push_front("D");
    auto itBegin = d.begin();
    auto itEnd = d.end();
    itBegin++;
    itEnd--;
    while (itBegin != itEnd)
    {
        std::cout << *itBegin << " ";
        itBegin++;
    }
    return 0;
}
 */
/*
template <typename T>
class Adder
{
private:
    vector<T> elems;
public:
    Adder(const T& elem) {this->elems.push_back(elem);}
    Adder& operator+(const T& elem){this->elems.push_back(elem); return *this;}
    Adder& operator++(){this->elems.push_back(this->elems.back()); return *this;}
    Adder& operator--()
    {
        if (this->elems.size() == 0)
            throw 20;
        this->elems.pop_back();
        
        
        
        return *this;}
    int sum()
    {
        int suma = 0;
        for(auto t: this->elems)
        {suma+=t;cout<<t<<" ";}
        
        return suma;
    }
};

int main()
{
    Adder<int> add{5};
    add = add+5+2;
    ++add;
    add +8;
    cout<<add.sum()<<"\n";
    --add;
    cout<<add.sum()<<"\n";
    --(--add);
    cout<<add.sum()<<"\n";
    try{
        --(--(--add));
    }catch(int ex)
    {
        cout<<ex;
    }
    return 0;
}
*/
/*
int fct(string v)
{
    if (v == "") throw string{"2"};
    cout<<"1 ";
    auto a = v.size();
    if (v.size() > 4) throw runtime_error{"pula"};
    
    return 0;
}

int main()
{
    try {
        cout<< fct("HI")<<" ";
        cout<< fct("Hello")<<" ";
        cout<< fct("")<<" ";
    }catch(string& e)
    {
        cout<<e;
    }
    catch(runtime_error& e)
    {
        cout<<e.what();
    }
    return 0;
}
*/
/*class B
{
public:
    B() {}
    B(const B& b) {cout <<"copy ";}
    virtual void f() {cout<<"B.f ";}
    void g(B b) {cout<<"B.g ";};
    virtual ~B() {cout<<"~B ";}
};

class D: public B {
public:
    D() {}
    void f() {B::f(); cout<<"D.f ";}
    void g(D d) {B::g(d); cout<<"D.g ";}
};

int main()
{
    B* b = new B{};
    B* d = new D{};
    d->f();
    cout<<endl;
    d->g(*b);
    delete b;
    delete d;
    
    return 0;
}
 */
/*
class A
{
private:
    int* x;
public:
    A(int _x=0) {x = new int{_x};}
    A(const A& a)
    {
        x = new int{*a.x};
    }
    
    int get() {return *x;}
    void set(int _x) {*x = _x;}
    
    ~A() {delete x;}
};
int main()
{
    A a1, a2; a1.set(8);
    A a3; a3 = a1;
    A a4 = a1;
    a1.set(5);
    cout<<a1.get()<<" ";
    cout<<a2.get()<<" ";
    cout<<a3.get()<<" ";
    cout<<a4.get()<<" ";
    
    
    return 0;
}


int main()
{
    vector<int> v{1,2,3,4,5};
    vector<int>::iterator it = find(v.begin(), v.end(), 4);
    v.insert(it, 7);
    it = v.begin()+2;
    *it = 11;
    vector<int> x;
    copy_if(v.begin(), v.end(), back_inserter(x), [](int a){return a%2==1;});
    for(auto a: x)
        cout<<a<<" ";
    return 0;
}
*/

class Shape {
public:
    int a;
    int ceva() {
        cout<<"base class\n";
        return 0;
    }
};

class Triangle: public Shape {
public:
    int ceva(int b) {
        cout<<"child\n";
        return 3*a;
    }
};
int main()
{
    Shape* x = new Shape();
    x->ceva();
    Triangle* y = new Triangle();
    y->ceva(2);

    return 0;
}
