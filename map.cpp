#include"map.h"
#include<stdio.h>
#include<iostream>
#include<stdlib.h>

Map::Map(int width, int height){
	this->w = width;
	this->h = height+6;
	map = new char*[this->h];
	for(int i=0;i<this->h;i++){
		map[i] = new char[this->w];
		for(int j=0;j<this->w;j++)
			map[i][j] = (i==4)?'-':(i==this->h-1)?blockChar:' ';
	}
}

Map::~Map(){
	for(int i=0;i<this->h;i++){
		delete[] map[i];
		map[i] = nullptr;
	}
	delete[] map;
	map = nullptr;
}

void Map::printMap(void){
	system("clear");
	printf("Score Now: %d\n", this->score);
	for(int i=0;i<this->h;i++){
		for(int j=0;j<this->w;j++)
			printf("%c ", map[i][j]);
		std::cout<<std::endl;
	}
}
	
bool Map::printBlock(Block *b){
	int **oG = b->getOccupiedGrid();
	map[oG[0][0]][oG[0][1]] = blockChar;
	map[oG[1][0]][oG[1][1]] = blockChar;
	map[oG[2][0]][oG[2][1]] = blockChar;
	map[oG[3][0]][oG[3][1]] = blockChar;
	system("clear");
	printf("Score Now: %d\n", this->score);
	for(int i=0;i<this->h;i++){
		for(int j=0;j<this->w;j++)
			printf("%c ", map[i][j]);
		std::cout<<std::endl;
	}
	if(b->isTouch(map, this->blockChar))
		return true;

	// 因为方块在移动，所以显示完毕后要恢复这些区域为空白
	map[oG[0][0]][oG[0][1]] = ' ';
	map[oG[1][0]][oG[1][1]] = ' ';
	map[oG[2][0]][oG[2][1]] = ' ';
	map[oG[3][0]][oG[3][1]] = ' ';
	return false;
}

void Map::refreshMap(void){
	char *thisLayer;
	int iLayer = this->h-2, k=iLayer;  // h-1层是地板
	int i;
	bool flag;
	while(k>4){
		thisLayer = map[k];
		flag=true;
		for(i=0;i<this->w;i++){
			if(thisLayer[i]!=blockChar){
				flag=false;
				break;
			}
		}
		if(flag){
			delete[] map[k];
			map[k] = nullptr;
			k--;
		}
		else{
			map[iLayer] = map[k];
			iLayer--;
			k--;
		}

	}
	while(iLayer>4){
		map[iLayer] = new char[this->w];
		for(i=0;i<this->w;i++){
			map[iLayer][i] = ' ';
		}
		iLayer--;
		score++;
	}
}

bool Map::isDead(void){
	char *layer = map[4];
	for(int i=0;i<this->w;i++){
		if(layer[i]==blockChar)
			return true;
	}
	return false;
}
