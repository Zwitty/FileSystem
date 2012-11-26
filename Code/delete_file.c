#include <stdio.h>
#include "blockio.h"
#include "string.h"

//overwrites the pathblock in simdisk.data, it first finds the index.
int sfs_delete(char *pathname){
	char* path2;
	path2 = malloc(128);//allocating space for path2
	append(path2, '0');//add a 0 to path2
	int q;
	for(q =0; q <strlen(pathname); q++){//aadd the whole path nme using our append function to path2
		append(path2, pathname[q]);
	}

	int index = inodeSearch(path2);//we retrieve the index using inodesearch
	if(index < 0){//if index is negative we do not have a file at this location and we return an error
		return 0;
	}
	char* buf = malloc(128);//allocate space
	put_block(index, buf);//if the index is open we put the data in that block
	return 1;
}
