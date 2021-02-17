#pragma once
/*
地图类，具有的功能：
	1). 打印地图
	2). 绘制当前移动的方块
具有的属性：
	1). 宽
	2). 高
	3). 地图数组(char **)
*/
#include"block.h"

class Map{
public:
	Map(int width, int height);
	~Map();
	void printMap(void);  // 打印当前地图
	bool printBlock(Block *b);  // 打印当前移动的方块
	void refreshMap(void);  // 当一个方块结束移动后，需要刷新地图，消去满的行
	bool isDead(void);  // 判断是否死亡

	char **map;
private:
	char blockChar='*';  // 表示方块的符号
	int w,h;
	int score=0;
};
