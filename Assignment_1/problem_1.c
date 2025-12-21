// Question 1
// Accept filename from user and open using open()
// Print: Success message + returned file descriptor
// Handle errors using perror()

#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int main()
{
	int  fd = 0;
	char filename[256];     // 256 because max filename size = 256 bytes

	// Accepting the filename
	printf("Enter file name:\n");
	scanf("%s", filename);

	// Open the file in READ MODE
	// Also CREATE the file if it does not exists already
	fd = open(filename, O_CREAT | O_RDONLY, 0644);

	if(fd >= 0){
		printf("File opened successfully with fd: %d\n", fd);
	}else{
		perror("Error opening the file\nINFO");
	}
	return 0;
}
