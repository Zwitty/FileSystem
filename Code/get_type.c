#include <stdio.h>


//Checks the files descriptor in the simdisk.data block for the pathname.
int
sfs_gettype(char *pathname){


	//checks to see if the path contains a directory
	char* buf2;
	buf2 = malloc(128);
	char* path3;
	path3 = malloc(128);
	append(path3, '1');
	int w;
	for(w =0; w <strlen(pathname); w++){
		append(path3, pathname[w]);
	}
	int index2 = inodeSearch(path3);
	if(index2 > 0){
		get_block(index2, buf2);
	}
	if(buf2[0] == '1'){
		return 1;//returns 1 for directory
	}

	//checks to see if the path contains a file
	char* buf1;
	buf1 = malloc(128);
	char* path2;
	path2 = malloc(128);
	append(path2, '0');
	int q;
	for(q =0; q <strlen(pathname); q++){
		append(path2, pathname[q]);
	}
	int index = inodeSearch(path2);//returns the index of the block
	if(index > 0){
		get_block(index, buf1);
		if(buf1[0] == '0'){
			return 0;//returns 0 for path
		}
	}else{
		return -1;//returns -1 for undefined

	}
}
