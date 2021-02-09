#include "function.h"

int tcpInit(int *fd)
{
    int ret;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    error_check(sockfd, -1, "socket");
    int on = 1;
    ret = setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
    error_check(ret, -1, "setsockopt");
    struct sockaddr_in sockinfo;
    bzero(&sockinfo, sizeof(sockinfo));
    sockinfo.sin_addr.s_addr = inet_addr(IP);
    sockinfo.sin_port = htons(PORT);
    sockinfo.sin_family = AF_INET;
    ret = bind(sockfd, (sockaddr *)&sockinfo, sizeof(sockinfo));
    error_check(ret, -1, "bind");
    ret = listen(sockfd, 10);
    error_check(ret, -1, "listen");
    *fd = sockfd;
    return 0;
}