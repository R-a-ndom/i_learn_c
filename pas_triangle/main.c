/*
  Pascal triangle output program

  (c) Alexey Sorokin , 2018
*/

#include <stdio.h>
#include "pas_triangle.h"

#define MAX_ARR 50

int main(int argc, char **argv)
{
  unsigned long our_line[MAX_ARR];
  int num;
  int i=1;
  printf("\nPascal triangle output program:\n\n");
  if ((argc==1) || ((num = str2num(argv[1]))==0 ) || (num>MAX_ARR))
  {
    printf("--------------------------------\n\n");
    printf("Command-line parametr ERROR!\n\n");
    printf("Use this program:\n");
    printf("user@user $ pastriangle <number 1..50>\n\n");
    printf("--------------------------------\n\n");
    return 1;
  }
  our_line[0]=1;
  print_empty_space(num);
  printf("|  1  |\n");
  count_next_line(our_line);
  while (i<=num) {
    print_empty_space(num-i);
    print_our_line(our_line);
    count_next_line(our_line);
    i++;
  }
  return 0;
}
