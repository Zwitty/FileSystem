#include <stdio.h>
#include "string.h"
#include "blockio.h"

char* inode[512];
char* inodeBlocks[8];



char buff[128];


//Finds index of a specified path in simdisk.data
int inodeSearch(char* path){

	int i, j;
	int index = -1;
	char* temp, temp2;
	char* A;
	temp = malloc(128);//get info from get_block()
	for (i=11; i<512; i++){

		get_block(i, temp);
		if (temp[0] != '\0'){
			if(strncmp(temp, path, strlen(path)) == 0){
					index = i;
					break;
				}else{
					continue;
				}
		}
	}
	return index;
}

//returns the index of an empty block in simdisk.data to put the block
int inodeAdd(int type, char* path){
	inodeReadTable();
	int i;
	int index = -1;
	char* chartype = (char)type;
	char* temp, temp2;
	temp = malloc(128);
	
	for (i=11; i<512; i++){
		get_block(i, temp);
		if (temp[0] == '\0'){
			index = i;
			temp2 = (char)index;
			inode[i] = temp2;
			break;
		}
	}
	return index;
}


//reades the inode table and stores data into inode array.
int inodeReadTable(){
	inodeBlocks[0] = malloc(128);
	inodeBlocks[1] = malloc(128);
	inodeBlocks[2] = malloc(128);
	inodeBlocks[3] = malloc(128);
	inodeBlocks[4] = malloc(128);
	inodeBlocks[5] = malloc(128);
	inodeBlocks[6] = malloc(128);
	inodeBlocks[7] = malloc(128);
	get_block(2, inodeBlocks[0]);
	get_block(3, inodeBlocks[1]);
	get_block(4, inodeBlocks[2]);
	get_block(5, inodeBlocks[3]);
	get_block(6, inodeBlocks[4]);
	get_block(7, inodeBlocks[5]);
	get_block(8, inodeBlocks[6]);
	get_block(9, inodeBlocks[7]);
	int j, k;
	int i = 0;
	char* temp;
	temp = malloc(128);

	int g;
   //allocating space
	for(g=0; g<512; g++){
		inode[g] = malloc(20);
	}

  //creating the inode table
	for (j = 0; j < 8; j++) {
		for (k =0; k < 128; k++){
			if(inodeBlocks[j][k] == '!'){
				if(i < 512){
					inode[i] = temp;
					i = i + 1;
				}
			}else if(inodeBlocks[j][k] != '\0') {
				append(temp, inodeBlocks[j][k]);
			}else{
				continue;
			}
		}
	
	}
	return 0;
}


