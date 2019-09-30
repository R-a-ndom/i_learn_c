/*
  simple number guessing ( 1...1000 ) game
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

enum {
  max_line       = 100,
  max_secret_num = 999
};

enum {
  state_quit,
  state_fine,
  state_continue
};

enum {
  award_gold   = 10,
  award_silver = 20,
  award_bronze = 30
};

enum {
  c_very_cold = 100,
  c_cold      =  50,
  c_warm      =  25,
  c_hot       =   5
};

int get_try_line(char *try_line, int lim)
{
  char ch;
  int sym_c;
  for(sym_c = 0 ;sym_c < lim-1 && (ch = getchar()) != EOF && ch != '\n'; sym_c++)
  {
     if (ch == EOF)
       return -1;
     else
       try_line[sym_c] = ch;
  }
  try_line[sym_c] = '\0';
  return 0;
}

int str2int(const char* our_str)
{
  int our_num = 0;
  int i = 0;
  while( our_str[i] != '\0' ) {
    if (isdigit(our_str[i]))
    {
      our_num = (our_num * 10) + (our_str[i] - '0');
      i++;
    } else {
      return -1;
    }
  }
  return our_num;
}


int get_try_number()
{
  char try_line[max_line];
  int tmp;
  if (get_try_line(try_line,max_line) == -1)
  {
    printf("Input error !\n");
    return -1;
  } else {
    tmp = str2int(try_line);
    if (tmp == -1)
      return -1;
    else
      return tmp;
  }
}

int compare_nums(const int secret_num,const int try_num)
{
  if (secret_num == try_num) {
    printf("Right !!!\n");
    return state_fine;
  } else {

    int delta;

    if (secret_num > try_num)
      delta = secret_num - try_num;
    else
      delta = try_num - secret_num;

    if (delta <= c_hot)
      printf("Hot !!!\n");
    else if (delta <= c_warm)
      printf("Warm !..\n");
    else if (delta <= c_cold)
      printf("C-c-cold !\n");
    else
      printf("We-ery c-c-cold !..\n");
  }
  return state_continue;
}

int main()
{
  time_t t;
  int secret_num, try_num;
  int tries_count = 0;
  int game_state = state_continue;

  srand((unsigned) time(&t));
  printf("[ Simple number guessing game ]\n");
  printf("Guess a number 1..1000 !\n");
  secret_num = ( rand() % max_secret_num ) + 1;
  while (game_state != state_quit) {
    if (tries_count == 0)
      printf("Let's guess the number!");
    else
      printf("Your try is < %d >",tries_count);
    printf(" ! Please input your choice :>> ");
    try_num = get_try_number();
    if ((try_num == -1) || (try_num <= 0) || (try_num > 1000))
    {
      printf("Incorrect input! Please input a number 1..1000 !\n");
    } else {
      printf("Your input is: < %d > - ",try_num);
      game_state = compare_nums(secret_num,try_num);
      if (game_state == state_continue) {
        tries_count++;
      } else {
        game_state = state_quit;
      }
    }
  }
  printf("Your tries number - %d\n",tries_count);
  printf("thanks for game!\n");
  return 0;
}
