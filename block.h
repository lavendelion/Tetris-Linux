#pragma once
/*
��������࣬Ӧ�еĹ���Ϊ��
	1). ����ת90��
	2). ����ת90��
	3). �����½�1��
	4). ���ƶ�1��
	5). ���ƶ�1��
	6). �Ƿ���ײ(��Ҫ���뵱ǰ��ͼ)
	7). ��ȡ����ռ�ݵĸ�������

Ӧ�е����ԣ�
	1). ������������
	2). ��������(5��) L O Z l T
	3). ������̬(���4��) L:4 O:1 Z:2 l:1 T:4
	4). ����ռ�ݵĸ������� int** 
*/
class Block{
public:
	Block(int width, int height);
	~Block();
	virtual void leftRotate(void)=0;			 // 1). ����ת90��
	virtual void rightRotate(void)=0;			 // 2). ����ת90��
	void drop(void);							 // 3). �����½�1��
	virtual void leftMove(void)=0;   			 // 4). ���ƶ�1��
	virtual void rightMove(void)=0;  			 // 5). ���ƶ�1��
	virtual void downMove(void)=0;               // �����ƶ�1��
	virtual bool isTouch(char**, char)=0;		 	     // 6). �Ƿ���ײ(��Ҫ���뵱ǰ��ͼ)
	virtual int** getOccupiedGrid(void)=0;       // 7). ��ȡ����ռ�ݵĸ�������

	float pos[2];			// ������������
	int w,h;                // �ƶ�����Ŀ���
	char type;				// ��������(5��) L R O Z N l T, R�Ǿ���L, N�Ǿ���Z
protected:
	int posture;			// ������̬(���4��) posture={0,1,2,3}  L:4 O:1 Z:2 l:1 T:4
	int** occupiedGrid;
};

class L_Block:public Block{
public:
	L_Block(int w, int h);
	virtual void leftRotate(void);			 // ����ת90��
	virtual void rightRotate(void);			 // ����ת90��
	virtual void leftMove(void);   			 // ���ƶ�1��
	virtual void rightMove(void);  			 // ���ƶ�1��
	virtual void downMove(void);               // �����ƶ�1��
	virtual bool isTouch(char **map, char blockChar);    // �Ƿ���ײ(��Ҫ���뵱ǰ��ͼ)
	virtual int** getOccupiedGrid(void);       // ��ȡ����ռ�ݵĸ�������
};

class R_Block:public Block{
public:
	R_Block(int w, int h);
	virtual void leftRotate(void);			 // ����ת90��
	virtual void rightRotate(void);			 // ����ת90��
	virtual void leftMove(void);   			 // ���ƶ�1��
	virtual void rightMove(void);  			 // ���ƶ�1��
	virtual void downMove(void);               // �����ƶ�1��
	virtual bool isTouch(char **map, char blockChar);    // �Ƿ���ײ(��Ҫ���뵱ǰ��ͼ)
	virtual int** getOccupiedGrid(void);       // ��ȡ����ռ�ݵĸ�������
};

class O_Block:public Block{
public:
	O_Block(int w, int h);
	virtual void leftRotate(void);			 // ����ת90��
	virtual void rightRotate(void);			 // ����ת90��
	virtual void leftMove(void);   			 // ���ƶ�1��
	virtual void rightMove(void);  			 // ���ƶ�1��
	virtual void downMove(void);               // �����ƶ�1��
	virtual bool isTouch(char **map, char blockChar);    // �Ƿ���ײ(��Ҫ���뵱ǰ��ͼ)
	virtual int** getOccupiedGrid(void);       // ��ȡ����ռ�ݵĸ�������
};

class Z_Block:public Block{
public:
	Z_Block(int w, int h);
	virtual void leftRotate(void);			 // ����ת90��
	virtual void rightRotate(void);			 // ����ת90��
	virtual void leftMove(void);   			 // ���ƶ�1��
	virtual void rightMove(void);  			 // ���ƶ�1��
	virtual void downMove(void);               // �����ƶ�1��
	virtual bool isTouch(char **map, char blockChar);    // �Ƿ���ײ(��Ҫ���뵱ǰ��ͼ)
	virtual int** getOccupiedGrid(void);       // ��ȡ����ռ�ݵĸ�������
};

class N_Block:public Block{
public:
	N_Block(int w, int h);
	virtual void leftRotate(void);			 // ����ת90��
	virtual void rightRotate(void);			 // ����ת90��
	virtual void leftMove(void);   			 // ���ƶ�1��
	virtual void rightMove(void);  			 // ���ƶ�1��
	virtual void downMove(void);               // �����ƶ�1��
	virtual bool isTouch(char **map, char blockChar);    // �Ƿ���ײ(��Ҫ���뵱ǰ��ͼ)
	virtual int** getOccupiedGrid(void);       // ��ȡ����ռ�ݵĸ�������
};

class l_Block:public Block{
public:
	l_Block(int w, int h);
	virtual void leftRotate(void);			 // ����ת90��
	virtual void rightRotate(void);			 // ����ת90��
	virtual void leftMove(void);   			 // ���ƶ�1��
	virtual void rightMove(void);  			 // ���ƶ�1��
	virtual void downMove(void);               // �����ƶ�1��
	virtual bool isTouch(char **map, char blockChar);    // �Ƿ���ײ(��Ҫ���뵱ǰ��ͼ)
	virtual int** getOccupiedGrid(void);       // ��ȡ����ռ�ݵĸ�������
};

class T_Block:public Block{
public:
	T_Block(int w, int h);
	virtual void leftRotate(void);			 // ����ת90��
	virtual void rightRotate(void);			 // ����ת90��
	virtual void leftMove(void);   			 // ���ƶ�1��
	virtual void rightMove(void);  			 // ���ƶ�1��
	virtual void downMove(void);               // �����ƶ�1��
	virtual bool isTouch(char **map, char blockChar);    // �Ƿ���ײ(��Ҫ���뵱ǰ��ͼ)
	virtual int** getOccupiedGrid(void);       // ��ȡ����ռ�ݵĸ�������
};
