#include "Hdd.hpp"
#include "../log.hpp"
#include <chrono>

std::mutex Hdd::sMutex;
Hdd *Hdd::sInstance = nullptr;

Hdd::Hdd()
{
    std::thread check_space_thread(&Hdd::check_space, this);
    check_space_thread.detach();
}

Hdd::~Hdd()
{
}

Hdd *Hdd::getInstance()
{
    login();
    if (nullptr == sInstance)
    {
        std::lock_guard<std::mutex> lock(sMutex);

        if (nullptr == sInstance)
        {
            logi("create Hdd");
            sInstance = new Hdd();
        }
    }

    return sInstance;
}

void Hdd::check_space()
{
    while (true)
    {
        logi("Hdd check space");
        std::this_thread::sleep_for(std::chrono::seconds(3));
    }
}