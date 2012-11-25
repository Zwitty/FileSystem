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

	put_block(0, fileChar);
	return 0;
}
//Gets the open files superblock_0
int getSuperBlock(){
	char* buf;
	buf = malloc(128);
	get_block(0, buf);
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
	put_block(1, buf);
	return 0;
}
//gets directory for superblock_1
char* getDirSuperBlock(){
	char* dir;
	dir = malloc(128);
	int i;
	get_block(1, dir);
	return dir;
}