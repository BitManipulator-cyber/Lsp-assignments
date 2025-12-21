// Question 5
// Accept the filename and number of bytes N
// Read exactly N bytes using read() and print on the console
// If file contains less than N, print only available bytes

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main()
{
	int  fd     = 0;
	int  iRet   = 0;
	int  bytes;
	char filename[256];
	char buf[100];

	printf("Enter the filename: \n");
	scanf("%s", filename);

	printf("Number of bytes to read?: \n");
	scanf("%d", &bytes);
	
	// Open the file
	fd = open(filename, O_RDONLY);

	// Syntax of read()
	// ssize_t read (int fd, void buf[count], size_t count);
	iRet = read(fd, buf, bytes);

	if(iRet >= 0){
		printf("Buffer: %s\n", buf);
	}else{
		printf("ERROR INFO: %s\n", strerror(errno));
	}

	close(fd);
	
	return 0;
}
