#ifndef _SINGLETONWITHTHREAD_H
#define _SINGLETONWITHTHREAD_H

#include <memory>

#include "dllexport.h"


struct  SingletonWithThread
{
    DLLEXPORT static SingletonWithThread& getInstance();

private:
    SingletonWithThread();
    virtual ~SingletonWithThread();

    SingletonWithThread(const SingletonWithThread&) = delete;
    SingletonWithThread& operator=(const SingletonWithThread&) = delete;
    SingletonWithThread(SingletonWithThread&&) = delete;
    SingletonWithThread& operator=(SingletonWithThread&&) = delete;

    struct Implementation;
    std::unique_ptr<Implementation> d;
};

#endif // !_SINGLETONWITHTHREAD_H
