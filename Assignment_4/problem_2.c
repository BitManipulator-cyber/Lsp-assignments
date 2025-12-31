/**
 * Author: Aaditya Jagtap
 * Problem statement: Copy a file starting from a given byte offset of the source file
 * Input : source_file, destination file and offset of source file
 * Output: Partial file copied from starting from the offset
 */

/* Header files */
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

/**
 * copy_from_offset() - copies file content from source file to destination file with user specified offset
 *
 * @source_fname: stores source filename
 * @dest_fname  : stores destination filename
 * @src_offset  : stores source file offset given by user
 *
 * This function copies content of source file to the destination file but with user specified offset
 * First it opens the source file and read the source file and stores the data of the file into local
 * buffer.
 *
 * Then it opens the destination file in *write + append mode* and create the file if not exists already
 * Before writing the data directly to the file we calculate the offset by subtracting the offset with the
 * length of the buffer
 *
 * Return:
 * Copied content from source file to the destination file
 */
void copy_from_offset(char source_fname[], char dest_fname[], int src_offset)
{
	int  fd1 = 0, fd2 = 0;
	char buf[1024];
	
	fd1 = open(source_fname, O_RDONLY);
	if(fd1 < 0) perror("Failed to open the file\n");
	else 	    printf("Source file opened successfully\n");

	if(read(fd1, buf, sizeof(buf)) < 0)
	{
		perror("Failed to read from source file\n");
	}
	else
	{
		printf("Source file read succesfully\n");
	}

	fd2 = open(dest_fname, O_WRONLY | O_APPEND | O_CREAT, 0644);
	if(fd1 < 0) perror("Failed to open the file\n");
	else 	    printf("Destination file opened successfully\n");

	int buf_size = strlen(buf) - src_offset;

	if(write(fd2, buf, buf_size) < 0)
	{
		perror("Failed to write to destination file\n");
	}
	else
	{
		printf("Destination file write succesfully\n");
	}

	close(fd1);
	close(fd2);
}

/* Entry point function */
int main(void)
{
	char source_fname[256];
	char dest_fname[256];
	int  src_offset;

	printf("Enter source filename:\n");
	scanf ("%255s", source_fname);

	printf("Enter destination filename:\n");
	scanf ("%255s", dest_fname);

	printf("Enter source file offset\n");
	scanf ("%d", &src_offset);

	copy_from_offset(source_fname, dest_fname, src_offset);

	return 0;
}
