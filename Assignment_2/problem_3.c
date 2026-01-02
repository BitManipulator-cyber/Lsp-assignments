/**
 * Author: Aaditya Jagtap
 * Problem Statement: print all filenames present in user specified directory
 * Input : Directory name
 * Output: Filename(Skip . and ..)
 */

/* Header files */
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>

/**
 * print_filename - prints the files present inside a directory
 *
 * @dir_name: stores directory name
 *
 * This function opens the directory and then reads the directory
 * and prints the file names and skips . and .. entries
 * 	(.) --> current directory
 * 	(..)--> parent directory
 *
 * Return:
 * void (filenames except . and ..)
 */
void print_filename(char dir_name[])
{
	DIR *dp = NULL;
	struct dirent *ptr = NULL;
	
	/* Open the directory */
	dp = opendir(dir_name);
	if(dp == NULL)
		perror("Failed to open the directory\n");
	else
		printf("Opened directory succesfully\n");

	/* Read the directory */
	while((ptr = readdir(dp)) != NULL)
	{
		/* Skip . and .. */
		if(strcmp(".", ptr -> d_name) == 0 || strcmp("..", ptr -> d_name) == 0)
		{
			continue;
		}
		/* Print filenames */
		printf("Filename: %s\n", ptr -> d_name);
	}
	/* Close the directory */
	closedir(dp);
}

/* Entry point function */
int main()
{
	char dir_name[256];

	printf("Enter directory name:\n");
	scanf ("%s", dir_name);
	
	/* Call to function */
	print_filename(dir_name);

	return 0;
}
