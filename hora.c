#include<stdio.h>
#include<time.h>

int main()
{
   time_t t;
   time(&t);
   
   printf("La hora es: %s", ctime(&t));
   
   printf(1);
   return 0;
}
