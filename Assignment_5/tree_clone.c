/*
 * Author: Aaditya jagtap
 * Problem statement: To create a `tree` terminal command clone
 * Input : Directory name
 * Output: Tree like structure
 */

/* Header file */
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

/**
 * print_tree() - prints the folder structure in tree format
 *
 * @dir_name: stores directory name
 * @depth   : used for proper indentation
 *
 * This function recursively traverse the directory and prints the 
 * filename with a prefix *R* and *D* if a directory. If a directory is
 * encountered then it will call the function again with (+1) depth
 *
 * Example:
 * root/
 * 	a.txt
 * 	src/
 * 	  Ganesh.c
 * 	  Demo.txt
 *
 * Return:
 * void (folder structure printed in tree-like format)
 */
void print_tree(char dir_name[], int depth)
{
	DIR           *dp = NULL;
	struct dirent *ptr = NULL;
	struct stat    s_obj;
	char   fullpath[1024];
	
	dp = opendir(dir_name);
	if(dp == NULL) perror("Failed to open the directory\n");

	while(ptr = readdir(dp))
	{
		/* Skip . and .. */
		if(strcmp(".", ptr -> d_name) == 0 || strcmp("..", ptr -> d_name) == 0)
		{
			continue;
		}

		printf("%*s", depth*4, "");

		/* Building full path */
		snprintf(fullpath, sizeof(fullpath), "%s/%s", dir_name, ptr -> d_name);

		if(lstat(fullpath, &s_obj) == 0)
		{
			if(S_ISREG(s_obj.st_mode))
			{
				printf("[R] %s\n", ptr -> d_name);
			}
			if(S_ISDIR(s_obj.st_mode))
			{
				printf("[D] %s\n", ptr -> d_name);
				print_tree(fullpath, depth+1);
			}
		}
	}
	closedir(dp);
}

/* Entry point function */
int main(void)
{
	char dir_name[256];
	
	printf("Enter directory name:\n");

	/* Safe input avoid error caused by newline */
	fgets(dir_name, sizeof(dir_name), stdin);
	dir_name[strcspn(dir_name, "\n")] = 0;

	print_tree(dir_name, 0);

	return 0;
}
