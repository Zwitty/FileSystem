#include <stdio.h>

int
sfs_getsize(char *pathname){
	char* path2;
	path2 = malloc(128);
	append(path2, '0');
	int q;
	for(q =0; q <strlen(pathname); q++){
		append(path2, pathname[q]);
	}
	int index = inodeSearch(path2);
	char* buf;
	buf = malloc(128);
	int count = 0;
	if(index > 0){
		get_block(index+1, buf);

		int i;
		
		for(i = 0; i < 128; i++){
				if(buf[i] != '\0'){
					count = count + 1;
				}
			}
		return count;
	}else{
		return -1;
	}
	
}
