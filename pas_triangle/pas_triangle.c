/*
  Pascal triangle program functions
  (c) Alexey Sorokin, 2018
*/

#include "pas_triangle.h"

/*
  translating a string from " $1 " into a integer number
*/

int str2num(char str[])
{
  int i=0;
  int num=0;
  char c;
  while ((c=str[i]) != '\0') {
    if ( c>='0' && c<='9')
    {
      num=num*10 + (c-'0');
      i++;
    }
    else
      return 0;
  }
  return num;
}


/*
  printing an empty space before numbers
*/

void print_empty_space(int n)
{
  while (n>0) {
    printf("  ");
    n--;
  }
}

/*
  print one triangle line
*/

void print_our_line(unsigned long int_arr[])
{
  int i=0;
    printf("|%3ld",int_arr[i]);
  i++;
  while (int_arr[i]>1) {
    printf(" %3ld",int_arr[i]);
    i++;
  }
  printf(" %3ld  |\n",int_arr[i]);
}

/*
  creating a new triangle line
*/

void count_next_line(unsigned long our_line[])
{
  int i=1;
  unsigned long tmp=0;
  unsigned long tmp_pr=1;
  do {
    tmp=our_line[i];
    our_line[i]=tmp_pr+tmp;
    tmp_pr=tmp;
    i++;
  } while (tmp_pr>1);
  our_line[i]=1;
  return;
}

/*
  ---  ---  ---  ***  ---  ---  ---
*/
