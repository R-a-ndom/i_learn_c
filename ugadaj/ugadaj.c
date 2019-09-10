/*
  simple number 1...1000 game
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
  c_very_cold = 150,
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
    switch (our_str[i]) {
      case '0': case '1': case '2': case '3': case '4':
      case '5': case '6': case '7': case '8': case '9':
        our_num = (our_num * 10) + (our_str[i] - '0');
        break;
      default:
        return -1;
    }
    i++;
  }
  return our_num;
}


int compare_input(int secret_num, int try_num)
{
  if (secret_num == try_num) {
    printf("Right !!!");
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
    else if (delta <= c_very_cold)
      printf("We-ery c-c-cold !..\n");
    else {
      printf("compare_input() - WTF ?\n");
      exit(1);
    }
  }
  return state_continue;
}

int main()
{
  time_t t;
  int secret_num, try_num;

/*  int tries_count = 0;
  int game_state = state_continue; */

  char try_line[max_line];

  srand((unsigned) time(&t));

  printf("guess a number 1..1000 !\n");
  secret_num = ( rand() % max_secret_num ) + 1;
  printf("%d\n",secret_num);

  printf("Please input your choice ::>> ");
  if ( get_try_line(try_line,max_line) )
    printf("Your input is < %s >\n",try_line);
  else
    printf("< %s > - Input error !!!\n",try_line);

  if ( (try_num=str2int(try_line)) != -1 )
    printf("Your number : < %d >\n",try_num);
  else
    printf("String checking error !!!\n");

  printf("thanks for game!\n");
  return 0;
}
