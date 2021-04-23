#include <termios.h>
#include <stdio.h>
 #include <string.h>
static struct termios old, new;
 
/* Initialize new terminal i/o settings */


void initTermios(int echo) 
{
  tcgetattr(0, &old); //grab old terminal i/o settings
  new = old; //make new settings same as old settings
  new.c_lflag &= ~ICANON; //disable buffered i/o
  new.c_lflag &= echo ? ECHO : ~ECHO; //set echo mode
  tcsetattr(0, TCSANOW, &new); //apply terminal io settings
}
 
/* Restore old terminal i/o settings */
void resetTermios(void) 
{
  tcsetattr(0, TCSANOW, &old);
}
 
/* Read 1 character - echo defines echo mode */
char getch_(int echo) 
{
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}
 
/* 
Read 1 character without echo 
getch() function definition.
*/
char getch(void) 
{
  return getch_(0);
}
 
/* 
Read 1 character with echo 
getche() function definition.
*/
char getche(void) 
{
  return getch_(1);
}

void gotoxy(int x,int y)    
{
    printf("%c[%d;%df",0x1B,y,x);
}
void drawbox(int x,int y,int xlen,int ylen,char xtok[],char ytok[]){
    int i,j;
    int sl= strlen(ytok)-1;
    for ( i = y; i <= ylen+y; i++)
    {
         if (i==y || i==ylen+y ){
                // printf("\n");
                gotoxy(x,i);
                for (j=x;j<=x+xlen;j++){
                    printf("%s",xtok);  
                    }
            }else{
                    gotoxy(x,i);
                    printf("%s",ytok);
                    gotoxy(x+xlen-sl,i);
                    printf("%s",ytok);

            }
    }
}