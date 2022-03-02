#include "observer.hpp"

Observer::Observer()
{
    mSubjects = new std::set<Subject *>();
}

Observer::~Observer()
{
    delete mSubjects;
}

void Observer::remove_subject(Subject &s)
{
    mSubjects->erase(&s);
}

void Observer::set_subject(Subject &s)
{
    mSubjects->insert(&s);
    s.register_observer(*this);
}

