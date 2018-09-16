/*
  col_printf.h

  Macross header file
  Colors for PRINTF
*/

#ifndef COL_PRINTF_H_SENTRY
#define COL_PRINTF_H_SENTRY

#define CSI "\033["
#define END "m"

/*
  Text colors
*/

#define COL_BLACK CSI "30" END
#define COL_RED CSI "31" END
#define COL_GREEN CSI "32" END
#define COL_YELLOW CSI "33" END
#define COL_BLUE CSI "34" END
#define COL_MAGENTA CSI "35" END
#define COL_CYAN CSI "36" END
#define COL_WHITE CSI "37" END

/*
  Text colors (light)
*/

#define COL_LBLACK CSI "1;30" END
#define COL_LRED CSI "1;31" END
#define COL_LGREEN CSI "1;32" END
#define COL_LYELLOW CSI "1;33" END
#define COL_LBLUE CSI "1;34" END
#define COL_LMAGENTA CSI "1;35" END
#define COL_LCYAN CSI "1;36" END
#define COL_LWHITE CSI "1;37" END

/*
  Background colors (light)
*/

#define COL_BG_BLACK CSI "40" END
#define COL_BG_RED CSI "41" END
#define COL_BG_GREEN CSI "42" END
#define COL_BG_YELLOW CSI "43" END
#define COL_BG_BLUE CSI "44" END
#define COL_BG_MAGENTA CSI "45" END
#define COL_BG_CYAN CSI "46" END
#define COL_BG_WHITE CSI "47" END

/*
  Reset terminal
*/

#define COL_RESET CSI "0" END

#endif
