#include <stdio.h>
#include "blockio.h"
#include "string.h"

int sfs_delete(char *pathname){
	int index = inodeSearch(pathname);
	if(index < 0){
		return 0;
	}
	char* buf = malloc(128);
	put_block(index, buf);
	return 1;
}
