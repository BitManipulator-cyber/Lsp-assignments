// Question 3
// Accept filename + mode(read, write, execute)
// Use access() to check permission for current process
// Print "accessible/not accessible" with reason

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main()
{
	int  fd   = 0;
	int  flag = 0;
	int  iRet = 0;
	char mode[32];
	char filename[256];

	memset (mode,     '\0', sizeof(mode));
	memset (filename, '\0', sizeof(filename));

	printf("Enter filename:\n");
	scanf("%s", filename);

	printf("Enter the mode\n");
	scanf("%s", mode);

	if      (strcmp(mode, "R")  == 0) flag = O_RDONLY;
	else if (strcmp(mode, "W")  == 0) flag = O_WRONLY;
	else if (strcmp(mode, "RW") == 0) flag = O_RDWR;
	else if (strcmp(mode, "A")  == 0) flag = O_WRONLY | O_APPEND;
	else     printf("Please enter a valid character\n");
	
	fd = open(filename, flag | O_CREAT, 0644);
	
	// access() syscall
	// It is used to check if the process trying to open the
	// file has access to file

	// Syntax of access()
	// int access(const char *path, int mode);
	iRet = access(filename, flag);

	// Return value
	//  0  : success
	// -1 : failure , can be displayed using errno

	if(iRet == 0){
		printf("File opened succesfully with fd: %d\n", fd);
		printf("Access to the process: %d\n", iRet);
	}else{
		printf("ERROR INFO: %s", strerror(errno));
	}
	
	return 0;
}
