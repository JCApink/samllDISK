
#include "factory.h"


Factory::Factory() : 
    threadNum(THREADNUM), 
    cond(PTHREAD_COND_INITIALIZER), 
    startFlag(false){
        threadNum = THREADNUM;
        cond = PTHREAD_COND_INITIALIZER;
        startFlag = false;
}

void Factory::startFactory() {
    if (!startFlag) {
        cout << "server is running ..." << endl;
        for (int i = 0; i < threadNum; i++) {
            pthread_create(&threads[i], NULL, doingTask, this);
        }
        sleep(1);
        startFlag = true;
    }
}

WorkQue Factory::getWorkQue() {
    return que;
}

pthread_cond_t Factory::getCond() {
    return cond;
}