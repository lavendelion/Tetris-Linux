/*
�û������࣬���ܣ�
	1). ��ȡ�û�����
	2). ��������
���ԣ�
	1). �û�����ֵ
*/
#include<termios.h>
#include"block.h"

class UserInterface{
public:
	UserInterface(void);
	~UserInterface(void);
	bool readKeyboard(void);  // �����������룬����������򷵻�true���޸�key
	void operateBlock(Block *b);

	int key;
	struct termios initial_settings, new_settings;
};
