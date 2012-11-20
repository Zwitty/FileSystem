/****************************************************
  This is a simple interactive test program for use
  with the file system interface functions.   
  To use this program, compile it and link 
  it with your implementation of the
  file system functions, and with the blockio functions.

  The program will print out a list of available commands
  and then prompt for a command.  There is one command for
  each function in the file system interface.

  This program is very simple.  It does minimal error checking
   and recovery.  All data written to and read from files passes
   through a single buffer (io_buffer).  Only printable ASCII
   characters may be written to files.  Non-printable characters
   read from files will not be displayed properly.

  You are free to make a copy of this program and to modify your
   copy for the purposes of testing your file system implementation.
******************************************************/
#include <stdio.h>

/*****************************************************
   templates for the sfs interface functions
******************************************************/

int
sfs_open(char *pathname);

int
sfs_read(int fd,
	 int start,
	 int length,
	 char *mem_pointer);

int
sfs_write(int fd,
	  int start,
	  int length,
	  char *mem_pointer);

int
sfs_readdir(int fd,
	    char *mem_pointer);

int
sfs_close(int fd);

int
sfs_delete(char *pathname);

int
sfs_create(char *pathname,
	   int type);

int
sfs_getsize(char *pathname);

int
sfs_gettype(char *pathname);

int
sfs_initialize(int erase);



/*****************************************************
   Program constants
******************************************************/

/* This is the maximum number of bytes that can be read from
   or written to a file with a single file system call using this
   program.  Since files are limited
   to 512 bytes length, this should be sufficient. */
/* the format definition is necessary because macro substitutions
   do not take place within quoted strings */
#define MAX_IO_LENGTH   1024       /* I CHANGED IT FROM 512--->1024 */
#define IO_BUF_FORMAT   "%512s"

/* This is the maximum length of input strings (e.g., file names) read from
   the standard input.  This should be large enough for most purposes. */
/* the format definition is necessary because macro substitutions
   do not take place within quoted strings */
#define MAX_INPUT_LENGTH  512
#define INPUT_BUF_FORMAT  "%1024s"

/*****************************************************
   Global data structures
******************************************************/

/* buffer to hold commands read from standard input */
char command_buffer[MAX_INPUT_LENGTH+1];

/* buffer to hold data going to/from the disk */
char io_buffer[MAX_IO_LENGTH+1];

/* the following is used to hold string input parameters, such as file names */
char data_buffer_1[MAX_INPUT_LENGTH];
/* the following are used to hold integer input parameters */
int p1,p2,p3;



/*****************************************************
   main test routine
******************************************************/

