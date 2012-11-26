#include <stdio.h>
#include "blockio.h"
#include "string.h"
#include "stdlib.h"

//puts the requested index into the superblock_0
int putSuperBlock(int FileLoc){
	char* buf;
	buf = malloc(128);

	char* fileChar;
	fileChar = malloc(128);
	snprintf(fileChar, 127, "%d",FileLoc);
	int i;

	char* temp;
	temp = malloc(128);

	for(i = 0; i< 4; i++){
		get_block(i,temp);
		if(temp[0] == '0'){
			put_block(i, fileChar);	
			return i;	
		}
	}

	return -1;
}
//Gets the open files superblock_0
int getSuperBlock(int fd){
	char* buf;
	buf = malloc(128);
	get_block(fd-1, buf);
	int openFile =atoi(buf);
	return openFile;
}

//puts open directory into superblock_1
int putDirSuperBlock(char* openDir){
	char* buf;
	buf = malloc(128);
	int i;
	for(i=0; i< strlen(openDir); i++){
		append(buf, openDir[i]);
	}
	put_block(4, buf);
	return 0;
}
//gets directory for superblock_1
char* getDirSuperBlock(){
	char* dir;
	dir = malloc(128);
	int i;
	get_block(4, dir);
	return dir;
}