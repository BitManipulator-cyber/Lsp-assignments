// Question 5
// Accept the directory name
// Find and print the largest filename and it's size in bytes
// Consider only the regular files

#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <stdlib.h>

int main()
{
	DIR           *dp  = NULL;
	struct dirent *ptr = NULL;
	struct stat    s_obj;
	struct stat    largest_stat;
	char   dir_name[256];
	char   fullpath[1024];

	// Track largest file
	char   largest_name[256] = "";
	int    max_length        = -1;

	printf("Enter the directory name\n");
	scanf("%s", dir_name);

	// Open the directory
	dp = opendir(dir_name);

	if(dp != NULL)
	{
		printf("Directory opened successfully\n");
	}
	else
	{
		printf("ERROR INFO: %s", strerror(errno));
		exit(0);
	}

	// Read the directory entries
	while((ptr = readdir(dp)) != NULL)
	{
		// Skip . and ..
		if(strcmp(".", ptr -> d_name) == 0 || strcmp("..", ptr -> d_name) == 0)
		{
			continue;
		}

		// Create the fullpath
		snprintf(fullpath, sizeof(fullpath), "%s/%s", dir_name, ptr -> d_name); 

		if(lstat(fullpath, &s_obj) == 0 && (S_ISREG(s_obj.st_mode)))
		{
			// Regular File only
			int current_length = strlen(ptr -> d_name);

			printf("Checking %s (length: %d)\n", ptr -> d_name, current_length);

			if(current_length > max_length)
			{
				max_length = current_length;
				strcpy(largest_name, ptr -> d_name);
				largest_stat = s_obj;
			}
		}

	}
	closedir(dp);

	if(max_length == -1)
	{
		printf("No regular files found\n");
	}
	else
	{
		printf("Largest filename: '%s'\n", largest_name);
		printf("Length: %d characters\n", max_length);
		printf("Size: %ld bytes\n", (long)largest_stat.st_size);
	}

	return 0;

}
