#include"block.h"
#include<iostream>

Block::Block(int width, int height){
	this->w = width;
	this->h = height;
	// 随机生成方块姿势
	this->posture = rand() % 4;
	// 分配occupiedGrid空间
	this->occupiedGrid = new int*[4];
	for(int i=0;i<4;i++)
		this->occupiedGrid[i] = new int[2]();
}

Block::~Block(){
	for(int i=0;i<4;i++){
		delete[] this->occupiedGrid[i];
		this->occupiedGrid[i] = nullptr;
	}
	delete[] this->occupiedGrid;
	this->occupiedGrid = nullptr;
}

void Block::drop(void){
	this->pos[1] += 1;
}

/* implementation of L_Block */
L_Block::L_Block(int w, int h):Block(w,h){
	this->type = 'L';
	this->pos[0] = w/2;
	this->pos[1] = 1;
}

void L_Block::leftRotate(void){
	if(this->posture==0&&this->pos[0]==0) return;  // 边界情况
	if(this->posture==2&&this->pos[0]==this->w-1) return;  // 边界情况
	// 左旋转只需要将posture-1即可，注意0->3的情况
	this->posture = (this->posture + 3) % 4;
}

void L_Block::rightRotate(void){
	if(this->posture==0&&this->pos[0]==0) return;  // 边界情况
	if(this->posture==2&&this->pos[0]==this->w-1) return;  // 边界情况
	// 右旋转只需要将posture+1即可，注意3->0的情况
	this->posture = (this->posture + 1) % 4;
}

void L_Block::leftMove(void){
	switch(this->posture){
		case 0:
			if(this->pos[0]!=0)
				this->pos[0] -= 1;
			break;
		default:
			if(this->pos[0]!=1)
				this->pos[0] -= 1;
			break;
	}
}

void L_Block::rightMove(void){
	switch(this->posture){
		case 2:
			if(this->pos[0]!=this->w-1)
				this->pos[0] += 1;
			break;
		default:
			if(this->pos[0]!=this->w-2)
				this->pos[0] += 1;
			break;
	}
}

void L_Block::downMove(void){
	switch(this->posture){
		case 3:
			if(this->pos[1]!=this->h-2)
				this->pos[1]++;
			break;
		default:
			if(this->pos[1]!=this->h-3)
				this->pos[1]++;
			break;
	}
}

bool L_Block::isTouch(char **map, char blockChar){
	int row=this->pos[1], col=this->pos[0];
	switch(this->posture){
		case 0:
			if(map[row+2][col]==blockChar||map[row+2][col+1]==blockChar)
				return true;
			break;
		case 1:
			if(map[row+2][col-1]==blockChar||map[row+1][col]==blockChar||map[row+1][col+1]==blockChar)
				return true;
			break;
		case 2:
			if(map[row+2][col]==blockChar||map[row][col-1]==blockChar)
				return true;
			break;
		case 3:
			if(map[row+1][col-1]==blockChar||map[row+1][col]==blockChar||map[row+1][col+1]==blockChar)
				return true;
			break;
	}
	return false;
}

