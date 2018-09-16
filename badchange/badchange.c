/*
BADCHANGE - C string exercise
Changing in output letter 'a'
            with bad word [FUCK]
*/

#include <stdio.h>
#include "col_printf.h"

/* bad word with red color (maybe) */

#define STR_BUF 200

#define COL_YELLOW_ON_RED COL_BG_RED COL_LYELLOW

/*getting string from stdin*/

int get_str( char formed_str[] )
{
  int i,c;
  for(i=0; i<(STR_BUF-1) && ( c=getchar() ) != EOF && c !='\n' ; i++)
  {
    formed_str[i] = c;
  }
  formed_str[i]='\0';
  if (c!=EOF)
    return i;
  else
    return -1;
}

void update_str(char new_str[],char old_str[])
{
  const char bad_word[]  = COL_YELLOW_ON_RED "[ FUCK! ]" COL_RESET;
  int i,j;

  j=0;

  for (i=0 ; old_str[i] ; i++) {
    if ( (old_str[i]=='a') || (old_str[i]=='A') ) {
      int k;
      for (k=0;bad_word[k];k++) {
        new_str[j]=bad_word[k];
        j++;
      }
    } else {
      new_str[j]=old_str[i];
      j++;
    }
  }
  new_str[j]='\0';
  return;
}

int main()
{
  char getted_str[STR_BUF];
  char updated_str[STR_BUF];
  while(get_str(getted_str) !=-1)
  {
    update_str(updated_str,getted_str);
    printf("%s\n",updated_str);
  }
  return 0;
}
