#include <stdio.h>
#include "Server.h"
#include <arpa/inet.h>//sock�õ�

int initListenFd(unsigned short port)
{
	//1.����������fd
	int lfd = socket(AF_INET, SOCK_STREAM, 0);
	if(lfd == -1)
	{
		perror("socket");
		return -1;
	}
	//2.���ö˿ڷ���
	int opt = 1;//����������Ͽ���һ�����ٽ���֮����һ��2ml�ĵȴ�ʱ��
	int ret = setsockopt(lfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof opt);
	if (ret == -1)
	{
		perror("setsocketopt");
		return -1;
	}
	//3.��
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;//IPV4
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = 
	ret = bind(lfd)
	//����fd
	return 0;
}
