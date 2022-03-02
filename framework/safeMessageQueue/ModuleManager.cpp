#include "ModuleManager.hpp"
#include "Dvr.hpp"
#include "Hdd.hpp"
#include "../log.hpp"

#include <thread>

std::mutex ModuleManager::sMutex;
ModuleManager *ModuleManager::sInstance = nullptr;

ModuleManager::ModuleManager()
{
    mMsgQueue = new SafeQueue<std::shared_ptr<message_t>>();

    std::thread handle_message_thread(&ModuleManager::handle_message, this);
    handle_message_thread.detach();
}

ModuleManager::~ModuleManager()
{
    login();

    if (mMsgQueue)
    {
        delete mMsgQueue;
        mMsgQueue = nullptr;
    }
}

ModuleManager *ModuleManager::getInstance()
{
    if (sInstance == nullptr)
    {
        std::unique_lock<std::mutex> lock(sMutex);
        if (sInstance == nullptr)
        {
            sInstance = new ModuleManager();
        }
    }
    return sInstance;
}

void ModuleManager::update(std::shared_ptr<message_t> msg)
{
    login();
    mMsgQueue->push(msg);
}

int ModuleManager::start_record(void *params)
{
    login();

    unuse(params);

    int id = -1;
    if (-1 == (id = Dvr::alloc_dvr_id()))
    {
        loge("alloc DVR id failed, id = %d", id);
        return id;
    }

    Dvr *dvr = Dvr::getInstance(id);
    set_subject(*dvr);
    dvr->prepare();

    return id;
}

void ModuleManager::stop_record(int id)
{
    std::shared_ptr<message_t> msg = std::make_shared<message_t>();
    msg->what = PVR_MSG_RECORD_STOP;
    msg->obj.dvr.id = id;
    update(msg);
}

void ModuleManager::handle_message()
{
    logi("ModuleManager start handle message");

    int id = -1;
    Hdd *hdd = Hdd::getInstance();
    set_subject(*hdd);
    Dvr *dvr = nullptr;

    std::shared_ptr<message_t> msg;

    while (true)
    {
        mMsgQueue->wait_and_pop(msg);

        switch (msg->what)
        {
        case PVR_MSG_RECORD_START:
            id = msg->obj.dvr.id;
            dvr = Dvr::getInstance(id);
            logd("Receive DVR(%d) message, now start.", id);
            dvr->start();
            break;
        case PVR_MSG_RECORD_PAUSE:
            id = msg->obj.dvr.id;
            dvr = Dvr::getInstance(id);
            logd("Receive DVR(%d) message, now pause.", id);
            dvr->pause();
            break;
        case PVR_MSG_RECORD_RESTART:
            id = msg->obj.dvr.id;
            dvr = Dvr::getInstance(id);
            logd("Receive DVR(%d) message, now restart.", id);
            dvr->restart();
            break;
        case PVR_MSG_RECORD_STOP:
            id = msg->obj.dvr.id;
            if (!Dvr::is_instance_exist(id))
            {
                loge("Attempt to terminate DVR(%d) that does not exist.", id);
                break;
            }

            dvr = Dvr::getInstance(id);
            logd("Receive DVR(%d) message, now stop.", id);
            dvr->stop();
            break;
        case HDD_MSG_SPACE_NOT_ENOUGH:
            //stop_record();
            break;
        }
    }
}
