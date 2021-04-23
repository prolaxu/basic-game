#include "sys/sys.h"

int x=15;
int y=9;
int fx=0;
int fy=0;
int xt,yt;
int ch;
int sc_point=0;
int status=1;
int act=0;
void  drawui();
 int rd(int min_num, int max_num)
    {
        int result = 0, low_num = 0, hi_num = 0;

        if (min_num < max_num)
        {
            low_num = min_num;
            hi_num = max_num + 1; // include max_num in output
        } else {
            low_num = max_num + 1; // include max_num in output
            hi_num = min_num;
        }

        srand(time(NULL));
        result = (rand() % (hi_num - low_num)) + low_num;
        return result;
    }

void score(){
      gotoxy(35,3);
      printf("Score : %d",sc_point);
}
void pxy(int x,int y){
   // system(clear);
    gotoxy(7,7);
    printf("x: %d , y: %d",x,y);
}
void locate(){
    
    gotoxy(xt,yt);
    printf("  ");    
    gotoxy(x,y);
    printf("#");
}
void locatefood(){
    if(act==0){
        fx=rd(5,44);
        fy=rd(5,24);
    }else{
        act=0;
    }
    
    gotoxy(fx,fy);
    printf("*");
    locate();
}
void check(){
    if (fx==x && fy==y)
    {
        sc_point=sc_point+10;
        score();
        locatefood();
    }
    
}
void dbug(){
    drawbox(2,29,60,6,"-","|");
    drawbox(2,29,60,2,"-","|");
    gotoxy(30,30);
    printf("Debug:");
    gotoxy(5,32);
    printf(" x : %d  y : %d | fx : %d  | fy : %d | xt : %d | yt : %d \n |   Keybord Input: %d | Status : %d| Event Char[",x,y,fx,fy,xt,yt,ch,status);
 }
 int menu(){
     drawbox(15,7,21,10,"#","#");
     gotoxy(18,8);
     printf("Choose the option");
     gotoxy(18,9);
     printf("  1 - Resume");
     gotoxy(18,10);
     printf("  2 - New Game");
     gotoxy(18,11);
     printf("  3 - Exit");
     
     
     int c=1,rt;
      gotoxy(18,8+c);
      printf(">");
     while (1)
     {
         ch=getch();
        if(ch==119 && c>1){
            gotoxy(18,8+c);
          printf(" ");
            c=c-1;
          gotoxy(18,8+c);
          printf(">");
          

      }else if(ch==115 && c<3){
          //down
          gotoxy(18,8+c);
          printf(" ");
          c=c+1;
          gotoxy(18,8+c);
          printf(">");
          
      }else if(ch == 10){
          if (c==1)
          {
              act=1;
             drawui();
          }else if(c==2){
              sc_point=0;
              drawui();
          }else if(c==3){
              rt=0;
          }
          break;
      }
      gotoxy(18,16);
     printf("=> %d ",c);
     }
     


     
     return rt;
      }
    void drawui(){
         system(clear);
    drawbox(2,2,50,25,"#","#");
    drawbox(2,2,50,2,"#","#");
    gotoxy(x,y);
    printf("#");
    score();
    locatefood();
    }
int main(void) {
    drawui();
  while (status!=0)
  {
      xt=x;
      yt=y;
      dbug();
      ch=getche();
      
      
    if(ch==119 && y>5){
          //up
          y=y-1;
         locate();
         check();
      }else if(ch==115 && y<26){
          //down
          y=y+1;
            locate();
            check();
      }else if(ch==97 && x>3){
          //right
          x=x-1;
          locate();
          check();

      }else if(ch==100 && x<50){
          //left
         x=x+1;
          locate();
          check();

      }else if (ch==113)
      {
          status=menu();
          
      }
    
  }
  
  
}