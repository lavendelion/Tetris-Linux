#pragma once
/*
方块抽象类，应有的功能为：
	1). 左旋转90°
	2). 右旋转90°
	3). 重力下降1格
	4). 左移动1格
	5). 右移动1格
	6). 是否碰撞(需要输入当前地图)
	7). 获取方块占据的格子坐标

应有的属性：
	1). 方块中心坐标
	2). 方块类型(5种) L O Z l T
	3). 方块姿态(最多4种) L:4 O:1 Z:2 l:1 T:4
	4). 方块占据的格子坐标 int** 
*/
class Block{
public:
	Block(int width, int height);
	~Block();
	virtual void leftRotate(void)=0;			 // 1). 左旋转90°
	virtual void rightRotate(void)=0;			 // 2). 右旋转90°
	void drop(void);							 // 3). 重力下降1格
	virtual void leftMove(void)=0;   			 // 4). 左移动1格
	virtual void rightMove(void)=0;  			 // 5). 右移动1格
	virtual void downMove(void)=0;               // 向下移动1格
	virtual bool isTouch(char**, char)=0;		 	     // 6). 是否碰撞(需要输入当前地图)
	virtual int** getOccupiedGrid(void)=0;       // 7). 获取方块占据的格子坐标

	float pos[2];			// 方块中心坐标
	int w,h;                // 移动区域的宽、高
	char type;				// 方块类型(5种) L R O Z N l T, R是镜像L, N是镜像Z
protected:
	int posture;			// 方块姿态(最多4种) posture={0,1,2,3}  L:4 O:1 Z:2 l:1 T:4
	int** occupiedGrid;
};

class L_Block:public Block{
public:
	L_Block(int w, int h);
	virtual void leftRotate(void);			 // 左旋转90°
	virtual void rightRotate(void);			 // 右旋转90°
	virtual void leftMove(void);   			 // 左移动1格
	virtual void rightMove(void);  			 // 右移动1格
	virtual void downMove(void);               // 向下移动1格
	virtual bool isTouch(char **map, char blockChar);    // 是否碰撞(需要输入当前地图)
	virtual int** getOccupiedGrid(void);       // 获取方块占据的格子坐标
};

class R_Block:public Block{
public:
	R_Block(int w, int h);
	virtual void leftRotate(void);			 // 左旋转90°
	virtual void rightRotate(void);			 // 右旋转90°
	virtual void leftMove(void);   			 // 左移动1格
	virtual void rightMove(void);  			 // 右移动1格
	virtual void downMove(void);               // 向下移动1格
	virtual bool isTouch(char **map, char blockChar);    // 是否碰撞(需要输入当前地图)
	virtual int** getOccupiedGrid(void);       // 获取方块占据的格子坐标
};

class O_Block:public Block{
public:
	O_Block(int w, int h);
	virtual void leftRotate(void);			 // 左旋转90°
	virtual void rightRotate(void);			 // 右旋转90°
	virtual void leftMove(void);   			 // 左移动1格
	virtual void rightMove(void);  			 // 右移动1格
	virtual void downMove(void);               // 向下移动1格
	virtual bool isTouch(char **map, char blockChar);    // 是否碰撞(需要输入当前地图)
	virtual int** getOccupiedGrid(void);       // 获取方块占据的格子坐标
};

class Z_Block:public Block{
public:
	Z_Block(int w, int h);
	virtual void leftRotate(void);			 // 左旋转90°
	virtual void rightRotate(void);			 // 右旋转90°
	virtual void leftMove(void);   			 // 左移动1格
	virtual void rightMove(void);  			 // 右移动1格
	virtual void downMove(void);               // 向下移动1格
	virtual bool isTouch(char **map, char blockChar);    // 是否碰撞(需要输入当前地图)
	virtual int** getOccupiedGrid(void);       // 获取方块占据的格子坐标
};

class N_Block:public Block{
public:
	N_Block(int w, int h);
	virtual void leftRotate(void);			 // 左旋转90°
	virtual void rightRotate(void);			 // 右旋转90°
	virtual void leftMove(void);   			 // 左移动1格
	virtual void rightMove(void);  			 // 右移动1格
	virtual void downMove(void);               // 向下移动1格
	virtual bool isTouch(char **map, char blockChar);    // 是否碰撞(需要输入当前地图)
	virtual int** getOccupiedGrid(void);       // 获取方块占据的格子坐标
};

class l_Block:public Block{
public:
	l_Block(int w, int h);
	virtual void leftRotate(void);			 // 左旋转90°
	virtual void rightRotate(void);			 // 右旋转90°
	virtual void leftMove(void);   			 // 左移动1格
	virtual void rightMove(void);  			 // 右移动1格
	virtual void downMove(void);               // 向下移动1格
	virtual bool isTouch(char **map, char blockChar);    // 是否碰撞(需要输入当前地图)
	virtual int** getOccupiedGrid(void);       // 获取方块占据的格子坐标
};

class T_Block:public Block{
public:
	T_Block(int w, int h);
	virtual void leftRotate(void);			 // 左旋转90°
	virtual void rightRotate(void);			 // 右旋转90°
	virtual void leftMove(void);   			 // 左移动1格
	virtual void rightMove(void);  			 // 右移动1格
	virtual void downMove(void);               // 向下移动1格
	virtual bool isTouch(char **map, char blockChar);    // 是否碰撞(需要输入当前地图)
	virtual int** getOccupiedGrid(void);       // 获取方块占据的格子坐标
};
