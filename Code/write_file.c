#include <stdio.h>

//writes to the open file defined in the superblock.
//writes to the reserved block in simdisk.data
int sfs_write(int fd, int start, int length, char *mem_pointer){
	char* buf;
	buf = malloc(128);
	int index;
	index = getSuperBlock(fd); //returns open block.
	if(index == -1){
		return -1;
	}
	get_block(index+1, buf);//gets block
	int i;
	int space = start+length;//make sure we do not go over the 128 bytes allowed
	for(i = start; i < space; i++){
		buf[i] = mem_pointer[i-start];
	}
	put_block(index+1, buf);
	return 1;
}