int** L_Block::getOccupiedGrid(void){
	int row=this->pos[1], col=this->pos[0];
	switch(this->posture){
		case 0:
			this->occupiedGrid[0][0]=row-1;
			this->occupiedGrid[0][1]=col;
			this->occupiedGrid[1][0]=row;
			this->occupiedGrid[1][1]=col;
			this->occupiedGrid[2][0]=row+1;
			this->occupiedGrid[2][1]=col;
			this->occupiedGrid[3][0]=row+1;
			this->occupiedGrid[3][1]=col+1;
			break;
		case 1:
			this->occupiedGrid[0][0]=row;
			this->occupiedGrid[0][1]=col+1;
			this->occupiedGrid[1][0]=row;
			this->occupiedGrid[1][1]=col;
			this->occupiedGrid[2][0]=row;
			this->occupiedGrid[2][1]=col-1;
			this->occupiedGrid[3][0]=row+1;
			this->occupiedGrid[3][1]=col-1;
			break;
		case 2:
			this->occupiedGrid[0][0]=row+1;
			this->occupiedGrid[0][1]=col;
			this->occupiedGrid[1][0]=row;
			this->occupiedGrid[1][1]=col;
			this->occupiedGrid[2][0]=row-1;
			this->occupiedGrid[2][1]=col;
			this->occupiedGrid[3][0]=row-1;
			this->occupiedGrid[3][1]=col-1;
			break;
		case 3:
			this->occupiedGrid[0][0]=row;
			this->occupiedGrid[0][1]=col-1;
			this->occupiedGrid[1][0]=row;
			this->occupiedGrid[1][1]=col;
			this->occupiedGrid[2][0]=row;
			this->occupiedGrid[2][1]=col+1;
			this->occupiedGrid[3][0]=row-1;
			this->occupiedGrid[3][1]=col+1;
			break;
	}
	return this->occupiedGrid;
}

/* implementation of R_Block */
R_Block::R_Block(int w, int h):Block(w,h){
	this->type = 'R';
	this->pos[0] = w/2;
	this->pos[1] = 1;
}

void R_Block::leftRotate(void){
	if(this->posture==2&&this->pos[0]==0) return;  // 边界情况
	if(this->posture==0&&this->pos[0]==this->w-1) return;  // 边界情况
	// 左旋转只需要将posture-1即可，注意0->3的情况
	this->posture = (this->posture + 3) % 4;
}

void R_Block::rightRotate(void){
	if(this->posture==2&&this->pos[0]==0) return;  // 边界情况
	if(this->posture==0&&this->pos[0]==this->w-1) return;  // 边界情况
	// 右旋转只需要将posture+1即可，注意3->0的情况
	this->posture = (this->posture + 1) % 4;
}

void R_Block::leftMove(void){
	switch(this->posture){
		case 2:
			if(this->pos[0]!=0)
				this->pos[0] -= 1;
			break;
		default:
			if(this->pos[0]!=1)
				this->pos[0] -= 1;
			break;
	}
}

void R_Block::rightMove(void){
	switch(this->posture){
		case 0:
			if(this->pos[0]!=this->w-1)
				this->pos[0] += 1;
			break;
		default:
			if(this->pos[0]!=this->w-2)
				this->pos[0] += 1;
			break;
	}
}

void R_Block::downMove(void){
	switch(this->posture){
		case 1:
			if(this->pos[1]<this->h-2)
				this->pos[1]++;
			break;
		default:
			if(this->pos[1]<this->h-3)
				this->pos[1]++;
			break;
	}
}

bool R_Block::isTouch(char **map, char blockChar){
	int row=this->pos[1], col=this->pos[0];
	switch(this->posture){
		case 0:
			if(map[row+2][col]==blockChar||map[row+2][col-1]==blockChar)
				return true;
			break;
		case 1:
			if(map[row+1][col-1]==blockChar||map[row+1][col]==blockChar||map[row+1][col+1]==blockChar)
				return true;
			break;
		case 2:
			if(map[row+2][col]==blockChar||map[row][col+1]==blockChar)
				return true;
			break;
		case 3:
			if(map[row+2][col+1]==blockChar||map[row+1][col]==blockChar||map[row+1][col-1]==blockChar)
				return true;
			break;
	}
	return false;
}

