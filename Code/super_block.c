#include <stdio.h>
#include "blockio.h"
#include "string.h"
#include "stdlib.h"

//puts the requested index into the superblock
int putSuperBlock(int FileLoc){
	char* buf;
	buf = malloc(128);

	char* fileChar;
	fileChar = malloc(128);
	snprintf(fileChar, 127, "%d",FileLoc);

	put_block(0, fileChar);
	return 0;
}
//Gets the open files block
int getSuperBlock(){
	char* buf;
	buf = malloc(128);
	get_block(0, buf);
	int openFile =atoi(buf);
	return openFile;
}