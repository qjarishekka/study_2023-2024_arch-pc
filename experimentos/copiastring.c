#include<stdio.h>
#include<string.h>

int main(){

char a[10] = "qwerty";
char b[10] = "012";
char c[10] = "qwerty";
char d[10] = "01245";
int i =0;

strcpy(a+2,b+1);

for(i=0;i<10;i++){

printf("%c\n",a[i]);

}


strncpy(c,d,2);

for(i=0;i<10;i++){

printf("%c\n",c[i]);

}



}