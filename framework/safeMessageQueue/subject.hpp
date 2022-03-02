#ifndef SUBJECT_HPP
#define SUBJECT_HPP

#include <set>
#include <memory>
#include "message.hpp"
#include "observer.hpp"

class Observer;

class Subject
{
protected:
    std::set<Observer *> *mObservers;

protected:
    Subject();

    virtual ~Subject();

public:
    virtual void register_observer(Observer &o);

    virtual void remove_observer(Observer &o);

    virtual void notify_observers(std::shared_ptr<message_t> msg);
};

#endif
