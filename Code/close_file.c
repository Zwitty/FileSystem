#include <stdio.h>

//overwrites the superblock to close the file
int sfs_close(int fd){
	if (fd <= 4){
		char* buf;
		buf = malloc(128);
		strcpy(buf, "0");
		put_block(fd-1,buf);//rewrites superblock 0 with nothing.
		return 1;
	}else{
		return -1;
	}
}
