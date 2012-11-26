#include <stdio.h>

int
sfs_readdir(int fd, char *mem_pointer){
	char* openDir;
	openDir = malloc(128);//allocating space
	openDir = getDirSuperBlock();//retrieing the data from super block
	
	char* buf;
	buf = malloc(128);//allocating space
	append(buf, '0');//appending a 0
	int i;
	for(i = 1; i < strlen(openDir); i++){
		append(buf, openDir[i]);//copying over the rest of the directory path
	}
	char* temp;
	temp = malloc(128);
	char* temp2;
	temp2 = malloc(128);

	int check = 0;
	int j;
	for (j = 11; j < 512; j++){
		get_block(j,temp);//get the block
		if(strncmp(temp, buf, strlen(buf)) == 0){//compare the strings
			check = check + 1;
			if(check == fd){
				int k;
				for(k =1; k <strlen(temp); k++){//gets rid of file descriptor
					append(temp2, temp[k]);
				}
				strcpy(mem_pointer, temp2);//copy the temp back to the pointer
				return 1;
			}
		}
	}
	return 0;
}
