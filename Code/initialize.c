#include <stdio.h>
#include "blockio.h"
#include "string.h"

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
	
	char * superblock_0 = NULL;
	char * superblock_1 = NULL;
	char* inodein[512];

	superblock_0 = malloc(128);
	strcpy(superblock_0, "superblock_0");
	put_block(0, superblock_0);
	
//	memcpy(superblock_0, "superblock_0", sizeof(char));
	

	superblock_1 = malloc(128);
	strcpy(superblock_1, "superblock_0");
	inodein[0] = malloc(128);
	inodein[0] = NULL;
	inodein[1] = malloc(128);
	inodein[1] = NULL;
	
	inodein[2] = malloc(128);
	strcpy(inodein[2], "101/!");//first entry in inode
	
	inodein[3] = malloc(128);
	//strcpy(inode[3], "inode 3");

	inodein[4] = malloc(128);
	//strcpy(inode[4], "inode 4");

	inodein[5] = malloc(128);
	//strcpy(inode[5], "inode 5");

	inodein[6] = malloc(128);
	//strcpy(inode[6], "inode 6");

	inodein[7] = malloc(128);
	//strcpy(inode[7], "inode 7");

	inodein[8] = malloc(128);
	//strcpy(inode[8], "inode 8");

	inodein[9] = malloc(128);
	//strcpy(inode[9], "inode 9");



	//root
	inodein[10] = malloc(128);
	strcpy(inodein[10], "1/");
	
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
		put_block(2, inodein[10]);
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
		put_block(2, inodein[2]);
		put_block(3, inodein[3]);
		put_block(4, inodein[4]);
		put_block(5, inodein[5]);
		put_block(6, inodein[6]);
		put_block(7, inodein[7]);
		put_block(8, inodein[8]);
		put_block(9, inodein[9]);
		put_block(10, inodein[10]);
		get_block(10, inodein[10]);
		return 1;
	}
}
