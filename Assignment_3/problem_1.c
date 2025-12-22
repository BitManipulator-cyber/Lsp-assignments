// Question 1
// Copy file contents from `SOURCE` -> 'DESTINATION`
// Accept source_file and destination_file path
// Creat destination if not exists
// Copy using buffered read() / write()
// Preserve permission (optional bonus using stat() + chmod())

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>

int main()
{
	int    fd1  = 0;		/*Source file*/
	int    fd2  = 0;		/*Destination file*/
	int    iRet = 0;
	struct stat s_obj;	        /*For getting permission bits*/
	int    permission_bits;
	char   source_file[256];
	char   dest_file[256];
	char   buffer[1024];
	
	printf("Enter source file\n");
	scanf ("%255s", source_file);
	
	printf("Enter destination file\n");
	scanf ("%255s", dest_file);

	// Open source file
	fd1 = open(source_file, O_RDONLY);

	// Read from the source file
	iRet = read(fd1, buffer, sizeof(buffer));

	if(iRet >= 0)
	{
		printf("Source file opened successfully\n");
	}
	else
	{
		printf("Error occured: %s", strerror(errno));
	}

	// Get permission bits of source file
	if(fstat(fd1, &s_obj) == 0)
	{
		permission_bits = s_obj.st_mode;
	}
	else
	{
		printf("fstat failed: %s", strerror(errno));
	}

	// Open destination file
	fd2 = open(dest_file, O_WRONLY | O_CREAT, permission_bits);

	int buf_length = strlen(buffer);
	// Write the buffer to the file
	iRet = write(fd2, buffer, buf_length);

	if(iRet >= 0)
	{
		printf("Content copied successfully to the destination file\n");
	}
	else
	{
		printf("Error occured: %s", strerror(errno));
	}
	
	close(fd1);
	close(fd2);

	return 0;
}
