// Write a program which generate parent process to write unnamed pipe and will read from it

#include<stdio.h>
#include<stdlib.h>
#include<sys/file.h>
#include<string.h>
#include<dirent.h>
#include<fcntl.h>

char string[] = "Advanced Operating System";
main()
{
  char buf[1024];
  char *cp1, *cp2;
  int fds[2],i;
  cp1 = string;
  cp2 = buf;
  while(*cp1)
    *cp2++ = *cp1++;
    pipe(fds);                      // create one way communication channel i.e pipe (unnamed pipe)
    for(i=0;i<5;i++)
     {
       write(fds[1],buf,6);  /* child process writes at the output side of the pipe*/
       read(fds[0],buf,6); /*parent process reads the data written by the child process at the output side of the pipe*/
       printf("The data read by parent process is : % s\n",buf);
     }
}

