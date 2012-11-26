#include <stdio.h>

//finds the index of the pathname and adds the index to the superblock
int sfs_open(char *pathname){
	int type = sfs_gettype(pathname);//checks to see if it is a file or directory.
	char chartype = (char)(((int)'0')+type);
	char* path2;
	path2 = malloc(128);//allocating space
	append(path2, chartype);//adding a pathname
	int q;
	for(q =0; q <strlen(pathname); q++){
		append(path2, pathname[q]);//appending the pathname into our char array
	}
	int index = inodeSearch(path2);//retrieving the index
	if(index < 0){//if index is negative we return an error
		return index;
	}
	if(type == 0){//if type is 0 we know we are opening a file
		return putSuperBlock(index) + 1;
	}
	if(type == 1){//if it is equal to 1 we are opening a directory at the path
		putDirSuperBlock(path2);
	}
	return type;//return the type of file that was opened
}
