/**
 * Author: Aaditya Jagtap
 * Problem statement: Merge multiple input files into a single output file
 * Input: output_file file_1 file_2 file_3....
 * Output: Combined file content in order
 */

/* Header files */
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

/* Entry point function */
int main(int argc, char *argv[])
{
	int iRet = 0, output_fd = 0;
	char buf[2048];

	output_fd = open(argv[1], O_WRONLY | O_CREAT | O_APPEND, 0644);

	for(int i = 2; i < argc; i++)
	{
		int input_fd = 0;
		iRet = 0;

		input_fd = open(argv[i], O_RDONLY);
		if(input_fd < 0) printf("Failed to open %d file\n", i);
		else	         printf("File %d opened successfully\n", i);

		iRet = read(input_fd, buf, sizeof(buf));
		if(iRet < 0) printf("Failed to read from %d file\n", i);
		else         printf("Read succesfully from %d file\n", i);

		iRet = write(output_fd, buf, iRet); 
		if(iRet < 0) printf("Failed to write in OUTPUT FILE\n");
		else         printf("Succesfully merged file contents\n");

		close(input_fd);
	}

	close(output_fd);

	return 0;
}
