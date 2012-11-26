#include <stdio.h>
#include "blockio.h"
#include "string.h"

//creates a file or directory
int sfs_create(char *pathname, int type){
	int index;
	index = inodeAdd(type, pathname);//retrieving the index
	if(pathname[0] != '/')//if the first index in path is not a slash we return an error
	{
		return -1;
	}
	if(index == -1){//if our index is negative we have to file there so we return an error
		return -1;
	}

	int p;
	int count = 0;
	for(p=1; p<strlen(pathname);p++){
		if(pathname[p] != '/'){//checking each value that is not equal to a slash
			count = count + 1;//increment count
		}
		if(pathname[p] == '/'){//if our value is equal to a slash we reset count
			count = 0;
		}
		if(count > 6){	//if the file has more than 6 values we return an error
			return -1;
		}
	}

	char* addToBlock;
	addToBlock = malloc(128);//allocating space

	char* chartype = (char)(((int)'0')+type);
	append(addToBlock, chartype);//appending a 0 to the addToBlock array
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
