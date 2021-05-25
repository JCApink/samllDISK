#include "Task.h"


Task::Task(int _fd, std::string _orders, std::string _username, int _Dir)
    :fd(_fd),
    orders(_orders),
    username(_username),
    Dir(_Dir) {

}


int Task::getFd() const {
    return fd;
}

std::string Task::getOrders() const {
    return orders;
}

std::string Task::getUsername() const {
    return username;
}

int Task::getDir() const {
    return Dir;
}