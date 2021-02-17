/*
用户交互类，功能：
	1). 读取用户键盘
	2). 操作方块
属性：
	1). 用户键盘值
*/
#include<termios.h>
#include"block.h"

class UserInterface{
public:
	UserInterface(void);
	~UserInterface(void);
	bool readKeyboard(void);  // 监听键盘输入，如果有输入则返回true并修改key
	void operateBlock(Block *b);

	int key;
	struct termios initial_settings, new_settings;
};
