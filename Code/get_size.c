#include <stdio.h>

int
sfs_getsize(char *pathname){
	char* path2;
	path2 = malloc(128);//allocate space
	append(path2, '0');//add a 0 to path2 indicating a file
	int q;
	for(q =0; q <strlen(pathname); q++){
		append(path2, pathname[q]);//adding the rest of the path onto path2 using the append funciton
	}
	int index = inodeSearch(path2);//retrieving the index
	char* buf;
	buf = malloc(128);
	int count = 0;
	if(index > 0){//get the block at index
		get_block(index+1, buf);

		int i;
		
		for(i = 0; i < 128; i++){
				if(buf[i] != '\0'){//while the value is not null increment the counter to find the size
					count = count + 1;
				}
			}
		return count;//return the size
	}else{
		return -1;
	}
	
}
