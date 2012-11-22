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
	char* superblock_0 = NULL;
	char* superblock_1 = NULL;
	char* inode[512];
	
	superblock_0 = (char*) calloc(10, sizeof(char));
	superblock_1 = (char*) calloc(10, sizeof(char));
	superblock_0 = "superblock_0";
	superblock_1 = "superblock_1";
	
	inode[0] = NULL;
	inode[1] = NULL;
	inode[2] = "inode 2";
	inode[3] = "inode 3";
	inode[4] = "inode 4";
	inode[5] = "inode 5";
	inode[6] = "inode 6";
	inode[7] = "inode 7";
	inode[8] = "inode 8";
	inode[9] = "inode 9";
	
	inode[10] = "0/";
	
	
	
	char* buf = NULL;
	buf = (char*) calloc(10, sizeof(char));

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
	if (put_block(0, superblock_0) != 0)
	{
		put_block(1, superblock_1);
		put_block(2, inode[10]);
		return -1;
	}
	
	else if(erase >= 1){
		//buf = (char*) calloc(10, sizeof(char))
			buf = "";
			put_block(0, buf);
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
		return -1;
	}
}
