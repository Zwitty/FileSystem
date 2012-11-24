#include <stdio.h>

int sfs_close(int fd){
	if(fd == 0){
		char* buf;
		buf = malloc(128);
		put_block(0,buf);//rewrites superblock 0 with nothing.
		return 1;
	}else{
		return fd;
	}
}
