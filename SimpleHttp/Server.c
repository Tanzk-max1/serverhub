#include <stdio.h>
#include "Server.h"
#include <arpa/inet.h>//sock用的

int initListenFd(unsigned short port)
{
	//1.创建监听的fd
	int lfd = socket(AF_INET, SOCK_STREAM, 0);
	if(lfd == -1)
	{
		perror("socket");
		return -1;
	}
	//2.设置端口服用
	int opt = 1;//如果是主动断开的一方，再结束之后又一个2ml的等待时长
	int ret = setsockopt(lfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof opt);
	if (ret == -1)
	{
		perror("setsocketopt");
		return -1;
	}
	//3.绑定
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;//IPV4
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = 
	ret = bind(lfd)
	//返回fd
	return 0;
}