int** R_Block::getOccupiedGrid(void){
	int row=this->pos[1], col=this->pos[0];
	switch(this->posture){
		case 0:
			this->occupiedGrid[0][0]=row-1;
			this->occupiedGrid[0][1]=col;
			this->occupiedGrid[1][0]=row;
			this->occupiedGrid[1][1]=col;
			this->occupiedGrid[2][0]=row+1;
			this->occupiedGrid[2][1]=col;
			this->occupiedGrid[3][0]=row+1;
			this->occupiedGrid[3][1]=col-1;
			break;
		case 1:
			this->occupiedGrid[0][0]=row;
			this->occupiedGrid[0][1]=col-1;
			this->occupiedGrid[1][0]=row;
			this->occupiedGrid[1][1]=col;
			this->occupiedGrid[2][0]=row;
			this->occupiedGrid[2][1]=col+1;
			this->occupiedGrid[3][0]=row-1;
			this->occupiedGrid[3][1]=col-1;
			break;
		case 2:
			this->occupiedGrid[0][0]=row+1;
			this->occupiedGrid[0][1]=col;
			this->occupiedGrid[1][0]=row;
			this->occupiedGrid[1][1]=col;
			this->occupiedGrid[2][0]=row-1;
			this->occupiedGrid[2][1]=col;
			this->occupiedGrid[3][0]=row-1;
			this->occupiedGrid[3][1]=col+1;
			break;
		case 3:
			this->occupiedGrid[0][0]=row;
			this->occupiedGrid[0][1]=col-1;
			this->occupiedGrid[1][0]=row;
			this->occupiedGrid[1][1]=col;
			this->occupiedGrid[2][0]=row;
			this->occupiedGrid[2][1]=col+1;
			this->occupiedGrid[3][0]=row+1;
			this->occupiedGrid[3][1]=col+1;
			break;
	}
	return this->occupiedGrid;
}

/* implementation of O_Block */
O_Block::O_Block(int w, int h):Block(w,h){
	this->type = 'O';
	this->pos[0] = w/2+0.5;
	this->pos[1] = 1.5;
}

void O_Block::leftRotate(void){
	// 左旋转只需要将posture-1即可，注意0->3的情况
	this->posture = (this->posture + 3) % 4;
}

void O_Block::rightRotate(void){
	// 右旋转只需要将posture+1即可，注意3->0的情况
	this->posture = (this->posture + 1) % 4;
}

void O_Block::leftMove(void){
	if(this->pos[0]>0.5)
		this->pos[0] -= 1;
}

void O_Block::rightMove(void){
	if(this->pos[0]<this->w-1.5)
		this->pos[0] += 1;
}

void O_Block::downMove(void){
	if(this->pos[1]<this->h-1.5)
		this->pos[1]++;
}

bool O_Block::isTouch(char **map, char blockChar){
	int row=(int)this->pos[1], col=(int)this->pos[0];
	if(map[row+2][col]==blockChar||map[row+2][col+1]==blockChar)
		return true;
	return false;
}

int** O_Block::getOccupiedGrid(void){
	int row=(int)this->pos[1], col=(int)this->pos[0];
	this->occupiedGrid[0][0]=row;
	this->occupiedGrid[0][1]=col;
	this->occupiedGrid[1][0]=row;
	this->occupiedGrid[1][1]=col+1;
	this->occupiedGrid[2][0]=row+1;
	this->occupiedGrid[2][1]=col;
	this->occupiedGrid[3][0]=row+1;
	this->occupiedGrid[3][1]=col+1;
	return this->occupiedGrid;
}

/* implementation of Z_Block */
Z_Block::Z_Block(int w, int h):Block(w,h){
	this->type = 'Z';
	this->pos[0] = w/2;
	this->pos[1] = 1;
}

void Z_Block::leftRotate(void){
	if(this->posture%2==0&&this->pos[0]==this->w-1) return;  // 边界情况
	// 左旋转只需要将posture-1即可，注意0->3的情况
	this->posture = (this->posture + 3) % 4;
}

void Z_Block::rightRotate(void){
	if(this->posture%2==0&&this->pos[0]==this->w-1) return;  // 边界情况
	// 右旋转只需要将posture+1即可，注意3->0的情况
	this->posture = (this->posture + 1) % 4;
}

void Z_Block::leftMove(void){
	if(this->pos[0]>1)
		this->pos[0] -= 1;
}

