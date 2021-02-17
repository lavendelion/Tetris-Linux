#include"map.h"
#include"user.h"
#include"block.h"

#include<ctime>
#include<cstdlib>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<errno.h>
#include<sys/mman.h>
#include<string.h>
#include<new>
#include<signal.h>

void *createSharedSection(int size){
	// 1. ������ʱ�ļ�����������ӳ����
	char path[128]="/home/xuanq/eluosifangkuai/tempfile";
	int fd = open(path, O_RDWR|O_CREAT, 0666);
	if(fd==-1){
		perror("open error");
		exit(0);
	}
	int ret;
	ret = truncate(path, size);
	if(ret != 0){
		perror("truncate error");
		exit(0);
	}
	// 2. ����ӳ����
	void *addr = mmap(NULL, size, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
	if(addr==MAP_FAILED){
		printf("mmap error: %s\n", strerror(errno));
		exit(0);
	}
	unlink(path);  // ��ʱ�ļ�ʹ����Ϻ��Զ�ɾ��
	close(fd);
	return addr;
}

int main(void){
	void *addr = createSharedSection(1024);

	std::srand(std::time(0));
	int width=15, height=15;
	Block *pb;
	int pid = fork();
	int randType;
	if(pid>0){
		Map map(width, height);
		map.printMap();
		while(1){
			randType = rand()%7;
			switch(randType){
				case 0: pb = (Block*)(new(addr) L_Block(width, height));break;
				case 1: pb = (Block*)(new(addr) R_Block(width, height));break;
				case 2: pb = (Block*)(new(addr) O_Block(width, height));break;
				case 3: pb = (Block*)(new(addr) Z_Block(width, height));break;
				case 4: pb = (Block*)(new(addr) N_Block(width, height));break;
				case 5: pb = (Block*)(new(addr) l_Block(width, height));break;
				case 6: pb = (Block*)(new(addr) T_Block(width, height));break;
			}
			int count=0;
			while(1){
				count = (1+count)%5;
				if(map.printBlock(pb)) break;
				if(count==0)
					pb->drop();
				usleep(100000);
			}
			map.refreshMap();
			if(map.isDead()) break;
		}
		kill(pid, SIGKILL);
		sleep(1);
		system("stty echo");  // ��ʱ��ô�������ÿ�γ�������ն��޷����Լ������룬��Ϊ�ӽ���û�лָ��ն����á�Ҫע���źŻص��������
		printf("Thanks for playing!\n");
	}
	else if(pid==0){
		UserInterface user;
		pb = (Block*)addr;
		while(1){
			if(user.readKeyboard())
				user.operateBlock(pb);
		}
	}
	else{
		perror("fork error");
		exit(0);
	}
	return 0;
}
