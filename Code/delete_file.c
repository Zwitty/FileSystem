#include <stdio.h>
#include "blockio.h"
#include "string.h"

int sfs_delete(char *pathname){
	char* path2;
	path2 = malloc(128);
	append(path2, '0');
	int q;
	for(q =0; q <strlen(pathname); q++){
		append(path2, pathname[q]);
	}

	int index = inodeSearch(path2);
	if(index < 0){
		return 0;
	}
	char* buf = malloc(128);
	put_block(index, buf);
	return 1;
}
