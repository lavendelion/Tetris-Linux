#include"user.h"
#include<unistd.h>

UserInterface::UserInterface(void){
    tcgetattr(0,&initial_settings);
    new_settings = initial_settings;
    new_settings.c_lflag ^= ICANON;
    new_settings.c_lflag ^= ECHO;
    new_settings.c_lflag |= ISIG;
    new_settings.c_cc[VMIN] = 0;
    new_settings.c_cc[VTIME] = 0;
    tcsetattr(0, TCSANOW, &new_settings);

	key = -1;
}

UserInterface::~UserInterface(void){
	tcsetattr(0, TCSANOW, &initial_settings);
}

bool UserInterface::readKeyboard(void){
    unsigned char ch;
    int nread;
 
    if (key != -1) return true;
    nread = read(0,&ch,1);
    if(nread == 1) 
    {
        key = (int)ch;
        return true;
    }
    return false;
}

void UserInterface::operateBlock(Block *b){
	switch(key){
		case 119: b->leftRotate();break;  // 'w'
		case 115: b->rightRotate();break;  // 's'
		case 97: b->leftMove();break;  // 'a'
		case 100: b->rightMove();break;  // 'd'
		case 32: b->downMove();break;  // 'space'
		default: break;
	}
	key = -1;  // 操作完要把当前操作符清空
}

