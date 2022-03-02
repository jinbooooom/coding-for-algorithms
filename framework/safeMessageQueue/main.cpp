#include "ModuleManager.hpp"
#include <unistd.h>

int main()
{
    // ModuleManager 是给上层模块调用的
    ModuleManager *mgr = ModuleManager::getInstance();

    int id0 = mgr->start_record(nullptr);
    sleep(5);

    int id1 = mgr->start_record(nullptr);
    mgr->stop_record(id0);
    sleep(10);
    mgr->stop_record(id1);

    while (true)
        ;

    return 0;
}