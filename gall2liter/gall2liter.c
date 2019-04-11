/*
  Gallons to liters table
*/

#include <stdio.h>
#include "gall2liter.h"

void print_line()
{
  int i;
  for(i=1 ; i<=ROWS_NUMBER*CELL_WIDTH ; i++)
    putchar('-');
  printf("-\n");
}

void print_header()
{
  int i;
  printf("\nTranslation from HALLONS to LITERS table:\n");
  print_line();
  for(i=1 ; i<=ROWS_NUMBER ; i++)
    printf("|    H          L   ");
  printf("|\n");
  print_line();
}

double gallon_to_liter(double liter)
{
  return  3.7854 * liter;
}

void print_one_cell(double gallon, double liter)
{
  printf("| %5.1f  -  %7.3f ",gallon,liter);
}

void print_one_line(double start_gallon)
{
  int i=1;
  while (i<=5) {
    print_one_cell(start_gallon,gallon_to_liter(start_gallon));
    start_gallon += LINES_NUMBER;
    i++;
  }
  printf("|\n");
}
