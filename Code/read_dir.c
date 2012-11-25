#include <stdio.h>

int
sfs_readdir(int fd, char *mem_pointer){
	char* openDir;
	openDir = malloc(128);
	openDir = getDirSuperBlock();
	
	char* buf;
	buf = malloc(128);
	append(buf, '0');
	int i;
	for(i = 1; i < strlen(openDir); i++){
		append(buf, openDir[i]);
	}
	char* temp;
	temp = malloc(128);
	char* temp2;
	temp2 = malloc(128);

	int check = 0;
	int j;
	for (j = 11; j < 512; j++){
		get_block(j,temp);
		if(strncmp(temp, buf, strlen(buf)) == 0){
			check = check + 1;
			if(check == fd){
				int k;
				for(k =1; k <strlen(temp); k++){//gets rid of file descriptor
					append(temp2, temp[k]);
				}
				strcpy(mem_pointer, temp2);
				return 1;
			}
		}
	}
	return 0;
}
