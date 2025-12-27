// Question 4
// Accept filename and display the file metadata using stat()
// Size, inode no, permissions, hardlinks, owner uid/gid, filetype, last access/modify time

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>

// Displays the metadata about a file
void call_stat(const char *filename, struct stat *s_obj)
{
	// Syntax 
	// int stat(const char *restrict path,struct stat *restrict statbuf);
	if(stat(filename, s_obj) == 0)
	{
		printf("Size of the file:       %ld\n", s_obj -> st_size);
		printf("Inode number:           %ld\n", s_obj -> st_ino);
		printf("Permissions:            %d\n",  s_obj -> st_mode);
		printf("Hardlink count:         %ld\n", s_obj -> st_nlink);
		printf("Owner ID:               %d\n",  s_obj -> st_uid);
		printf("File type:              %d\n",  s_obj -> st_mode);
		printf("Last access time:       %ld\n", s_obj -> st_atim.tv_sec);
		printf("Last modification time: %ld\n", s_obj -> st_mtim.tv_sec);
		printf("Time of status change:  %ld\n", s_obj -> st_ctim.tv_sec);
	}
	else
	{
		printf("stat() failed: %s\n", strerror(errno));
	}

}

int main()
{

	struct stat s_obj; 		/*Define an object of the structure*/
	char   filename[256];

	printf("Enter the filename:\n");
	scanf("%s", filename);

	// Printing the required values
	call_stat(filename, &s_obj);
	
	return 0;
}
