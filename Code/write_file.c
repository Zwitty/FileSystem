#include <stdio.h>

int sfs_write(int fd, int start, int length, char *mem_pointer){
	if(fd != 0){
		return -1;
	}else{
		char* buf;
		buf = malloc(128);
		int index;
		index = getSuperBlock(); //returns open block.
		get_block(index+1, buf);
		int i;
		int space = start+length;
		for(i = start; i < space; i++){
			buf[i] = mem_pointer[i-start];
		}
		put_block(index+1, buf);
	}
		return 1;
}
