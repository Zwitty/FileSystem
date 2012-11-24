#include <stdio.h>
#include "blockio.h"
#include "string.h"

int sfs_create(char *pathname, int type){
	int index;
	index = inodeAdd(type, pathname);
//	index = 11;
	char* addToBlock;
	addToBlock = malloc(128);

	//strcpy(addToBlock, "added");
	char* chartype = (char)(((int)'0')+type);
	append(addToBlock, chartype);
	int i;
	for(i=0; i<strlen(pathname); i++){
		append(addToBlock, pathname[i]);
	}
	put_block(index, addToBlock);
	if(type == 0){
		//creates a block used to store data
		char* dataBuf;
		dataBuf = malloc(128);
		append(dataBuf, '!');//the "!" denotes an empty reserved data block
		put_block(index+1, dataBuf);
	}
	return 1;
}
