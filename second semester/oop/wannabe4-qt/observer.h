#ifndef OBSERVER_H
#define OBSERVER_H
#include <vector>

class Observer
{
public:
    Observer();
    virtual void update() = 0;
    virtual ~Observer(){}
};

class Observable
{
private:
    std::vector<Observer*> observers;

public:

    virtual ~Observable() {}

    void addObserver(Observer* obs)
    {
        this->observers.push_back(obs);
    }
    void removeObserver(Observer* obs)
    {
        this->observers.erase(std::remove(this->observers.begin(), this->observers.end(), obs));
    }
    void notify()
    {
        for (auto o: this->observers)
            o->update();
    }
};

#endif // OBSERVER_H
