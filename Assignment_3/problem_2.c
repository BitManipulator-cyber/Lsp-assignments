// Question 2
// Check file present in Directory
// Accept directory name and filename
// Check whether that file exists in that directory
// Print absolute matched path if found

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int main()
{
	int           flag = 0;
	DIR           *dp  = NULL;
	struct dirent *ptr = NULL;
	char   filename[256];
	char   dir_name[256];
	char   absolute_path[1024];

	printf("Enter directory name:\n");
	scanf ("%255s", dir_name);

	printf("Enter filename: \n");
	scanf ("%255s", filename);

	// Open the directory
	dp = opendir(dir_name);

	if(dp != NULL)
	{
		printf("Directory opened successfully\n");	
	}
	else
	{
		printf("Error occured: %s\n", strerror(errno));
		exit(0);
	}

	while(ptr = readdir(dp))
	{
		// Skip . and ..
		if(strcmp(".", ptr -> d_name) == 0 || strcmp("..", ptr -> d_name) == 0)
		{
			continue;
		}

		// Check if the file exists in the directory
		if(strcmp(filename, ptr -> d_name) == 0)
		{
			flag = 1;
			printf("File '%s' exists inside the '%s' directory\n", filename, dir_name);
			// Change directory to input directory
			chdir(dir_name);

			getcwd(absolute_path, sizeof(absolute_path));
			// Print absolute path
			printf("Absolute path: %s\n", absolute_path);
			break;
		}
	}
	
	if(flag != 1)
	{
		printf("File '%s' does not exists in '%s' directory\n", filename, dir_name);
	}
	
	closedir(dp);

	return 0;
}