void Z_Block::rightMove(void){
	switch(this->posture){
		case 0: ;
		case 2:
			if(this->pos[0]<this->w-1)
				this->pos[0] += 1;
			break;
		default:
			if(this->pos[0]<this->w-2)
				this->pos[0] += 1;
			break;
	}
}

void Z_Block::downMove(void){
	if(this->pos[1]<this->h-2)
		this->pos[1]++;
}

bool Z_Block::isTouch(char **map, char blockChar){
	int row=this->pos[1], col=this->pos[0];
	switch(this->posture){
		case 0:
			if(map[row+2][col-1]==blockChar||map[row+1][col]==blockChar)
				return true;
			break;
		case 1:
			if(map[row+1][col-1]==blockChar||map[row+2][col]==blockChar||map[row+2][col+1]==blockChar)
				return true;
			break;
		case 2:
			if(map[row+2][col-1]==blockChar||map[row+1][col]==blockChar)
				return true;
			break;
		case 3:
			if(map[row+1][col-1]==blockChar||map[row+2][col]==blockChar||map[row+2][col+1]==blockChar)
				return true;
			break;
	}
	return false;
}

int** Z_Block::getOccupiedGrid(void){
	int row=this->pos[1], col=this->pos[0];
	switch(this->posture){
		case 0:
			this->occupiedGrid[0][0]=row-1;
			this->occupiedGrid[0][1]=col;
			this->occupiedGrid[1][0]=row;
			this->occupiedGrid[1][1]=col;
			this->occupiedGrid[2][0]=row;
			this->occupiedGrid[2][1]=col-1;
			this->occupiedGrid[3][0]=row+1;
			this->occupiedGrid[3][1]=col-1;
			break;
		case 1:
			this->occupiedGrid[0][0]=row;
			this->occupiedGrid[0][1]=col-1;
			this->occupiedGrid[1][0]=row;
			this->occupiedGrid[1][1]=col;
			this->occupiedGrid[2][0]=row+1;
			this->occupiedGrid[2][1]=col;
			this->occupiedGrid[3][0]=row+1;
			this->occupiedGrid[3][1]=col+1;
			break;
		case 2:
			this->occupiedGrid[0][0]=row-1;
			this->occupiedGrid[0][1]=col;
			this->occupiedGrid[1][0]=row;
			this->occupiedGrid[1][1]=col;
			this->occupiedGrid[2][0]=row;
			this->occupiedGrid[2][1]=col-1;
			this->occupiedGrid[3][0]=row+1;
			this->occupiedGrid[3][1]=col-1;
			break;
		case 3:
			this->occupiedGrid[0][0]=row;
			this->occupiedGrid[0][1]=col-1;
			this->occupiedGrid[1][0]=row;
			this->occupiedGrid[1][1]=col;
			this->occupiedGrid[2][0]=row+1;
			this->occupiedGrid[2][1]=col;
			this->occupiedGrid[3][0]=row+1;
			this->occupiedGrid[3][1]=col+1;
			break;
	}
	return this->occupiedGrid;
}

/* implementation of N_Block */
N_Block::N_Block(int w, int h):Block(w,h){
	this->type = 'N';
	this->pos[0] = w/2;
	this->pos[1] = 1;
}

void N_Block::leftRotate(void){
	if(this->posture%2==0&&this->pos[0]==0) return;  // 边界情况
	// 左旋转只需要将posture-1即可，注意0->3的情况
	this->posture = (this->posture + 3) % 4;
}

void N_Block::rightRotate(void){
	if(this->posture%2==0&&this->pos[0]==0) return;  // 边界情况
	// 右旋转只需要将posture+1即可，注意3->0的情况
	this->posture = (this->posture + 1) % 4;
}


