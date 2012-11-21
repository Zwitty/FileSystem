typedef struct{
	char superblock_0[128];
	char superblock_1[128];
}superblock;

typedef struct{
	char type;
	char name[14][7];
	short int desination[14];
	char valid;
}folderblock;
