#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int width=19,height=19,gameover;
int x,y,fruitx,fruity,score,flag;
int Tailx[50],Taily[50];
int countTail=0;
void setup()
{
 gameover=0;
 x=width/2;
 y=height/2;

 label1:
 fruitx=rand()%10;
 if(fruitx==0)
 goto label1;
 label2:
 fruity=rand()%10;
 if(fruity==0)
 goto label2;
 score=0;
}
void draw()
{
   int i,j,k;
   system("cls");
   printf("\t\t ||WELCOME TO SNAKE GAME||\n");
   printf("\t\t press w to move snake up\n");
   printf("\t\t press a to move snake left\n");
   printf("\t\t press s to move snake down\n");
   printf("\t\t press d to move snake right\n");
   for(i=0;i<width;i++)
   {
    for(j=0;j<height;j++)
    {
   if(i==0||i==height-1||j==0||j==width-1)
    {
       printf(".");
    }
    else
    {
if(i==x && j==y)
 printf("0");
 else
 if(i==fruitx && j==fruity)
 printf("@");
 else
   {
     int ch=0;
     for(k=0;k<countTail;k++)
      {
if(i==Tailx[k] && j==Taily[k])
{
   printf("o");
   ch=1;
}
      }
      if(ch==0)
      printf(" ");
    }
}
       }
       printf("\n");
     }

   printf("\t\tYOUR SCORE=%d",score);
   printf("\t\t RULES\n");
   printf("\t\t the snake should not crash the wall or itself\n");
   printf("\t\t if it is crashed the game is over\n");
 }
 void input()
{

    if(kbhit())
    {
      switch(getch())
      {
case 'a':
   flag=1;
   break;
case 'd':
    flag=2;
    break;
case 'w':
   flag=3;
   break;
       case 's':
   flag=4;
   break;
       case 'x':
   gameover=1;
   break;
      }
    }
 }
 void makeLogic()
 {
 int i;
 int prevX=Tailx[0];
 int prevY=Taily[0];
 int prev2X,prev2Y;
 Tailx[0]=x;
 Taily[0]=y;

 for(i=1;i<countTail;i++)
 {
    prev2X=Tailx[i];
    prev2Y=Taily[i];
    Tailx[i]=prevX;
    Taily[i]=prevY;
    prevX=prev2X;
    prevY=prev2Y;
 }
   switch(flag)
   {
    case 1:
       y--;
       break;
    case 2:
       y++;
       break;
    case 3:
       x--;
       break;
    case 4:
       x++;
       break;
    default:
       break;
 }
 if(x<0||x>width||y<0||y>height)
    gameover=1;
 for(i=0;i<countTail;i++)
 {
   if(x==Tailx[i] && y==Taily[i])
   gameover=1;
 }
 if(x==fruitx && y==fruity)
 {
   label3:
  fruitx=rand()%10;
  if(fruitx==0)
  goto label3;
  label4:
  fruity=rand()%10;
  if(fruity==0)
  goto label4;
  score+=10;
  countTail++;
 }
 }
int main()

  {
   int m,n;
   char c;
   label5:

   setup();
   while(!gameover)
   {
    draw();
    input();
    makeLogic();
    for(m=0;m<2500;m++)
       for(n=0;n<2500;n++){
       }
   }
   for(m=0;m<2500;m++)

   {
      for(n=0;n<2500;n++){
      }
   }
  printf("\n your snake crashed the wall");
  printf("\n press y to continue again or press any other key to exit game :");
  scanf("%c",&c);
  if(c=='y'||c=='y')
    goto label5;
  return 0;
  }
