//2. Write a program to demonstrate the use of atexit() function.

#include<stdio.h>
#include<stdlib.h>
void functionA()
 {
   printf("This is Function A \n");
 }
void functionB()
 {
   printf("This is function B\n");
 }
int main()
 {
    if((atexit(functionA)!=0)|(atexit(functionB)!=0));
       atexit(functionA);
       atexit(functionB);
       printf("Starting main program\n");
       printf("Existing main program\n");
       return(0);
}