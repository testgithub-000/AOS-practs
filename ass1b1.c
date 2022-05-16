// Write a program to handle the two way communication between parent and child using pipe

#include<stdio.h>
#include<unistd.h>
#include<sys/file.h>
#include<dirent.h>
#include<fcntl.h>
#include<stdlib.h>
int main()
{
  int pipefds1[2];
  int pipefds2[2];
  int returnstatus1,returnstatus2;
  int pid;
  char pipe1writemessage[20]="Parent";
  char pipe2writemessage[20]="Child";
  char readmessage[20];

  returnstatus1 = pipe(pipefds1);
  if(returnstatus1 == -1)
    {
      printf("Unable to create pipe1 \n");
      return 1;
    }
    returnstatus2 = pipe(pipefds2);
     if(returnstatus2 == -1)
       {
         printf("unable to create pipe2 \n");
         return 1;
       }
  pid = fork();
   if(pid!=0)
     {
         //parent process
         close(pipefds1[0]);   //close unwanted pipe1 read side
         close(pipefds2[1]);   //close the unwanted pipe2 write side
         printf("In parent writing to pipe1 - Message is %s\n",pipe1writemessage);
         write(pipefds1[1],pipe1writemessage,sizeof(pipe1writemessage));
         read(pipefds2[0],readmessage,sizeof(readmessage));
         printf("In Child:Reading from pipe1 Message is %s\n",readmessage);
         printf("In child:Writing to pipe2 Message is %s\n",pipe2writemessage);
         write(pipefds2[1],pipe2writemessage,sizeof(pipe2writemessage));
     }
return 0;
}
