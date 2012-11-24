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

	//defines super block
	superblock_0 = malloc(128);
	strcpy(superblock_0, "superblock_0");
	superblock_1 = malloc(128);
	strcpy(superblock_1, "superblock_1");

	//defines room for inode table
	inodein[0] = malloc(128);
	inodein[0] = NULL;//superblock
	inodein[1] = malloc(128);
	inodein[1] = NULL;//superblock
	inodein[2] = malloc(128);
	strcpy(inodein[2], "101/!");//first entry in inode
	inodein[3] = malloc(128);
	inodein[4] = malloc(128);
	inodein[5] = malloc(128);
	inodein[6] = malloc(128);
	inodein[7] = malloc(128);
	inodein[8] = malloc(128);
	inodein[9] = malloc(128);



	//root
	inodein[10] = malloc(128);
	strcpy(inodein[10], "1/");
	
	if(erase >= 1){
		char* buf;
		buf = malloc(128);
		int i;
		for(i=0; i<512; i++){
			put_block(i, buf);
		}
		return 2;
	}else{	
		put_block(0, superblock_0);
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
		return 1;
	}
}
