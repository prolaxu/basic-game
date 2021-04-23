#ifndef _COMMON_H_
#define _COMMON_H_
#include "sys.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifdef _WIN32
#define clear "cls"
#else
#define clear "clear"
#endif

char getche();
void gotoxy(); 
void drawbox();
int kbhit();
#endif