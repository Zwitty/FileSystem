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
	
	char* buf = NULL;
	buf = (char*) calloc(10, sizeof(char));

	/* Simple way to write to disk*/	
	buf = "hello world";

	if (put_block(0, buf) != 0)
	{
		return -1;
	}
	/*
	if(erase >= 1){
		while(!eof("simdisk.data")){
			put_block(0, NULL);
		}
	}*/
	
	//put_block(0, NULL);
	return 0;
}
