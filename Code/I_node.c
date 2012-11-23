#include <stdio.h>
#include "blockio.h"

static char* inode[512];
char* inodeBlocks[7];
char buff[128];
//inode = (char*) calloc(7, sizeof(char));


int inodeSeach(char* path){
	inodeReadTable();
	char* temp;
	int i;
	for(i = 0; i < 512; i++){
		int m = 0;
		while(inode[i][m] != '!'){
			strcat(temp, inode[i][m]);
		}
	}
	return 0;
}
int inodeAdd(int type, char* path){
	int index;
	int i;
	char* temp;
	for (i=11; i<512; i++){
		char* temp;
		get_block(i, temp);
		if (temp[0] == '\0'){
			index = i;
			strcpy(inode[i], (const char*)index);
			strcpy(inode[i], (const char*)type);
			strcpy(inode[i], (const char*)path);
			break;
		}
	}
	return index;
}
int inodeRemove(char* info){
/*
	int index;
	int i;
	char* temp;
	for (i=11; i<512; i++){
		char* temp;
		get_block(i, temp);
		if (temp[0] == '\0'){
			index = i;
			strcpy(inode[i], (const char*)index);
			strcpy(inode[i], (const char*)type);
			strcpy(inode[i], (const char*)path);
			break;
		}
	}
	return index;*/
	return 0;
}
int inodeWriteTable(){
	put_block(2, inodeBlocks[0]);
	put_block(3, inodeBlocks[1]);
	put_block(4, inodeBlocks[2]);
	put_block(5, inodeBlocks[3]);
	put_block(6, inodeBlocks[4]);
	put_block(7, inodeBlocks[5]);
	put_block(8, inodeBlocks[6]);
	put_block(9, inodeBlocks[7]);
	return 0;
}
int inodeReadTable(){
	get_block(2, inodeBlocks[0]);
	get_block(3, inodeBlocks[1]);
	get_block(4, inodeBlocks[2]);
	get_block(5, inodeBlocks[3]);
	get_block(6, inodeBlocks[4]);
	get_block(7, inodeBlocks[5]);
	get_block(8, inodeBlocks[6]);
	get_block(9, inodeBlocks[7]);
	int j, k, i;
	char* temp;
	
	for (i = 0; i < 512; i++){
		for (j = 0; j < 8; j++) {
			for (k =0; k < 128; k++){
				if(inodeBlocks[j][k] == '!'){
				}else{
					strcat(temp, inodeBlocks[j][k]);
				}
			}
		}
		inode[i] = temp;
	}
	return 0;
}


