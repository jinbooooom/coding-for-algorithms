#ifndef HDD_HPP
#define HDD_HPP

#include "subject.hpp"

#include <thread>
#include <mutex>

class Hdd final : public Subject
{
private:
    static std::mutex sMutex;
    static Hdd *sInstance;

protected:
    Hdd();
    Hdd(const Hdd &) = delete;
    Hdd &operator=(const Hdd &) = delete;
    virtual ~Hdd();

public: 
    static Hdd *getInstance();

    void check_space();
};

#endif