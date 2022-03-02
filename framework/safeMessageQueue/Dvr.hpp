#ifndef DVR_HPP
#define DVR_HPP

#include "subject.hpp"
#include "garbo.hpp"
#include "../log.hpp"

#include <thread>
#include <mutex>

#define DVR_MAX (2)

class Dvr final : public Subject
{
private:
    int mId;

private:
    static std::mutex sMutex;
    static Dvr *sInstance[DVR_MAX];

protected:
    Dvr();
    explicit Dvr(int id);
    Dvr(const Dvr &) = delete;
    Dvr &operator=(const Dvr &) = delete;
    virtual ~Dvr();

    friend Garbo<Dvr *>;

public: // static function
    static Dvr *getInstance(const int id);
    static bool is_instance_exist(const int id);
    static int alloc_dvr_id();

    void prepare();
    void start();
    void pause();
    void restart();
    void stop();
};

#endif