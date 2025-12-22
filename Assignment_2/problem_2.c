// Question 2
// Accept filename and a string from the user
// Write the string using write()
// Print number of bytes written

#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int main()
{
	int  fd = 0;
	int  iRet = 0;
	char filename[256];
	char buffer[1024];

	printf("Enter the filename:\n");
	scanf("%s", filename);

	printf("Enter the string:\n");
	scanf("%s", buffer);

	size_t str_size = strlen(buffer);
	
	// Open the file in append mode
	fd = open(filename, O_WRONLY | O_APPEND);

	if(fd >= 0) printf("File opened succesfully\n");
	else 	    printf("ERROR INFO: %s", strerror(errno));

	// write() syntax
	// ssize_t write (int fd, void buf[count], size_t count);
	
	iRet = write(fd, buffer, str_size);

	if(iRet > 0) printf("%d bytes written to the file: %s\n", iRet, filename);
	else 	     printf("ERROR INFO: %s", strerror(errno));

	close(fd);

	return 0;
}
