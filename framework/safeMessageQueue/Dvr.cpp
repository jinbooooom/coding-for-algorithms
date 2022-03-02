#include "Dvr.hpp"
#include <thread>

std::mutex Dvr::sMutex;
Dvr *Dvr::sInstance[DVR_MAX]{nullptr};

Dvr::Dvr()
{
}

Dvr::Dvr(int id)
    : mId(id)
{
}

Dvr::~Dvr()
{
    login();
    sInstance[mId] = nullptr;
}

Dvr *Dvr::getInstance(const int id)
{
    if (id < 0 || id > DVR_MAX)
    {
        loge("Invalid DVR id = %d", id);
        return nullptr;
    }

    if (nullptr == sInstance[id])
    {
        std::lock_guard<std::mutex> lock(sMutex);
        if (nullptr == sInstance[id])
        {
            logi("Create DVR%d", id);
            sInstance[id] = new Dvr(id);
        }
    }

    return sInstance[id];
}

bool Dvr::is_instance_exist(const int id)
{
    return static_cast<bool>(sInstance[id]);
}

int Dvr::alloc_dvr_id()
{
    for (int i = 0; i < DVR_MAX; ++i)
    {
        if (!is_instance_exist(i))
        {
            return i;
        }
    }
    return -1;
}

void Dvr::prepare()
{
    logmark("DVR%d prepare success.", mId);

    std::shared_ptr<message_t> msg = std::make_shared<message_t>();
    msg->what = PVR_MSG_RECORD_START;
    msg->obj.dvr.id = mId;
    notify_observers(msg);
}

void Dvr::start()
{
    logmark("DVR%d start success", mId);

    if (0 == mId) // 测试时，假设 DVR0 录制 5s，暂停 2s，再等待用户手动停止
    {
        std::thread do_record_thread([this] {
            logi("DVR(%d) do something.", mId);
            std::this_thread::sleep_for(std::chrono::seconds(5));
            std::shared_ptr<message_t> msg = std::make_shared<message_t>();
            msg->what = PVR_MSG_RECORD_PAUSE;
            msg->obj.dvr.id = mId;
            notify_observers(msg);
        });
        do_record_thread.detach();
    }
    else // 其它的 DVR，假设它运行 5s，就到达了结束时间，自动 stop。
    {
        std::thread do_record_thread([this] {
            logi("DVR(%d) do something.", mId);
            std::this_thread::sleep_for(std::chrono::seconds(5));
            std::shared_ptr<message_t> msg = std::make_shared<message_t>();
            msg->what = PVR_MSG_RECORD_STOP;
            msg->obj.dvr.id = mId;
            notify_observers(msg);
        });
        do_record_thread.detach();
    }
}

void Dvr::pause()
{
    logmark("DVR%d pause success", mId);
    std::thread do_record_thread([this] {
        logi("status is pause, DVR(%d) do nothing...", mId);
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::shared_ptr<message_t> msg = std::make_shared<message_t>();
        msg->what = PVR_MSG_RECORD_RESTART;
        msg->obj.dvr.id = mId;
        notify_observers(msg);
    });
    do_record_thread.detach();
}

void Dvr::restart()
{
    logmark("DVR%d restart success", mId);
    logi("DVR(%d) record again.", mId);
}

void Dvr::stop()
{
    Garbo<Dvr *> gc(sInstance[mId]);

    // 等待读写等线程结束.

    logmark("DVR%d stop success", mId);
}