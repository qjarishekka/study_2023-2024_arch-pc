#include <stdio.h>
int main(void){
    // Your code here!
   float a = 12.9898;
   char con[20];
   sprintf(con, "%f", a);
   printf("Valor: %s", con);
   return 0;
}