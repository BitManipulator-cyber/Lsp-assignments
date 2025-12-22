// Question 3
// Accept source dir and destination dir
// Move all regular files
// Use rename() if same filesystem
// Else copy + delete
// Print count of moved files

#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
	int iRet = 0;
	int file_count = 0;
	DIR *dp = NULL;
	char source_dir[256];
	char dest_dir[256];
	char src_path[1024];
	char dest_path[1024];
	struct dirent *ptr = NULL;
	struct stat    s_obj;

	printf("Enter the source directory destination\n");
	scanf ("%255s", source_dir);

	printf("Enter the destination directory\n");
	scanf ("%255s", dest_dir);
	
	// Open the source directory
	dp = opendir(source_dir);

	if(dp != NULL)
	{
		printf("Directory opened succesfully\n");
	}
	else
	{
		printf("Error occured: %s\n", strerror(errno));
	}
	
	// Read source directory
	while(ptr = readdir(dp))
	{
		if(strcmp(".", ptr -> d_name) == 0 || strcmp("..", ptr -> d_name) == 0)
		{
			continue;
		}
			
		snprintf(src_path,  sizeof(src_path), "%s/%s", source_dir, ptr -> d_name);      /*Source path*/

		if(stat(src_path, &s_obj) == 0 && S_ISREG(s_obj.st_mode))
		{
			// If regular file
			snprintf(dest_path, sizeof(dest_path),"%s/%s", dest_dir,   ptr -> d_name);      /*Destination path*/

			file_count++;
			rename(src_path, dest_path);
		}
	}
	printf("Total number of files: %d\n", file_count);
	closedir(dp);

	return 0;	
}
