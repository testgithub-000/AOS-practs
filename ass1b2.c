// Write a program to open a file goes to sleep for 15 seconds before terminating

#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/file.h>
int main()
{
 if(open("sample.txt",O_RDWR)<0)
    perror("Open error");
 if(unlink("sample.txt")<0)
    perror("Unlink error");
    printf("File unlinked \n");
    printf("Now file goes on sleep mode for 15 seconds.... \n");
    sleep(15);
    printf("\n\n");
    printf("Done\n");
    exit(0);
}

