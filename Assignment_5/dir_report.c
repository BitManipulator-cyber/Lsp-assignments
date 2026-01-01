/**
 * Author: Aaditya Jagtap
 * Problem statement: To write a program that recursively calculates total number of files,
 * total number of directories, total size of directories, largest file name + size, etc
 * Input : Directory name
 * Output: Directory report
 */

/* Header files */
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

/**
 * print_directory_report - Recursively scans directory tree, accumulating statistics
 *
 * @dir_name        : Path to directory to analyze
 * @reg_count       : Pointer to count of regular files (updated)
 * @dir_count       : Pointer to count of directories (updated)  
 * @max_byte_count  : Pointer to size of largest regular file (updated)
 * @total_byte_count: Pointer to total size of all files+dirs (updated)
 * @largest_fname   : Buffer for name of largest file (updated, max 255 chars)
 *
 * Traverses entire subtree, skips . / .. / symlinks. Sums st_size for all entries.
 * Caller initializes counters to 0 / -1 and provides largest_fname buffer.
 *
 * Return:
 * void (updates counters via pointers)
 */
void print_directory_report(char dir_name[], int *reg_count, int *dir_count, int *max_byte_count, int *total_byte_count, char largest_fname[])
{
	DIR           *dp = NULL;
	struct dirent *ptr = NULL;
	struct stat    s_obj;
	char   fullpath[1024];

	dp = opendir(dir_name);
	if(dp == NULL) perror("Failed to open the directory\n");

	while((ptr = readdir(dp)) != NULL)
	{
		/* Skip . and .. */
		if(strcmp(".", ptr -> d_name) == 0 || strcmp("..", ptr -> d_name) == 0)
		{
			continue;
		}

		/* Build full path */
		snprintf(fullpath, sizeof(fullpath), "%s/%s", dir_name, ptr -> d_name);

		if(lstat(fullpath, &s_obj) == 0)
		{
			/* Increment `reg_count` by 1 and increase total bytes count */
			if(S_ISREG(s_obj.st_mode))
			{
				/* Derefer the variables */
				(*reg_count)++;
				(*total_byte_count) += s_obj.st_size;
				/* Update the max byte count and largest file name */
				if(s_obj.st_size > (*max_byte_count))
				{
					(*max_byte_count) = s_obj.st_size;
					strcpy(largest_fname, ptr -> d_name);
				}
			}
			/* Increment `dir_count` by 1 and increase total bytes count */
			else if(S_ISDIR(s_obj.st_mode))
			{
				(*dir_count)++;
				(*total_byte_count) += s_obj.st_size;
				/* Recursively traverse if a directory found */
				print_directory_report(fullpath, reg_count, dir_count, max_byte_count, 
						       total_byte_count, largest_fname);
			}
			/* Skip symlink file */
			else if(S_ISLNK(s_obj.st_mode))
			{
				continue;
			}
		}
		else
		{
			perror("lstat failed\n");
		}
	}
	closedir(dp);
}

/* Entry point function */
int main(void)
{
	char dir_name[256], largest_fname[256] = "";
	int reg_count = 0, dir_count = 0, max_byte_count = -1, total_byte_count = 0;

	printf("Enter directory name:\n");

	fgets(dir_name, sizeof(dir_name), stdin);
	dir_name[strcspn(dir_name, "\n")] = 0;

	print_directory_report(dir_name, &reg_count, &dir_count, &max_byte_count, &total_byte_count, largest_fname);

	printf("Files: %d\n", reg_count);
	printf("Dirs : %d\n", dir_count);
	printf("Total Size: %d\n", total_byte_count);
	printf("Largest file: %-2s(%d)\n", largest_fname, max_byte_count);

	return 0;
}
