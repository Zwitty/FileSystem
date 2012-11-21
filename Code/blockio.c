/***************************************************
* These routines provide block-oriented access to
* a simulated disk.
****************************************************/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <limits.h>
#include <unistd.h>
#include <stdio.h>

/* file  storing simulated disk's data */
#define DISKFILE "simdisk.data"
/* size of blocks on simulated disk */
#define BLKSIZE  128
/* number of blocks on simulated disk */
#define NUMBLKS  512
/* mode used to create disk file */
/* allows read and write by owner and by group */
#define DISKFILEMODE  S_IRUSR|S_IWUSR|S_IRWXG


/* descriptor of disk data file once opened
   negative value indicates that disk data file
   is not yet opened. */
static int diskfd = -1;

/************************************************
* init_disk()
*     - private function used to open the disk data file
*       a new file is created if one does not exist
*       newly created files read as all zeros
*     - returns 0 for success, -1 otherwise
*************************************************/
static int
init_disk()
{
  char garbage;

  if ((diskfd = open(DISKFILE,O_RDWR|O_CREAT,DISKFILEMODE)) < 0) {
    perror("opening disk data file");
    return(-1);
  }
  /* in case disk file is new, make sure it is as large as
     the simulated disk */
  /* this seek beyond end-of-file is supposed to create
     a hole which will read as zeros, so there should
     be no need to explicit initialization */
  if (lseek(diskfd,BLKSIZE*NUMBLKS,SEEK_SET) < 0) {
    perror("disk data file seek");
    return(-1);
  }
  if (write(diskfd,&garbage,1) < 0) {
    perror("disk data file write");
    return(-1);
  }
  return(0);
}

/************************************************
* get_block(blknum,buf)
*    - retrieves one block from the simulated disk
*      if disk file is not yet open, an attempt is
*      made to open it.
*
*    - blknum is the number of the desired block
*       (zero-based count)
*    - buf should point to a block-sized buffer
*
*    - Returns 0 if successful, -1 otherwise
*************************************************/
int
get_block(int blknum,
	  char *buf)
{
  if (blknum >= NUMBLKS || blknum < 0) {
    fprintf(stderr,"get_block: invalid block number: %d\n",blknum);
    return(-1);
  }
  if (diskfd < 0) {
    /* disk data file is not yet open - attempt to open it */
    if (init_disk() != 0) return(-1);
  }
  /* locate specified block */
  if (lseek(diskfd,blknum*BLKSIZE,SEEK_SET) < 0) {
    perror("get_block");
    return(-1);
  }
  /* get the data */
  if (read(diskfd,buf,BLKSIZE) < 0) {
    perror("get_block");
    return(-1);
  }
  return(0);
}

/************************************************
* put_block(blknum,buf)
*    - writes one block to the simulated disk
*      if disk file is not yet open, an attempt is
*      made to open it.
*
*    - blknum is the number of the desired block
*       (zero-based count)
*    - buf should point to a block-sized buffer
*
*    - Returns 0 if successful, -1 otherwise
*************************************************/
int
put_block(int blknum,
	  char *buf)
{
  if (blknum >= NUMBLKS || blknum < 0) {
    fprintf(stderr,"put_block: invalid block number: %d\n",blknum);
    return(-1);
  }
  if (diskfd < 0) {
    /* disk data file is not yet open - attempt to open it */
    if (init_disk() != 0) return(-1);
  }
  /* locate specified block */
  if (lseek(diskfd,blknum*BLKSIZE,SEEK_SET) < 0) {
    perror("put_block");
    return(-1);
  }
  /* get the data */
  if (write(diskfd,buf,BLKSIZE) < 0) {
    perror("put_block");
    return(-1);
  }
  return(0);
}
