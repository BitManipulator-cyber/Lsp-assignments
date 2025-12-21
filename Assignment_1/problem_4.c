// Question 4
// Accept filename and display the file metadata using stat()
// Size, inode no, permissions, hardlinks, owner uid/gid, filetype, last access/modify time

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

int main()
{
	// Syntax 
	// int stat(const char *restrict path,struct stat *restrict statbuf);

	// INBUILD STRUCTURE
	// struct stat {
	//           dev_t      st_dev;      /* ID of device containing file */
	//           ino_t      st_ino;      /* Inode number */
	//           mode_t     st_mode;     /* File type and mode */
	//           nlink_t    st_nlink;    /* Number of hard links */
	//           uid_t      st_uid;      /* User ID of owner */
	//           gid_t      st_gid;      /* Group ID of owner */
	//           dev_t      st_rdev;     /* Device ID (if special file) */
	//           off_t      st_size;     /* Total size, in bytes */
	//           blksize_t  st_blksize;  /* Block size for filesystem I/O */
	//           blkcnt_t   st_blocks;   /* Number of 512 B blocks allocated */
	//
	//           /* Since POSIX.1-2008, this structure supports nanosecond
	//              precision for the following timestamp fields.
	//              For the details before POSIX.1-2008, see VERSIONS. */
	//
	//           struct timespec  st_atim;  /* Time of last access */
	//           struct timespec  st_mtim;  /* Time of last modification */
	//           struct timespec  st_ctim;  /* Time of last status change */
	//
	//       #define st_atime  st_atim.tv_sec  /* Backward compatibility */
	//       #define st_mtime  st_mtim.tv_sec
	//       #define st_ctime  st_ctim.tv_sec
	//       };

	
	struct stat s_obj; 		/*Define an object of the structure*/
	int    iRet = 0;
	char   filename[256];

	printf("Enter the filename:\n");
	scanf("%s", filename);

	iRet = stat(filename, &s_obj);

	// Printing the required values
	printf("Size of the file:       %ld\n", s_obj.st_size);
	printf("Inode number:           %ld\n", s_obj.st_ino);
	printf("Permissions:            %d\n",  s_obj.st_mode);
	printf("Hardlink count:         %ld\n", s_obj.st_nlink);
	printf("Owner ID:               %d\n",  s_obj.st_uid);
	printf("File type:              %d\n",  s_obj.st_mode);
	printf("Last access time:       %ld\n", s_obj.st_atim.tv_sec);
	printf("Last modification time: %ld\n", s_obj.st_mtim.tv_sec);
	printf("Time of status change:  %ld\n", s_obj.st_ctim.tv_sec);
	
	return 0;
}
