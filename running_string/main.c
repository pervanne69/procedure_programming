#include <stdio.h>
#include <unistd.h>
 
int main()
{
   const char text[] = "Hello World";
 
   size_t i = 0, j;
 
   while (1)
   {
      for (j = i; j > 0; --j)
      {
         printf(" ");
      }
 
      printf("%.*s", 80-i-1, text);
 
      if (80 == ++i)
      {
         i = 0;
      }
 
      printf("%c", 13);
 
      usleep(100000);
   }
 
   return 0;
}