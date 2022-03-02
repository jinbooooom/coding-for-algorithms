#include "subject.hpp"

Subject::Subject()
{
    mObservers = new std::set<Observer *>();
}

Subject::~Subject()
{
    /**
     * Subject has no right to deconstruct specific observer,
     * but must deconstruct its own set.
    */
    for (const auto &o : *mObservers)
    {
        remove_observer(*o);
    }
    delete mObservers;
}

void Subject::register_observer(Observer &o)
{
    mObservers->insert(&o);
}

void Subject::remove_observer(Observer &o)
{
    o.remove_subject(*this);
}

void Subject::notify_observers(std::shared_ptr<message_t> msg)
{
    for (auto o : *mObservers)
    {
        o->update(msg);
    }
    return;
}
