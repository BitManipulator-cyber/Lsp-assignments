// Question 3
// Accept filename + mode(read, write, execute)
// Use access() to check permission for current process
// Print "accessible/not accessible" with reason

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

// Checks input and assigns the flag value
void check_input(const char *mode, int flag)
{
	if      (strcmp(mode, "R")  == 0) flag = O_RDONLY;
	else if (strcmp(mode, "W")  == 0) flag = O_WRONLY;
	else if (strcmp(mode, "RW") == 0) flag = O_RDWR;
	else if (strcmp(mode, "A")  == 0) flag = O_WRONLY | O_APPEND;
	else     printf("Please enter a valid character\n");

}

// Open the file and returns fd on success and -1 on failure
int open_file(const char* filename, int flag)
{
	int fd = open(filename, flag | O_CREAT, 0644);

	if(fd >= 0)
	{
		printf("File opened sucessfully\n");
		return fd;
	}
	else
	{
		printf("Error occured: %s\n", strerror(errno));
	}
}

void check_file_access(const char *filename, int flag)
{
	// Syntax of access()
	// int access(const char *path, int mode);
	int iRet = access(filename, flag);

	if(iRet == 0){
		printf("The process has access to the file: %d");
	}else{
		printf("ERROR INFO: %s", strerror(errno));
	}
}

int main()
{
	int  fd   = 0;
	int  flag = 0;
	char mode[32];
	char filename[256];

	printf("Enter filename:\n");
	scanf("%s", filename);

	printf("Enter the mode\n");
	scanf("%s", mode);
	
	check_input(mode, flag);
	fd = open_file(filename, flag);
	check_file_access(filename, flag);

	return 0;
}