void N_Block::leftMove(void){
	switch(this->posture){
		case 0: ;
		case 2:
			if(this->pos[0]>0)
				this->pos[0] -= 1;
			break;
		default:
			if(this->pos[0]>1)
				this->pos[0] -= 1;
			break;
	}
}

void N_Block::rightMove(void){
	if(this->pos[0]<this->w-2)
		this->pos[0] += 1;
}

void N_Block::downMove(void){
	if(this->pos[1]<this->h-2)
		this->pos[1]++;
}

bool N_Block::isTouch(char **map, char blockChar){
	int row=this->pos[1], col=this->pos[0];
	switch(this->posture){
		case 0:
			if(map[row+2][col+1]==blockChar||map[row+1][col]==blockChar)
				return true;
			break;
		case 1:
			if(map[row+1][col+1]==blockChar||map[row+2][col]==blockChar||map[row+2][col-1]==blockChar)
				return true;
			break;
		case 2:
			if(map[row+2][col+1]==blockChar||map[row+1][col]==blockChar)
				return true;
			break;
		case 3:
			if(map[row+1][col+1]==blockChar||map[row+2][col]==blockChar||map[row+2][col-1]==blockChar)
				return true;
			break;
	}
	return false;
}

int** N_Block::getOccupiedGrid(void){
	int row=this->pos[1], col=this->pos[0];
	switch(this->posture){
		case 0:
			this->occupiedGrid[0][0]=row-1;
			this->occupiedGrid[0][1]=col;
			this->occupiedGrid[1][0]=row;
			this->occupiedGrid[1][1]=col;
			this->occupiedGrid[2][0]=row;
			this->occupiedGrid[2][1]=col+1;
			this->occupiedGrid[3][0]=row+1;
			this->occupiedGrid[3][1]=col+1;
			break;
		case 1:
			this->occupiedGrid[0][0]=row;
			this->occupiedGrid[0][1]=col+1;
			this->occupiedGrid[1][0]=row;
			this->occupiedGrid[1][1]=col;
			this->occupiedGrid[2][0]=row+1;
			this->occupiedGrid[2][1]=col;
			this->occupiedGrid[3][0]=row+1;
			this->occupiedGrid[3][1]=col-1;
			break;
		case 2:
			this->occupiedGrid[0][0]=row-1;
			this->occupiedGrid[0][1]=col;
			this->occupiedGrid[1][0]=row;
			this->occupiedGrid[1][1]=col;
			this->occupiedGrid[2][0]=row;
			this->occupiedGrid[2][1]=col+1;
			this->occupiedGrid[3][0]=row+1;
			this->occupiedGrid[3][1]=col+1;
			break;
		case 3:
			this->occupiedGrid[0][0]=row;
			this->occupiedGrid[0][1]=col+1;
			this->occupiedGrid[1][0]=row;
			this->occupiedGrid[1][1]=col;
			this->occupiedGrid[2][0]=row+1;
			this->occupiedGrid[2][1]=col;
			this->occupiedGrid[3][0]=row+1;
			this->occupiedGrid[3][1]=col-1;
			break;
	}
	return this->occupiedGrid;
}

/* implementation of l_Block */
l_Block::l_Block(int w, int h):Block(w,h){
	this->type = 'N';
	this->pos[0] = w/2+0.5;
	this->pos[1] = 2.5;
}

void l_Block::leftRotate(void){
	if(this->posture%2==0&&this->pos[0]<=1) return;  // 边界情况
	if(this->posture%2==0&&this->pos[0]>=this->w-2) return;  // 边界情况
	// 左旋转只需要将posture-1即可，注意0->3的情况
	this->posture = (this->posture + 3) % 4;
}

void l_Block::rightRotate(void){
	if(this->posture%2==0&&this->pos[0]<=1) return;  // 边界情况
	if(this->posture%2==0&&this->pos[0]>=this->w-2) return;  // 边界情况
	// 右旋转只需要将posture+1即可，注意3->0的情况
	this->posture = (this->posture + 1) % 4;
}

