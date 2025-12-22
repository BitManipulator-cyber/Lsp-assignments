// Question 4
// Delete all empty regular files
// Accept directory name
// Delete file with size = 0 bytes(regular files only)
// Print names of deleted + total delete count

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>

int main()
{
	DIR *dp = NULL;
	struct dirent *ptr;
	struct stat    s_obj;
	int  delete_count = 0;  
	char dir_name[256];
	char fullpath[1024];
	char deleted_files[256] = "";

	printf("Enter directory name\n");
	scanf ("%s", dir_name);

	// Open the directory
	dp = opendir(dir_name);
	
	printf("LIST OF DELETED FILES:\n");
	// Read the directory entries
	while(ptr = readdir(dp))
	{
		// Skip . and ..
		if(strcmp(".", ptr -> d_name) == 0 || strcmp("..", ptr -> d_name) == 0)
		{
			continue;
		}
		// Create the fullpath
		snprintf(fullpath, sizeof(fullpath), "%s/%s", dir_name, ptr -> d_name);

		if(stat(fullpath, &s_obj) == 0 && S_ISREG(s_obj.st_mode))
		{
			if(s_obj.st_size == 0)
			{
				delete_count ++;
				printf("Deleted file: %s\n", ptr -> d_name);
				unlink(fullpath);
			}
			else
			{
				continue;
			}
		}
	}
	printf("Total deleted files: %d\n", delete_count);
	closedir(dp);
}
