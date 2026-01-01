/** 
 * Author: Aaditya Jagtap
 * Problem statement: Create a ls(list) terminal command clone
 * Input : directory name
 * Output: same as ls 
 */

/* Header files */
#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

/**
 * get_permission() - checks the permission bits and assigns a character
 *
 * @mode_t mode   : file mode from stat.st_mode 
 * @char *perm_str: buffer to store 11-char permission string (rwxrwxrwx)
 *
 * This function check each and every permission bits obtained from the stat object
 * and assigns a unique character predefined for each bit
 *
 * Converts st_mode buts to human readable format
 * - First char: file type ('-', 'd', 'l', 'c', 'b', 'p', 's', '?')
 *
 * Example:
 * 	mode -> "-rw-r--r--"
 *
 * Return:
 * void (modifies perm_str in-place)
 */
void get_permissions(mode_t mode, char *perm_str) {
    // File type
    if (S_ISREG(mode)) perm_str[0] = '-';
    else if (S_ISDIR(mode)) perm_str[0] = 'd';
    else if (S_ISLNK(mode)) perm_str[0] = 'l';
    else if (S_ISCHR(mode)) perm_str[0] = 'c';
    else if (S_ISBLK(mode)) perm_str[0] = 'b';
    else if (S_ISFIFO(mode)) perm_str[0] = 'p';
    else if (S_ISSOCK(mode)) perm_str[0] = 's';
    else perm_str[0] = '?';
    
    // User rwx
    perm_str[1] = (mode & S_IRUSR) ? 'r' : '-';
    perm_str[2] = (mode & S_IWUSR) ? 'w' : '-';
    perm_str[3] = (mode & S_IXUSR) ? 'x' : '-';
    
    // Group rwx
    perm_str[4] = (mode & S_IRGRP) ? 'r' : '-';
    perm_str[5] = (mode & S_IWGRP) ? 'w' : '-';
    perm_str[6] = (mode & S_IXGRP) ? 'x' : '-';
    
    // Other rwx
    perm_str[7] = (mode & S_IROTH) ? 'r' : '-';
    perm_str[8] = (mode & S_IWOTH) ? 'w' : '-';
    perm_str[9] = (mode & S_IXOTH) ? 'x' : '-';
    perm_str[10] = '\0';
}

/**
 * get_file_type() - returns the file type as a descriptive string
 *
 * @struct stat *s_obj : stat structure containing file mode
 *
 * This function returns the file type using the stat object and
 * determines file type from S_IS* macros in s_obj->st_mode
 *
 * Return:
 * Static string ("Regular", "Directory", "Symlink", "FIFO", "Socket",
 * "Character", "Block", "Unknown")
 */
const char *get_file_type(struct stat *s_obj) 
{ 
    if      (S_ISREG  (s_obj->st_mode)) return "Regular";
    else if (S_ISDIR  (s_obj->st_mode)) return "Directory";
    else if (S_ISLNK  (s_obj->st_mode)) return "Symlink";
    else if (S_ISFIFO (s_obj->st_mode)) return "FIFO";
    else if (S_ISSOCK (s_obj->st_mode)) return "Socket";
    else if (S_ISCHR  (s_obj->st_mode)) return "Character";
    else if (S_ISBLK  (s_obj->st_mode)) return "Block";
    else                                return "Unknown";
}

/**
 * list_file() - list all the directory entries
 *
 * @current_dir: stores the directory name and treats it as current 
 * 		 directory
 *
 * This function lists of the directory entries of the *user specified*
 * directory. This function lists all type of *file and directories*
 *
 * It follows a specific header structure
 *
 * FILE_PERMISSIONS--+--FILE_TYPE--+--LAST MODIFICATION TYPE--+--FILE NAME
 * rw-rwx-rw-        |  Regular    |  Dec 31 21:48            |  test.c
 *
 * Return:
 * Same format as `ls` terminal command string output
 */
void list_files(char current_dir[])
{
	DIR 	      *dp = NULL;
	struct dirent *ptr = NULL;	
	struct stat s_obj;
	char   fullpath[1024];
	char   perm_str[11];
	char   time_str[26];

	dp = opendir(current_dir);
	if (dp == NULL) 
	{
		perror("opendir failed");
		return;
        }

	printf("%-11s %-12s %-20s %s\n", "Permissions", "Filetype", "Last mod time", "Filename");
	while((ptr = readdir(dp)) != NULL)
	{
		/* Skip . and .. */
		if(strcmp(".", ptr -> d_name) == 0 || strcmp("..", ptr -> d_name) == 0)
		{
			continue;
		}
		snprintf(fullpath, sizeof(fullpath), "%s/%s", current_dir, ptr -> d_name);

		if(lstat(fullpath, &s_obj) == 0)
		{
			get_permissions(s_obj.st_mode, perm_str);

			struct tm *tm_info = localtime(&s_obj.st_mtime);
    			strftime(time_str, sizeof(time_str), "%b %e %H:%M:%S %Y", tm_info);

			const char *file_type = get_file_type(&s_obj);

			printf("%-11s %-12s %-20s %s\n", perm_str, file_type, time_str, ptr->d_name);
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
	char dir_name[256];

	printf("Enter the directory name:\n");
	scanf ("%255s", dir_name);

	list_files(dir_name);

	return 0;
}
