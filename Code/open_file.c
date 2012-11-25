#include <stdio.h>

//finds the index of the pathname and adds the index to the superblock
int sfs_open(char *pathname){
	int type = sfs_gettype(pathname);//checks to see if it is a file or directory.
	char chartype = (char)(((int)'0')+type);
	char* path2;
	path2 = malloc(128);
	append(path2, chartype);
	int q;
	for(q =0; q <strlen(pathname); q++){
		append(path2, pathname[q]);
	}
	int index = inodeSearch(path2);
	if(index < 0){
		return index;
	}
	if(type == 0){
		putSuperBlock(index);
	}
	if(type == 1){
		putDirSuperBlock(path2);
	}
	return type;
}
