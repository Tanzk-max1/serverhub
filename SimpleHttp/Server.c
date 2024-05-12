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
	addr.sin_addr.s_addr = INADDR_ANY;
		ret = bind(lfd,(struct sockaddr*)&addr,sizeof addr);
		if (ret == -1)
		{
			perror("bing");
			return -1;
		}
	//���ü���
		ret = listen(lfd, 128);//���������׽�����������ӣ�Ȼ���پܾ���һ��������֮ǰ��n�����������Ŷ�
		if (ret == -1)
		{	
			perror("listen");
			return -1;

		}

	//����fd

	return lfd;
}
