#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include <map>
#include <string>
#include <memory>
#include "message.hpp"
#include "subject.hpp"

class Subject;

class Observer
{
protected:
    // for remove subject
    std::set<Subject *> *mSubjects;

protected:
    Observer();

    virtual ~Observer();

public:
    virtual void remove_subject(Subject &s);

    virtual void set_subject(Subject &s);

    virtual void update(std::shared_ptr<message_t> msg) = 0;
};

#endif
