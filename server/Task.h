#pragma once
#include <string>

class Task
{
public:
    Task(int _fd, std::string _orders, std::string _username, int _Dir);
    int getFd() const ;
    std::string getOrders() const;
    std::string getUsername() const;
    int getDir() const;

private:
    int fd; //客户端socket
    std::string orders; //客户端发送来的命令
    std::string username; //客户端登陆用户名
    int Dir; //用户所在目录号
};