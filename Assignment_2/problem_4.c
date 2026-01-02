/**
 * Author: Aaditya Jagtap
 * Problem Statement: Print each file with it's type using lstat()
 * Input: Directory name
 * Output: Each filename + filetype
 */

/* Header files */
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>

/**
 * print_file_type - prints every file name and it's type
 *
 * @dir_name: stores directory name
 *
 * This function takes the directory name from the user and 
 * then opens the directory and traverse the whole directory.
 *
 * Then this function prints each file's name and it's type
 * on the console.
 *
 * Return:
 * void (filename + filetype on console)
 */
void print_file_type(char dir_name[])
{

	DIR           *dp = NULL;
	struct dirent *ptr = NULL;
	struct stat    s_obj;
	char   fullpath[1024];
	
	/* Open the directory */
	dp = opendir(dir_name);

	if(dp != NULL){
		printf("Directory opened successfully\n");
	}else{
		printf("ERROR INFO: %s\n", strerror(errno));
	}

	/* Traverse the directory */
	while((ptr = readdir(dp)) != NULL)
	{
		if(strcmp(".", ptr -> d_name) == 0 || strcmp("..", ptr -> d_name) == 0)
		{
			printf("Filename: %-10s\tFiletype: Directory file\n", ptr -> d_name);
			continue;
		}

		/* Build the path for lstat() to detect the filenames */
		snprintf(fullpath, sizeof(fullpath), "%s/%s", dir_name, ptr -> d_name);
		printf("Filename: %-10s\t", ptr -> d_name);
		
		/* Check and print the file type */
		if(lstat(fullpath, &s_obj) == 0)
		{
			if      (S_ISREG  (s_obj.st_mode)) printf("File type: Regular file\n");
			else if (S_ISDIR  (s_obj.st_mode)) printf("File type: Directory file\n");
			else if (S_ISLNK  (s_obj.st_mode)) printf("File type: Symlink file\n");
			else if (S_ISFIFO (s_obj.st_mode)) printf("File type: FIFO file\n");
			else if (S_ISSOCK (s_obj.st_mode)) printf("File type: SOCKET file\n");
			else if (S_ISCHR  (s_obj.st_mode)) printf("File type: Character file\n");
			else if (S_ISBLK  (s_obj.st_mode)) printf("File type: Block file\n");
			else 			           printf("File type: Unknown\n");
		}
		else
		{
			printf("lstat failed: %s\n", strerror(errno));
		}
	}

	closedir(dp);

}

/* Entry point function */
int main()
{
	char   dir_name[256];

	printf("Enter directory name:\n");
	scanf ("%s", dir_name);

	print_file_type(dir_name);

	return 0;
}
