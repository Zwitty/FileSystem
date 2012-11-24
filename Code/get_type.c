#include <stdio.h>

int
sfs_gettype(char *pathname){
	char* path2;
	path2 = malloc(128);
	append(path2, '0');
	int q;
	for(q =0; q <strlen(pathname); q++){
		append(path2, pathname[q]);
	}
	int index = inodeSearch(path2);
	if(index > 0){
		return 0;
	}


	char* path3;
	path3 = malloc(128);
	append(path3, '1');
	int w;
	for(w =0; w <strlen(pathname); w++){
		append(path3, pathname[w]);
	}
	int index2 = inodeSearch(path3);
		if(index2 > 0){
		return 1;
	}else{
		return -1;

	}

	/*char* buf;
	buf = malloc(128);
	get_block(index, buf);
	char* fd;
	fd = strtok(buf,"/");*/
}
