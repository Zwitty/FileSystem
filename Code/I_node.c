#include <stdio.h>
#include "string.h"
#include "blockio.h"

char* inode[512];
char* inodeBlocks[8];



char buff[128];
//inode = (char*) calloc(7, sizeof(char));

//

void append(char* s, char c)
{
        int len = strlen(s);
        s[len] = c;
        s[len+1] = '\0';
}
//Finds index of a specified path in simdisk.data
int inodeSearch(char* path){
	/*inodeReadTable();
	char* temp;
	int i;
	for(i = 0; i < 512; i++){
		int m = 0;
		while(inode[i][m] != '!'){
			append(temp, inode[i][m]);
			m = m + 1;
		}
	}
	return 0;*/

	//inodeReadTable();
	//inodeWriteTable();
	
	int i, j;
	int index = -1;
	char* temp, temp2;
	char* A;
	temp = malloc(128);//get info from get_block()
	for (i=11; i<512; i++){

		get_block(i, temp);
		//puts(A);
		if (temp[0] != '\0'){
			for(j = 0; j<128; j++){
				if(strncmp(temp, path, strlen(path)) == 0){
						index = i;
						break;
					}else{
						continue;
					}
			}
		}
	}
	//inodeWriteTable();
	return index;
}

//returns the index of simdisk.data to put the block - WORKS!
//adds the added path to the inode table - DOES NOT!
int inodeAdd(int type, char* path){
	inodeReadTable();
	//inodeWriteTable();
	int i;
	int index;
	char* chartype = (char)type;
	char* temp, temp2;
	temp = malloc(128);
	
	for (i=11; i<512; i++){
		//char* temp;
		//temp = malloc(128);
		get_block(i, temp);
		if (temp[0] == '\0'){
			index = i;
			//inode[i] = (char)index;
			temp2 = (char)index;
			//strcat(temp2, chartype);
			int p;
			for(p=0; p < strlen(path); p++){
				//append(temp2, path[p]);
			}
			inode[i] = temp2;
			break;
		}
	}
	//inodeWriteTable();
	return index;
	//inodeWriteTable();
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

//writes table into inode black
int inodeWriteTable(){
	int i, j;
	for(i=0; i<512; i++){
		for(j=0; j< 128; j++){
			append(inodeBlocks[0], inode[i][j]);
		}
	}
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
	//temp = inodeBlocks[0][0];
	/*int l;
	for(l=0; l<128; l++){
		if(inodeBlocks[0][l] == '!'){
				if(i < 512){
					inode[i] = temp;
					i = i + 1;
				}
			}else if(inodeBlocks[0][l] != '\0') {
				append(temp+1, inodeBlocks[0][l]);
			}else{
				continue;
		}
	}
	put_block(15, temp);*/
	int g;
	for(g=0; g<512; g++){
		inode[g] = malloc(20);
	}


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


