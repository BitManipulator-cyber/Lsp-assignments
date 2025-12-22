// Question 4
// Accept directory name
// Print each entry with it's type: Regular/Directory/Link/FIFO/Socket/Char/Block
// Use lstat() for accurate type

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

int main()
{
	DIR 	      *dp  = NULL;
	struct dirent *ptr = NULL;
	struct stat    s_obj;
	char   dir_name[256];
	int    iRet = 0;
	char   fullpath[PATH_MAX];

	printf("Enter directory name:\n");
	scanf ("%s", dir_name);

	// Open the directory file
	dp = opendir(dir_name);

	if(dp != NULL){
		printf("Directory opened successfully\n");
	}else{
		printf("ERROR INFO: %s\n", strerror(errno));
	}

	while(ptr = readdir(dp)){
		// Skip . and ..
		if(strcmp(".", ptr -> d_name) == 0 || strcmp("..", ptr -> d_name) == 0)
		{
			printf("Filename: %-10s\tFiletype: Directory file\n", ptr -> d_name);
			continue;
		}

		// Build the path for lstat() to detect the filenames
		snprintf(fullpath, sizeof(fullpath), "%s/%s", dir_name, ptr -> d_name);
		printf("Filename: %-10s\t", ptr -> d_name);

	        // switch (sb.st_mode & S_IFMT) {
		   // case S_IFBLK:  printf("block device\n");            break;
		   // case S_IFCHR:  printf("character device\n");        break;
		   // case S_IFDIR:  printf("directory\n");               break;
		   // case S_IFIFO:  printf("FIFO/pipe\n");               break;
		   // case S_IFLNK:  printf("symlink\n");                 break;
		   // case S_IFREG:  printf("regular file\n");            break;
		   // case S_IFSOCK: printf("socket\n");                  break;
		   // default:       printf("unknown?\n");                break;
		   // }

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

	return 0;
}
