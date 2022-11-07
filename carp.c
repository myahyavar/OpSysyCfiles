#include <stdio.h>
#include <string.h>
#include <stlib.h>
int strtoint( char* charnums)
{
 int number=0;
 int index=0;
 while(charnums[index])
 {
    if(('0'<=charnums[index]) && (charnums[index]<='9'))
    {

    if(!number)
        number= ( (int) charnums[index]) - 48;
    else
    {
        number = (number *= 10) + ((int) charnums[index] - 48);
    }
    index++;
         }
         else
         {
            number=-1;
            printf("\nGecersiz islem");
            break;
         }
 }
 return number;
}
int main(int argc, char *argv[])
{
    char s[10];
    printf("carp programi");
    read(3,s+1,10);
    printf("deger = %s\n",s);
    return 0;
}
