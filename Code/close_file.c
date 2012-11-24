#include <stdio.h>

int sfs_close(int fd){
	char* buf;
	buf = malloc(128);
	put_block(0,buf);//rewrites superblock 0 with nothing.
	return fd;
}
