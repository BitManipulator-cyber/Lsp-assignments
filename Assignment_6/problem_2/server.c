/* 
 * This is a server program which will be compiled to createa .so 
 * file which will server the client program 
 */

int add(int a, int b)
{
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}

/* 
 * Compilation steps  
 *
 *  (1) Create the object file
 *
 *	gcc -c -fPIC server.c server.o
 *
 *	- This creates a .o(object file)
 *	- c : tells the compiler to not link
 *	- fPIC : Position independant code
 *
 *  (2) Create the .so file
 *	gcc -shared -o libserver.so server.o
 *
 *	- This creates a shared object by specifying the
 *	  object file
 *	- shared : creates a shared object 
 */
