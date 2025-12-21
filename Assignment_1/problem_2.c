// Question 2
// Accept file + Mode from the user (R, W, RW, A)
// Convert mode to flags (O_RDONLY, O_WRONLY, O_RDWR, O_APPEND | O_CREAT)
// Open the file accordingly and display the fd

#include <stdio.h>
#include <fcntl.h>
#include <string.h>  // for strerror()
#include <errno.h>   // for int errno
#include <unistd.h>

int main()
{
	int  fd = 0;
	int  flag = 0;
	char mode[20];
	char filename[256];
	
	memset(mode,      '\0', sizeof(mode));
	memset(filename,  '\0', sizeof(filename));

	// Recieve FILENAME from the user
	printf("Enter the filename:\n");
	scanf("%s", filename);

	// Recieve MODE input from the user
	printf("Enter file mode:\n");
	scanf("%s", mode);

	if      (strcmp(mode, "R")  == 0) flag = O_RDONLY;
	else if (strcmp(mode, "W")  == 0) flag = O_WRONLY;
	else if (strcmp(mode, "RW") == 0) flag = O_RDWR;
	else if (strcmp(mode, "A")  == 0) flag = O_WRONLY | O_APPEND;
	else     printf("Enter a valid character\n");

	// CREATE and OPEN the file in user specified mode
	fd = open(filename, flag | O_CREAT, 0644);

	if(fd >= 0)
	{
		printf("File opened in %s Mode", mode);
		printf("File opened successfully with fd: %d\n", fd);
	}
	else
	{
		printf("ERROR INFO: %s\n", strerror(errno));
	}

	return 0;
}
