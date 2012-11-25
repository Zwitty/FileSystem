#include <stdio.h>

int sfs_read(int fd, int start, int length, char *mem_pointer){
	char* buf;
	buf = malloc(128);
	int index = getSuperBlock(fd);
	if(index == -1){//no file is open
		return -1;
	}else
		get_block(index+1, buf);
		int i;
		int space = start+length;
		//add formula check
		for(i = start; i < space; i++){
			mem_pointer[i-start] = buf[i];
		}
	return 1;
}