void l_Block::leftMove(void){
	switch(this->posture){
		case 0: ;
		case 2:
			if(this->pos[0]>0.5)
				this->pos[0] -= 1;
			break;
		default:
			if(this->pos[0]>1.5)
				this->pos[0] -= 1;
			break;
	}
}

void l_Block::rightMove(void){
	switch(this->posture){
		case 0: ;
		case 2:
			if(this->pos[0]<this->w-0.5)
				this->pos[0] += 1;
			break;
		default:
			if(this->pos[0]<this->w-2.5)
				this->pos[0] += 1;
			break;
	}
}

void l_Block::downMove(void){
	switch(this->posture){
		case 0: ;
		case 2:
			if(this->pos[1]<this->h-3.5)
				this->pos[1] += 1;
			break;
		default:
			if(this->pos[1]<this->h-1.5)
				this->pos[1] += 1;
			break;
	}
}

bool l_Block::isTouch(char **map, char blockChar){
	int row=(int)this->pos[1], col=(int)this->pos[0];
	switch(this->posture){
		case 0:
			if(map[row+3][col]==blockChar)
				return true;
			break;
		case 1:
			if(map[row+1][col-1]==blockChar||map[row+1][col]==blockChar||map[row+1][col+1]==blockChar||map[row+1][col+2]==blockChar)
				return true;
			break;
		case 2:
			if(map[row+3][col]==blockChar)
				return true;
			break;
		case 3:
			if(map[row+1][col-1]==blockChar||map[row+1][col]==blockChar||map[row+1][col+1]==blockChar||map[row+1][col+2]==blockChar)
				return true;
			break;
	}
	return false;
}

int** l_Block::getOccupiedGrid(void){
	int row=(int)this->pos[1], col=(int)this->pos[0];
	switch(this->posture){
		case 0:
			this->occupiedGrid[0][0]=row-1;
			this->occupiedGrid[0][1]=col;
			this->occupiedGrid[1][0]=row;
			this->occupiedGrid[1][1]=col;
			this->occupiedGrid[2][0]=row+1;
			this->occupiedGrid[2][1]=col;
			this->occupiedGrid[3][0]=row+2;
			this->occupiedGrid[3][1]=col;
			break;
		case 1:
			this->occupiedGrid[0][0]=row;
			this->occupiedGrid[0][1]=col-1;
			this->occupiedGrid[1][0]=row;
			this->occupiedGrid[1][1]=col;
			this->occupiedGrid[2][0]=row;
			this->occupiedGrid[2][1]=col+1;
			this->occupiedGrid[3][0]=row;
			this->occupiedGrid[3][1]=col+2;
			break;
		case 2:
			this->occupiedGrid[0][0]=row-1;
			this->occupiedGrid[0][1]=col;
			this->occupiedGrid[1][0]=row;
			this->occupiedGrid[1][1]=col;
			this->occupiedGrid[2][0]=row+1;
			this->occupiedGrid[2][1]=col;
			this->occupiedGrid[3][0]=row+2;
			this->occupiedGrid[3][1]=col;
			break;
		case 3:
			this->occupiedGrid[0][0]=row;
			this->occupiedGrid[0][1]=col-1;
			this->occupiedGrid[1][0]=row;
			this->occupiedGrid[1][1]=col;
			this->occupiedGrid[2][0]=row;
			this->occupiedGrid[2][1]=col+1;
			this->occupiedGrid[3][0]=row;
			this->occupiedGrid[3][1]=col+2;
			break;
	}
	return this->occupiedGrid;
}

/* implementation of T_Block */
T_Block::T_Block(int w, int h):Block(w,h){
	this->type = 'T';
	this->pos[0] = w/2;
	this->pos[1] = 2;
}

