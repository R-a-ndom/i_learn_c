#include <stdio.h>
#include "gall2liter.h"

int main()
{
  double start_gallon=1.0;
  print_header();
  while (start_gallon<=10.0)
  {
    print_one_line(start_gallon);
    start_gallon += 1.0;
  }
  print_line();
  return 0;
}

