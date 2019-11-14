#include "SingletonWithThread.h"

#include <thread>
#include <mutex>
#include <iostream>


struct SingletonWithThread::Implementation
{
    Implementation();

    std::thread bgThread;
    std::mutex bgThreadMutex;
    std::condition_variable cv;
    bool exitBgThread;
};

SingletonWithThread::Implementation::Implementation()
    : exitBgThread(false)
{
}

SingletonWithThread::SingletonWithThread()
    : d(std::make_unique<SingletonWithThread::Implementation>())
{
    d->bgThread = std::thread([this]() {
        std::cout << "Started thread id: " << std::this_thread::get_id() << std::endl;
        while (true) {
            //std::unique_lock<std::mutex> lock(d->bgThreadMutex);
            std::lock_guard<std::mutex> lock(d->bgThreadMutex);
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            //d->cv.wait_for(lock, std::chrono::milliseconds(1));
            if (d->exitBgThread) {
                break;
            }
        }
    });
}

SingletonWithThread::~SingletonWithThread()
{
    {
        std::lock_guard<std::mutex> lock(d->bgThreadMutex);
        d->exitBgThread = true;
        //d->cv.notify_all();
    }
    if (d->bgThread.joinable()) {
        d->bgThread.join();
    }
}

SingletonWithThread& SingletonWithThread::getInstance()
{
    static SingletonWithThread instance;
    return instance;
}
