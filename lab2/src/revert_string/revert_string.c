#include "revert_string.h"

void RevertString(char *str)
{
	 int i = 0;
     int end;

     while(str[i] != '\0')
     {
         i++;
     }

     end = i - 1;
     i = 0;

    char buff;

     while(i < end/2)
     {
         buff = str[i];
         str[i] = str[end - i];
         str[end - i] = buff;
         i++;
     }
}

