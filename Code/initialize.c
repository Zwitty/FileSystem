#include <stdio.h>
#include "sfstest.h"
#include "blockio.h"

static int openfile;
/*
int sfs_initialize(int erase){
if (simdisk.data != open)
function opens simdisk.data 
end if
int fileblock = search(erase)//finds file block in simdisk.data.
if (simdisk.data == NULL)
	return 0;
End if
if (erase >=1)
	while(!eof(simdisk.data))
		fileblock = NULL;
	End While

End if
return 1;

}
*/
int sfs_initialize(int erase){
	/*folderblock root;
	char temp[128];
	printf("gg");
	openfile = 0;*/
	char * superblock_0 = NULL;
	char * superblock_1 = NULL;
	char* inode[512];
	//superblock_0 = (char*) calloc(128, sizeof(char));
	/*memcpy(superblock_0, (char*)temp, sizeof(char));
	memcpy(superblock_0, 'e', sizeof(char));
	memcpy(superblock_0, 's', sizeof(char));
	memcpy(superblock_0, 't', sizeof(char));*/
	//superblock_0 = "superblock_0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
	superblock_0 = malloc(128);
	strcpy(superblock_0, "superblock_0");
	put_block(0, superblock_0);
	
//	memcpy(superblock_0, "superblock_0", sizeof(char));
	

	superblock_1 = malloc(128);
	strcpy(superblock_1, "superblock_0");
	
	//superblock_1 = "superblock_1\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
	inode[0] = malloc(128);
	inode[0] = NULL;
	inode[1] = malloc(128);
	inode[1] = NULL;
	
	inode[2] = malloc(128);
	strcpy(inode[2], "100/!");
	
	inode[3] = malloc(128);
	//strcpy(inode[3], "inode 3");

	inode[4] = malloc(128);
	//strcpy(inode[4], "inode 4");

	inode[5] = malloc(128);
	//strcpy(inode[5], "inode 5");

	inode[6] = malloc(128);
	//strcpy(inode[6], "inode 6");

	inode[7] = malloc(128);
	//strcpy(inode[7], "inode 7");

	inode[8] = malloc(128);
	//strcpy(inode[8], "inode 8");

	inode[9] = malloc(128);
	//strcpy(inode[9], "inode 9");



	//root
	inode[10] = malloc(128);
	strcpy(inode[10], "0/");

	
	
	
	//char* buf = NULL;
	//buf = (char*) calloc(10, sizeof(char));

	/* Simple way to write to disk*/	
//	buf = "Matthew Clark is Awesome~wertyuioiuytrewertyuiouytre";
	
/*	int m =0;
	while(m < 511){
		if(m > 512){
			break;
		} 
		if(m > 10){
			inode[m] = NULL;
		}
		if(put_block(m, inode[m]) != 0){
			printf(m);
		}
		m = m +1;
	}*/
	if (put_block(100, superblock_0) != 0)
	{
		put_block(1, superblock_1);
		put_block(2, inode[10]);
		return -1;
	}
	
	else if(erase >= 1){
		//buf = (char*) calloc(10, sizeof(char))
			//buf = "";
			//put_block(0, buf);
			return -1;
		}else{	
	//put_block(0, NULL);
		put_block(1, superblock_1);
		put_block(2, inode[2]);
		put_block(3, inode[3]);
		put_block(4, inode[4]);
		put_block(5, inode[5]);
		put_block(6, inode[6]);
		put_block(7, inode[7]);
		put_block(8, inode[8]);
		put_block(9, inode[9]);
		put_block(10, inode[10]);
		return 0;
	}
}
