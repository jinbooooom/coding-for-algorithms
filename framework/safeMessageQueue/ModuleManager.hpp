#ifndef MODULE_MANAGER_HPP
#define MODULE_MANAGER_HPP

#include "safequeue.hpp"
#include "message.hpp"
#include "observer.hpp"

class ModuleManager final : public Observer
{
private:
    static ModuleManager *sInstance;
    static std::mutex sMutex;
    SafeQueue<std::shared_ptr<message_t>> *mMsgQueue;

protected:
    ModuleManager();
    ModuleManager(const ModuleManager &) = delete;
    ModuleManager &operator=(const ModuleManager &) = delete;
    virtual ~ModuleManager();

public:
    static ModuleManager *getInstance();
    virtual void update(std::shared_ptr<message_t> msg) override;

    int start_record(void *params);
    void stop_record(int id);

    void handle_message();
};

#endif