// Write a C program to implement the following unix/linux command ls -1>output.txt

#include<stdio.h>
#include<unistd.h>
//#include<sys/type.h>
#include<stdlib.h>
#include<sys/wait.h>
int main()
{
   int pid;                     //process id
   pid=fork();                 // create another process
   if(pid<0)
     {
          //fail
        printf("\n Fork Failed\n");
        exit(-1);
     }
  else if(pid==0)
       {
               //child
          execlp("/bin/ls","ls","-l",NULL);
              //execute ls
       }
       else
       {
                  //Parent
          wait(NULL);            // wait for child
          printf("\nchild complete \n");
          exit(0);
       }
}

