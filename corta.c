#include <string.h>
#include <stdio.h>

int main () {
   
   const char s[] = " ";
   char *token;

   char str[] = "MOV a/b";
   
   /* get the first token */
   token = strtok(str, s);
   
   /* walk through other tokens */
   while( token != NULL ) {
      printf( " %s\n", token );
    
      token = strtok(NULL, s);
   }
   
   return(0);
}