#pragma once
#include "function.h"
#include "Task.h"

class WorkQue {
public:
    WorkQue() {
        mutex = PTHREAD_MUTEX_INITIALIZER;
    }
    //向任务队列中插入新的任务
    void insertTask(const Task& task) {
        deq.push_back(task);
    }
    int size() {
        return deq.size();
    }
    //线程取得新的任务
    Task getTask() {
        Task ans = deq.front();
        deq.pop_front();
        return ans;
    }

    pthread_mutex_t getMutex() {
        return mutex;
    }

private:
    pthread_mutex_t mutex; //多线程对任务队列的互斥锁
    deque<Task> deq; //存放accept 接收的 fd，
};
