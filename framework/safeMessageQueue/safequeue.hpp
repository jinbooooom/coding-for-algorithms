#ifndef THREAD_SAFE_QUEUE_HPP
#define THREAD_SAFE_QUEUE_HPP

#include <mutex>
#include <condition_variable>
#include <queue>
#include <memory>

template <typename T>
class SafeQueue
{
private:
    mutable std::mutex mMutex;
    std::queue<T> mDataQueue;
    std::condition_variable mQueueCond;

public:
    SafeQueue() {}

    SafeQueue(SafeQueue const &other)
    {
        std::lock_guard<std::mutex> lock(other.mMutex);
        mDataQueue = other.mDataQueue;
    }

    void push(T v)
    {
        std::lock_guard<std::mutex> lock(mMutex);
        mDataQueue.push(v);
        mQueueCond.notify_one();
    }

    void wait_and_pop(T &v)
    {
        std::unique_lock<std::mutex> lock(mMutex);
        mQueueCond.wait(lock, [this] { return !mDataQueue.empty(); });
        v = mDataQueue.front();
        mDataQueue.pop();
    }

    std::shared_ptr<T> wait_and_pop()
    {
        std::unique_lock<std::mutex> lock(mMutex);
        mQueueCond.wait(lock, [this] { return !mDataQueue.empty(); });
        std::shared_ptr<T> res(std::make_shared<T>(mDataQueue.front()));
        mDataQueue.pop();
        return res;
    }

    bool try_pop(T &v)
    {
        std::lock_guard<std::mutex> lock(mMutex);
        if (mDataQueue.empty())
            return false;
        v = mDataQueue.front();
        mDataQueue.pop();
        return true;
    }

    std::shared_ptr<T> try_pop()
    {
        std::lock_guard<std::mutex> lock(mMutex);
        if (mDataQueue.empty())
            return std::shared_ptr<T>();
        std::shared_ptr<T> res(std::make_shared<T>(mDataQueue.front()));
        mDataQueue.pop();
        return res;
    }

    bool empty() const
    {
        std::lock_guard<std::mutex> lock(mMutex);
        return mDataQueue.empty();
    }
};

#endif

