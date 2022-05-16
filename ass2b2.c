#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<time.h>
void sfile(char const filename []);
char * formatdate(char *str,time_t val)
{
  strftime(str,36,"%d %m %Y %H:%M:%S",localtime(&val));
  return str;
}
int main()
{
  ssize_t read;
  char *buffer=0;
  size_t buf_size=0;
  printf("Enter the name of a file to check:\n");
  read=getline(&buffer,&buf_size,stdin);
  if(read<=0)
  {
      printf("getline failed \n");
      exit(1);
  }
 if(buffer[read-1]=='\n')
  {
     buffer[read-1]=0;
   }
     int s=open(buffer,O_RDONLY);
     if(s==-1)
     {
        printf("File does not exits\n");
        exit(1);
     }
    else
     {
         sfile(buffer);
     }
    free(buffer);
     return 0;
  }
void sfile(char const filename [])
 {
     struct stat sfile;
     char date[36];
     if(stat(filename,&sfile)==-1)
       {
             printf("Error Occurred\n");
       }
    printf("Access:%s\n",formatdate(date,sfile.st_atime));
    printf("Modify:%s\n",formatdate(date,sfile.st_mtime));
    printf("Change:%s\n",formatdate(date,sfile.st_ctime));
    // accessing data members of stat struct
   printf("\nFile st_ino %d\n",sfile.st_ino);
   printf("\nFile st_mode %o\n",sfile.st_mode);
   printf("\nFile st_atime %d\n",sfile.st_atime);
   printf("\nFile st_uid %d\n",sfile.st_uid);
   printf("\nFile st_blksize %d\n",sfile.st_blksize);
   printf("\nFile st_gid %d\n",sfile.st_gid);
   printf("\nFile st_blocks %ld\n",sfile.st_blocks);
   printf("\nFile st_size %ld\n",sfile.st_size);
   printf("\nFile at_nlink %u\n",sfile.st_nlink);
   printf("\nFile Permission User\n");
   printf((sfile.st_mode & S_IRUSR)?"r":"_");
   printf((sfile.st_mode & S_IWUSR)?"w":"_");
   printf((sfile.st_mode & S_IXUSR)?"x":"_");
   printf("\n");
   printf("\nFile Permission Group\n");
   printf((sfile.st_mode & S_IRGRP)?"r":"_");
   printf((sfile.st_mode & S_IWGRP)?"w":"_");
   printf((sfile.st_mode & S_IXGRP)?"x":"_");
   printf("\n");
   printf("\nFile Permission Other\n");
   printf((sfile.st_mode & S_IROTH)?"r":"_");
   printf((sfile.st_mode & S_IWOTH)?"w":"_");
   printf((sfile.st_mode & S_IXOTH)?"x":"_");
   printf("\n");
}
