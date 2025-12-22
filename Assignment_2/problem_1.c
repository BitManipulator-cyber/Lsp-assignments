// Assingnment 2 Q1
// Accept filename and print full content on console
// Use a buffer loop (read() until 0)
// Show total bytes read

#include <stdio.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

int main()
{
	int  fd    = 0;
	int  iRet  = 0;
	char filename[256];
	char buffer[1024];

	memset(buffer, '\0', sizeof(buffer));

	printf("Enter filename:\n");
	scanf("%s", filename);

	fd = open(filename, O_RDONLY);

	// Syntax of read
	// ssize_t read (int fd, void buf[count], size_t count);
	
	iRet = read(fd, buffer, sizeof(buffer));
	
	if(iRet >= 0)
	{
		printf("Content of file: %s\n", buffer);
		printf("Byte count: %d\n", iRet);
	}
	else
	{
		printf("ERROR INFO: %s", strerror(errno));
	}

	close(fd);

	return 0;
}
