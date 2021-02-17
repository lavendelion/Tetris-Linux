#pragma once
/*
��ͼ�࣬���еĹ��ܣ�
	1). ��ӡ��ͼ
	2). ���Ƶ�ǰ�ƶ��ķ���
���е����ԣ�
	1). ��
	2). ��
	3). ��ͼ����(char **)
*/
#include"block.h"

class Map{
public:
	Map(int width, int height);
	~Map();
	void printMap(void);  // ��ӡ��ǰ��ͼ
	bool printBlock(Block *b);  // ��ӡ��ǰ�ƶ��ķ���
	void refreshMap(void);  // ��һ����������ƶ�����Ҫˢ�µ�ͼ����ȥ������
	bool isDead(void);  // �ж��Ƿ�����

	char **map;
private:
	char blockChar='*';  // ��ʾ����ķ���
	int w,h;
	int score=0;
};
