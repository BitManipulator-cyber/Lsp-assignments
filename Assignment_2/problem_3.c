// Question 3
// Accept directoy name
// Use opendir() / readdir() to print only the names of files present(skip . and ..)

#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <errno.h>
#include <stdlib.h>

int main()
{
	// Inbuild dirent structure
	// struct dirent {
	//         ino_t          d_ino;       /* Inode number */
	//         off_t          d_off;       /* Not an offset; see below */
	//         unsigned short d_reclen;    /* Length of this record */
	//         unsigned char  d_type;      /* Type of file; not supported by all filesystem types */
	//         char           d_name[256]; /* Null-terminated filename */
	//};
	
	// Documentation mentions
	// Set errno = 0 before calling readdir()
	// To distinguish between errno and NULL set it to 0 first
	
	DIR           *dp  = NULL;           /*Pointer for directory*/
	struct dirent *ptr = NULL;	     /*Pointer for dirent structure*/
	errno = 0;
	char   dir_name[256];

	printf("Enter directory name:\n");
	scanf ("%s", dir_name);

	dp = opendir(dir_name);

	if(dp == NULL){
		printf("ERROR INFO: %s\n", strerror(errno));
		exit(0);
	}

	// Syntax of readdir()
	// struct dirent *readdir (DIR *dirp);

	while(ptr = readdir(dp)){
		// Skipping the . and ..
		if(strcmp(".", ptr -> d_name) == 0 || strcmp("..", ptr -> d_name) == 0){
			continue;
		}
		printf("Filename: %s\n", ptr -> d_name);
	}
	
	closedir(dp);

	return 0;
}