main()
{
  int i;
  int retval;  /* used to hold return values of file system calls */

  /* do forever:
     1) print a list of available commands
     2) read a command
     3) read arguments for the command
     4) perform the requested operation
     5) display the results of the operation
  */
  while(1) {
    /* print a list of available commands */
    printf("\n");
    printf("o: open a file\n");
    printf("r: read from a file\n");
    printf("w: write to a file\n");
    printf("R: read from a directory\n");
    printf("c: close a file\n");
    printf("m: create (make) a new file\n");
    printf("d: delete a file\n");
    printf("s: get the size of a file\n");
    printf("t: get the type of a file\n");
    printf("i: initialize the file system\n");
    printf("q: quit - exit this program\n");
    /* read in the next command */
    printf("\nCommand? ");
    if (gets(command_buffer) == NULL) break;
    /* determine which command was requested */
    switch(command_buffer[0]) {
    case 'o':
      /* Open a file */
      printf("Enter full path name of file to open: ");
      scanf(INPUT_BUF_FORMAT,data_buffer_1);
      retval = sfs_open(data_buffer_1);
      if (retval >= 0) {
	printf("Open succeeded.  File Descriptor number is %d\n",retval);
      }
      else {
	printf("Error.  Return value was %d\n",retval);
      }
      break;
    case 'r':
      /* Read from a file */
      printf("Enter file descriptor number: ");
      scanf("%d",&p1);
      printf("Enter read start location: ");
      scanf("%d",&p2);
      printf("Enter number of bytes to read: ");
      scanf("%d",&p3);
      retval = sfs_read(p1,p2,p3,io_buffer);
      if (retval > 0) {
	printf("Read succeeded.\n");
	printf("The following data was read (only printable ASCII will display)\n");
	for(i=0;i<p3;i++) {
	  putchar(io_buffer[i]);
	}
	printf("\n");
      }
      else {
	printf("Error.  Return value was %d\n",retval);
      }
      break;
    case 'w':
      /* Write to a file */

      printf("Enter file descriptor number: ");
      scanf("%d",&p1);
      printf("Enter write start location: ");
      scanf("%d",&p2);
      printf("Enter number of bytes to write: ");
      scanf("%d",&p3);
      printf("This program allows only non-white-space, printable ASCII characters to be written to a file.\n");
      printf("Enter %d characters to be written: ",p3);
      scanf(IO_BUF_FORMAT,io_buffer);
      retval = sfs_write(p1,p2,p3,io_buffer);
      if (retval > 0) {
	printf("Write succeeded.\n");
	printf("Wrote %s to the disk\n",io_buffer);
      }
      else {
	printf("Error.  Return value was %d\n",retval);
      }
      break;
    case 'R':
      /* Read from a directory */
      printf("Enter file descriptor number: ");
      scanf("%d",&p1);
      retval = sfs_readdir(p1,io_buffer);
      if (retval > 0) {
	printf("sfs_readdir succeeded.\n");
	printf("Directory entry is: %s\n",io_buffer);
      }
      else if (retval == 0) {
	printf("sfs_readdir succeeded.\n");
	printf("No more entries in this directory\n");
      }
      else {
	printf("Error.  Return value was %d\n",retval);
      }
      break;
    case 'c':
      /* Close a file */
      printf("Enter file descriptor number: ");
      scanf("%d",&p1);
      retval = sfs_close(p1);
      if (retval > 0) {
	printf("sfs_close succeeded.\n");
      }
      else {
	printf("Error.  Return value was %d\n",retval);
      }
      break;
    case 'm':
      /* Create a new file */
      printf("Enter full path name of new file: ");
      scanf(INPUT_BUF_FORMAT,data_buffer_1);
      printf("Enter 0 for regular file, 1 for directory: ");
      scanf("%d",&p1);
      retval = sfs_create(data_buffer_1,p1);
      if (retval > 0) {
	printf("sfs_create succeeded.\n");
      }
      else {
	printf("Error.  Return value was %d\n",retval);
      }
      break;
    case 'd':
      /* Delete a file */
      printf("Enter full path name of file to delete: ");
      scanf(INPUT_BUF_FORMAT,data_buffer_1);
      retval = sfs_delete(data_buffer_1);
      if (retval > 0) {
	printf("sfs_delete succeeded.\n");
      }
      else {
	printf("Error.  Return value was %d\n",retval);
      }
      break;
    case 's':
      /* Get the size of a file */
      printf("Enter full path name of file: ");
      scanf(INPUT_BUF_FORMAT,data_buffer_1);
      retval = sfs_getsize(data_buffer_1);
      if (retval >= 0) {
	printf("sfs_getsize succeeded.\n");
	printf("size = %d\n",retval);
      }
      else {
	printf("Error.  Return value was %d\n",retval);
      }
      break;
    case 't':
      /* Get the type of a file */
      printf("Enter full path name of file: ");
      scanf(INPUT_BUF_FORMAT,data_buffer_1);
      retval = sfs_gettype(data_buffer_1);
      if (retval >= 0) {
	printf("sfs_gettype succeeded.\n");
	if (retval == 0) {
	  printf("file type is REGULAR\n");
	}
	else if (retval == 1) {
	  printf("file type is DIRECTORY\n");
	}
	else {
	  printf("file has unknown type %d\n",retval);
	}
      }
      else {
	printf("Error.  Return value was %d\n",retval);
      }
      break;
    case 'i':
      /* Initialize the file system */
      printf("Enter 1 to erase disk while initializing, 0 otherwise: ");
      scanf("%d",&p1);
      retval = sfs_initialize(p1);
      if (retval > 0) {
	printf("sfs_initialize succeeded.\n");
      }
      else {
	printf("Error.  Return value was %d\n",retval);
      }
      break;
    case 'q':
      /* Quit this program */
      break;
    default:
      printf("Unknown command: %s\n",command_buffer);
      break;
    }
    if (command_buffer[0] == 'q') break;
    /* cleanup the newline that remains after reading command parameter(s) */
    gets(command_buffer);
  }
}
      