void T_Block::leftRotate(void){
	if(this->posture==1&&this->pos[0]==0) return;  // 边界情况
	if(this->posture==3&&this->pos[0]==this->w-1) return;  // 边界情况
	// 左旋转只需要将posture-1即可，注意0->3的情况
	this->posture = (this->posture + 3) % 4;
}

void T_Block::rightRotate(void){
	if(this->posture==1&&this->pos[0]==0) return;  // 边界情况
	if(this->posture==3&&this->pos[0]==this->w-1) return;  // 边界情况
	// 右旋转只需要将posture+1即可，注意3->0的情况
	this->posture = (this->posture + 1) % 4;
}

void T_Block::leftMove(void){
	switch(this->posture){
		case 1:
			if(this->pos[0]>0)
				this->pos[0] -= 1;
			break;
		default:
			if(this->pos[0]>1)
				this->pos[0] -= 1;
			break;
	}
}

void T_Block::rightMove(void){
	switch(this->posture){
		case 3:
			if(this->pos[0]<this->w-1)
				this->pos[0] += 1;
			break;
		default:
			if(this->pos[0]<this->w-2)
				this->pos[0] += 1;
			break;
	}
}

void T_Block::downMove(void){
	switch(this->posture){
		case 0:
			if(this->pos[1]<this->h-2)
				this->pos[1]++;
			break;
		default:
			if(this->pos[1]<this->h-3)
				this->pos[1]++;
			break;
	}
}

bool T_Block::isTouch(char **map, char blockChar){
	int row=this->pos[1], col=this->pos[0];
	switch(this->posture){
		case 0:
			if(map[row+1][col-1]==blockChar||map[row+1][col]==blockChar||map[row+1][col+1]==blockChar)
				return true;
			break;
		case 1:
			if(map[row+2][col]==blockChar||map[row+1][col+1]==blockChar)
				return true;
			break;
		case 2:
			if(map[row+1][col-1]==blockChar||map[row+2][col]==blockChar||map[row+1][col+1]==blockChar)
				return true;
			break;
		case 3:
			if(map[row+2][col]==blockChar||map[row+1][col-1]==blockChar)
				return true;
			break;
	}
	return false;
}

int** T_Block::getOccupiedGrid(void){
	int row=this->pos[1], col=this->pos[0];
	switch(this->posture){
		case 0:
			this->occupiedGrid[0][0]=row-1;
			this->occupiedGrid[0][1]=col;
			this->occupiedGrid[1][0]=row;
			this->occupiedGrid[1][1]=col;
			this->occupiedGrid[2][0]=row;
			this->occupiedGrid[2][1]=col-1;
			this->occupiedGrid[3][0]=row;
			this->occupiedGrid[3][1]=col+1;
			break;
		case 1:
			this->occupiedGrid[0][0]=row-1;
			this->occupiedGrid[0][1]=col;
			this->occupiedGrid[1][0]=row;
			this->occupiedGrid[1][1]=col;
			this->occupiedGrid[2][0]=row;
			this->occupiedGrid[2][1]=col+1;
			this->occupiedGrid[3][0]=row+1;
			this->occupiedGrid[3][1]=col;
			break;
		case 2:
			this->occupiedGrid[0][0]=row+1;
			this->occupiedGrid[0][1]=col;
			this->occupiedGrid[1][0]=row;
			this->occupiedGrid[1][1]=col;
			this->occupiedGrid[2][0]=row;
			this->occupiedGrid[2][1]=col-1;
			this->occupiedGrid[3][0]=row;
			this->occupiedGrid[3][1]=col+1;
			break;
		case 3:
			this->occupiedGrid[0][0]=row;
			this->occupiedGrid[0][1]=col-1;
			this->occupiedGrid[1][0]=row;
			this->occupiedGrid[1][1]=col;
			this->occupiedGrid[2][0]=row+1;
			this->occupiedGrid[2][1]=col;
			this->occupiedGrid[3][0]=row-1;
			this->occupiedGrid[3][1]=col;
			break;
	}
	return this->occupiedGrid;
}

