/**
 * Author : Aaditya Jagtap
 * Problem Statement: Copy a file using pread() and pwrite() without changing the file offset
 * Input  : Source and destination filenames
 * Output : Copied file identical to source 
 */

/* Header files */
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

/**
 * copy_file_preserve_offset - copies file content from source to destination without changing the file offset(s)
 *
 * @source_fname: stores source filename
 * @dest_fname  : stores destination filename
 *
 * This function opens the source file and reads the content of file using the *pread()* system call which reads the 
 * file contens without changing the file offset
 * 
 * Then it opens the destination file in *write* and creates the file if it does'nt exists already. Then it writes the 
 * copied content of souce file into the destination file using the *pwrite()* system call without changing the file offset
 *
 * Return:
 * Copied content from the source file to destination file without changing the file offset(s)
 */
void copy_file_preserve_offset(char source_fname[], char dest_fname[])
{
	int  fd1 = 0, fd2 = 0, iRet = 0, buf_length = 0;
	char buf[1024];

	fd1 = open(source_fname, O_RDONLY);
	if(fd1 < 0) perror("Failed to open the SOURCE FILE\n");
	else	    printf("Succesfully opened SOURCE FILE\n");

	iRet = pread(fd1, buf, sizeof(buf), 0);
	if(iRet < 0) perror("Failed to read from the SOURCE FILE\n");
	else 	     printf("Succesful read from the SOURCE FILE\n");

	fd2 = open(dest_fname, O_WRONLY | O_CREAT, 0664);
	if(fd2 < 0) perror("Failed to open the DESTINATION FILE\n");
	else	    printf("Succesfully opened DESTINATION FILE\n");

	buf_length = strlen(buf);
	iRet = pwrite(fd2, buf, buf_length, 0);
	if(iRet < 0) perror("Failed to read from the DESTINATION FILE\n");
	else 	     printf("Succesful read from the DESTINATION FILE\n");

	close(fd1);
	close(fd2);
}

/* Entry point function */
int main(void)
{
	char source_fname[256];
	char dest_fname[256];

	printf("Enter source filename:\n");
	scanf("%255s", source_fname);

	printf("Enter destination filename:\n");
	scanf("%255s", dest_fname);

	copy_file_preserve_offset(source_fname, dest_fname);

	return 0;
}
