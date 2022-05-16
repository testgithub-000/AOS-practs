// Write a program to create a file with hole in it
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<sys/file.h>
#include<dirent.h>
int main()
{
  //create a new file named as file.txt
  int n = creat("file.txt","w+");
  char ch[16] = "hello";
  char str[20] = "od -c file.txt";
  
  //change permission of file.txt with maximum access
  system("chmod 777 file.txt");

  //write string in file.txt
  write(n,ch,5);

  // to move cursor from beginning to 30th position
  lseek(n,30,SEEK_SET);

  //write string in file.txt
  write(n,ch,16);
  
  //to prompt command in command prompt
  system(str);
  return(0);
}
